#include "stdafx.h"

void CGameScene_BaseUI::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();

	//====================================================
	// 배경
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/Imgs/background.png");
	m_pBg->SetPos(stEMVec3(0, 10, 0));
	m_pBg->SetBlend(false);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "A_Background", m_pBg);

	//====================================================
	// + LEFT BTN
	m_Btns[0].pUI[0] = new CEMPlane();
	m_Btns[0].pUI[0]->SetTexture("Data/Image/Imgs/28.png");
	m_Btns[0].pUI[0]->SetOrtho2D(true);
	m_Btns[0].pUI[0]->SetPos(stEMVec3(40, 40, 0));
	m_Btns[0].pUI[0]->SetBlend(true);
	m_Btns[0].pUI[0]->SetBackFaceCulling(true);
	m_Btns[0].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[0]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "D_LEVEL_PLUS_LEFT_BTN", m_Btns[0].pUI[0]);

	//====================================================
	// + BTN LEFT BG
	m_pEtcs[0] = new CEMPlane();
	m_pEtcs[0]->SetTexture("Data/Image/Imgs/101.png");
	m_pEtcs[0]->SetOrtho2D(true);
	m_pEtcs[0]->SetSize(1.0f, 0.7f);
	m_pEtcs[0]->SetPos(stEMVec3(120, 40, 0));
	m_pEtcs[0]->SetBlend(true);
	m_pEtcs[0]->SetBackFaceCulling(true);
	m_pEtcs[0]->SetBoundingBoxCalc(false);
	m_pEtcs[0]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "C_LEVEL_PLUS_LEFT_BG", m_pEtcs[0]);


	//====================================================
	// LOVE BG
	m_pEtcs[1] = new CEMPlane();
	m_pEtcs[1]->SetTexture("Data/Image/Imgs/30.png");
	m_pEtcs[1]->SetOrtho2D(true);
	m_pEtcs[1]->SetSize(1.2f, 1.2f);
	m_pEtcs[1]->SetPos(stEMVec3(136, 40, 0));
	m_pEtcs[1]->SetBlend(true);
	m_pEtcs[1]->SetBackFaceCulling(true);
	m_pEtcs[1]->SetBoundingBoxCalc(false);
	m_pEtcs[1]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "B_LOVE_BG", m_pEtcs[1]);


	//====================================================
	// + CENTER BTN 
	m_Btns[0].pUI[1] = new CEMPlane();
	m_Btns[0].pUI[1]->SetTexture("Data/Image/Imgs/28.png");
	m_Btns[0].pUI[1]->SetOrtho2D(true);
	m_Btns[0].pUI[1]->SetPos(stEMVec3(300, 40, 0));
	m_Btns[0].pUI[1]->SetBlend(true);
	m_Btns[0].pUI[1]->SetBackFaceCulling(true);
	m_Btns[0].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[1]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "D_LEVEL_PLUS_CENTER_BTN", m_Btns[0].pUI[1]);


	//====================================================
	// + CENTER BTN BG
	m_pEtcs[2] = new CEMPlane();
	m_pEtcs[2]->SetTexture("Data/Image/Imgs/47.png");
	m_pEtcs[2]->SetOrtho2D(true);
	m_pEtcs[2]->SetSize(1.7f, 0.8f);
	m_pEtcs[2]->SetPos(stEMVec3(400, 40, 0));
	m_pEtcs[2]->SetBlend(true);
	m_pEtcs[2]->SetBackFaceCulling(true);
	m_pEtcs[2]->SetBoundingBoxCalc(false);
	m_pEtcs[2]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "B_CENTER_BTN_BG", m_pEtcs[2]);

	//====================================================
	// + CENTER BTN COIN BG
	m_pEtcs[3] = new CEMPlane();
	m_pEtcs[3]->SetTexture("Data/Image/Imgs/42.png");
	m_pEtcs[3]->SetOrtho2D(true);
	m_pEtcs[3]->SetSize(1.15f, 1.15f);
	m_pEtcs[3]->SetPos(stEMVec3(470, 40, 0));
	m_pEtcs[3]->SetBlend(true);
	m_pEtcs[3]->SetBackFaceCulling(true);
	m_pEtcs[3]->SetBoundingBoxCalc(false);
	m_pEtcs[3]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "C_CENTER_BTN_COIN_BG", m_pEtcs[3]);


	//====================================================
	// + RIGHT BTN
	m_Btns[1].pUI[0] = new CEMPlane();
	m_Btns[1].pUI[0]->SetTexture("Data/Image/Imgs/28.png");
	m_Btns[1].pUI[0]->SetOrtho2D(true);
	m_Btns[1].pUI[0]->SetPos(stEMVec3(540, 40, 0));
	m_Btns[1].pUI[0]->SetBlend(true);
	m_Btns[1].pUI[0]->SetBackFaceCulling(true);
	m_Btns[1].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[0]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "D_LEVEL_PLUS_RIGHT_BTN", m_Btns[1].pUI[0]);


	//====================================================
	// + RIGHT BTN BG
	m_pEtcs[4] = new CEMPlane();
	m_pEtcs[4]->SetTexture("Data/Image/Imgs/47.png");
	m_pEtcs[4]->SetOrtho2D(true);
	m_pEtcs[4]->SetSize(1.7f, 0.8f);
	m_pEtcs[4]->SetPos(stEMVec3(640, 40, 0));
	m_pEtcs[4]->SetBlend(true);
	m_pEtcs[4]->SetBackFaceCulling(true);
	m_pEtcs[4]->SetBoundingBoxCalc(false);
	m_pEtcs[4]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "B_RIGHT_BTN_BG", m_pEtcs[4]);

	//====================================================
	// + RIGHT BTN DIAMOND BG
	m_pEtcs[5] = new CEMPlane();
	m_pEtcs[5]->SetTexture("Data/Image/Imgs/17.png");
	m_pEtcs[5]->SetOrtho2D(true);
	m_pEtcs[5]->SetSize(1.3f, 1.3f);
	m_pEtcs[5]->SetPos(stEMVec3(700, 40, 0));
	m_pEtcs[5]->SetBlend(true);
	m_pEtcs[5]->SetBackFaceCulling(true);
	m_pEtcs[5]->SetBoundingBoxCalc(false);
	m_pEtcs[5]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "B_RIGHT_BTN_DIAMOND_BG", m_pEtcs[5]);


	//====================================================
	// + GOTOMENU BTN
	m_Btns[2].pUI[0] = new CEMPlane();
	m_Btns[2].pUI[0]->SetTexture("Data/Image/Imgs/27.png");
	m_Btns[2].pUI[0]->SetOrtho2D(true);
	m_Btns[2].pUI[0]->SetPos(stEMVec3( 50, 900, 0));
	m_Btns[2].pUI[0]->SetSize(1.3f, 1.3f);
	m_Btns[2].pUI[0]->SetBlend(true);
	m_Btns[2].pUI[0]->SetBackFaceCulling(true);
	m_Btns[2].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[0]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "D_GOTOMENU_BTN", m_Btns[2].pUI[0]);

	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CGameScene_BaseUI::OnMouseMoveEvent(stMouseInfo stPos)
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
				if(m_pPrevSelectPlane)
					m_pPrevSelectPlane->SetColor(1, 1, 1, 1);
			}
		}

		if (m_pSelectPlane)
		{
			// 선택되어진놈 백업입니다.
			m_pPrevSelectPlane = m_pSelectPlane;

			// B로 시작하는 Plane만 빨간색으로 변경하게 하는 코드 입니다. 
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

void CGameScene_BaseUI::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
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
					if (m_pSelectPlane->GetName() == "D_LEVEL_PLUS_LEFT_BTN")
					{
						D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
						Dprintf("D_LEVEL_PLUS_LEFT_BTN\n");
					}

					if (m_pSelectPlane->GetName() == "D_LEVEL_PLUS_CENTER_BTN")
					{
						D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
						Dprintf("D_LEVEL_PLUS_CENTER_BTN\n");
					}

					if (m_pSelectPlane->GetName() == "D_LEVEL_PLUS_RIGHT_BTN")
					{
						D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
						Dprintf("D_LEVEL_PLUS_RIGHT_BTN\n");
					}

					if (m_pSelectPlane->GetName() == "D_GOTOMENU_BTN")
					{
						D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
						Dprintf("D_GOTOMENU_BTN\n");

						//GameScene_BaseUI 충돌처리 못하게 한다.
						SetCollisionFlag(false);

						//CGameScene* pGameScene = (CGameScene*)D_SCENE->GetCurScene();
						//pGameScene->m_GotoMenuPopup.SetShow(true);
					}
				}
			}break;

			case E_MOUSE_RIGHT:
			{

			}break;
		}
	}

}