#include "stdafx.h"

void CBaseMenuWin::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();

	//====================================================
	// 배경
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/메인+죽음/메인.png");
	m_pBg->SetSize(1.8f);
	m_pBg->SetPos(stEMVec3(0, 0, 0));
	m_pBg->SetBlend(false);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "A_Background", m_pBg);
	
	//====================================================
	// Play 버튼

	m_Btns[0].pUI[1] = new CEMPlane();
	m_Btns[0].pUI[1]->SetTexture("Data/Image/메인+죽음/게임 시작1.png");
	m_Btns[0].pUI[1]->SetPos(stEMVec3(0, 0, 0));
	m_Btns[0].pUI[1]->SetBoundingBox_LTLB_Size(-120);
	m_Btns[0].pUI[1]->SetBoundingBox_RTRB_Size(120);
	m_Btns[0].pUI[1]->SetBoundingBox_LTRT_Size(15);
	m_Btns[0].pUI[1]->SetBoundingBox_LBRB_Size(-15);
	m_Btns[0].pUI[1]->SetBlend(true);
	m_Btns[0].pUI[1]->SetBackFaceCulling(true);
	m_Btns[0].pUI[1]->SetSize(1.8f);
	m_Btns[0].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_PlayTxt", m_Btns[0].pUI[1]);

	//====================================================
	// Exit 버튼

	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/메인+죽음/게임 종료1.png");
	m_Btns[1].pUI[1]->SetPos(stEMVec3(0, -100, 0));
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetSize(1.8f);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_ExitTxt", m_Btns[1].pUI[1]);

	//====================================================
	// Option 버튼

	m_Btns[2].pUI[1] = new CEMPlane();
	m_Btns[2].pUI[1]->SetTexture("Data/Image/메인+죽음/설정1.png");
	m_Btns[2].pUI[1]->SetPos(stEMVec3(0, -200, 0));
	m_Btns[2].pUI[1]->SetBlend(true);
	m_Btns[2].pUI[1]->SetSize(1.8f);
	m_Btns[2].pUI[1]->SetBackFaceCulling(true);
	m_Btns[2].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_OptionTxt", m_Btns[2].pUI[1]);


	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CBaseMenuWin::OnMouseMoveEvent(stMouseInfo stPos)
{
	if (GetCollisionFlag())
	{
		stEMVec2 stPosVec2 = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

		// 전부 체크
		m_pSelectPlane = m_pScene->AABBvsRay(stPos.m_nX, stPos.m_nY, m_nLayer);

		// 마우스 이동시마다 빨간색으로 변경하게 하는 코드 입니다. 
		if (m_pPrevSelectPlane != NULL && m_pSelectPlane != NULL)
		{
			if (m_pSelectPlane != m_pPrevSelectPlane)
			{
				m_pPrevSelectPlane->SetColor(1, 1, 1, 1);
			}
		}

		if (m_pSelectPlane)
		{
			// 선택되어진놈 백업입니다.
			m_pPrevSelectPlane = m_pSelectPlane;

			// D로 시작하는 Plane만 빨간색으로 변경하게 하는 코드 입니다. 
			if (m_pSelectPlane->GetName().c_str()[0] != 'D')
			{
				if (m_pPrevSelectPlane)
					m_pPrevSelectPlane->SetColor(1, 1, 1, 1);
			}
			else
			{
				m_pSelectPlane->SetColor((float)246 / 255, (float)198 / 255, (float)53 / 255, 1);
			}
		}
	}
}

void CBaseMenuWin::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	if (GetCollisionFlag())
	{
		switch (eButton)
		{
			case E_MOUSE_LEFT:
			{
				stEMVec2 stPosVec2 = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

				// 전부 체크
				m_pSelectPlane = m_pScene->AABBvsRay(stPos.m_nX, stPos.m_nY, m_nLayer);

				if (m_pSelectPlane)
				{
					if (m_pSelectPlane->GetName() == "D_PlayTxt")
					{
						D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
						Dprintf("play\n");

						D_SCENE->ChangeSceneFade("game");

					}

					if (m_pSelectPlane->GetName() == "D_ExitTxt")
					{
						D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
						Dprintf("ExitBtn\n");

						//BaseMenuWin충돌처리 못하게 한다.
						SetCollisionFlag(false);

						CMenuScene_Ext* pMenuScene = (CMenuScene_Ext*)D_SCENE->GetCurScene();
						pMenuScene->m_ExitPopupWin.SetShow(true);
					}

					if (m_pSelectPlane->GetName() == "D_OptionTxt")
					{
						D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
						Dprintf("Option\n");

						//BaseMenuWin충돌처리 못하게 한다.
						SetCollisionFlag(false);

						CMenuScene_Ext* pMenuScene = (CMenuScene_Ext*)D_SCENE->GetCurScene();
						pMenuScene->m_SettingPopupWin.SetShow(true);
					}

				}
			}break;

			case E_MOUSE_RIGHT:
			{

			}break;
		}
	}

}