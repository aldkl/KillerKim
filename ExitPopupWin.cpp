
#include "stdafx.h"


void CExitPopupWin::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();

	//====================================================
	// Exit팝업창 윈도우
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/Imgs/PopupBg.png");
	m_pBg->SetPos(stEMVec3(0, 0, 0));
	m_pBg->SetBlend(true);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "A_ExitPopup", m_pBg);

	//===============================================================
	// 팝업 Title
	m_pEtcs[0] = new CEMPlane();
	m_pEtcs[0]->SetTexture("Data/Image/Imgs/Exit.png");
	m_pEtcs[0]->SetPos(stEMVec3(0, 50, 0));
	m_pEtcs[0]->SetBlend(true);
	m_pEtcs[0]->SetBackFaceCulling(true);
	m_pEtcs[0]->SetBoundingBoxCalc(false);
	m_pEtcs[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "B_ExitWindowTitle", m_pEtcs[0]);

	//===============================================================
	// OK버튼 배경
	m_Btns[0].pUI[0] = new CEMPlane();
	m_Btns[0].pUI[0]->SetTexture("Data/Image/Imgs/46.png");
	m_Btns[0].pUI[0]->SetPos(stEMVec3(-120, -60, 0));
	m_Btns[0].pUI[0]->SetBlend(true);
	m_Btns[0].pUI[0]->SetBackFaceCulling(true);
	m_Btns[0].pUI[0]->SetBoundingBoxCalc(false);
	m_Btns[0].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "C_OkBtnBg", m_Btns[0].pUI[0]);

	//===============================================================
	// OK	
	m_Btns[0].pUI[1] = new CEMPlane();
	m_Btns[0].pUI[1]->SetTexture("Data/Image/Imgs/Ok.png");
	m_Btns[0].pUI[1]->SetPos(stEMVec3(-120, -62, 0));
	m_Btns[0].pUI[1]->SetSize(0.35f);
	m_Btns[0].pUI[1]->SetBlend(true);
	m_Btns[0].pUI[1]->SetBackFaceCulling(true);
	m_Btns[0].pUI[1]->SetBoundingBoxCalc(false);
	m_Btns[0].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_OkBtn", m_Btns[0].pUI[1]);

	//===============================================================
	// Cancel 버튼 배경
	m_Btns[1].pUI[0] = new CEMPlane();
	m_Btns[1].pUI[0]->SetTexture("Data/Image/Imgs/47.png");
	m_Btns[1].pUI[0]->SetPos(stEMVec3(120, -60, 0));
	m_Btns[1].pUI[0]->SetBlend(true);
	m_Btns[1].pUI[0]->SetBackFaceCulling(true);
	m_Btns[1].pUI[0]->SetBoundingBoxCalc(false);
	m_Btns[1].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "C_CanCelBg", m_Btns[1].pUI[0]);

	//===============================================================
	// Cancel
	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/Imgs/Cancel.png");
	m_Btns[1].pUI[1]->SetPos(stEMVec3(120, -62, 0));
	m_Btns[1].pUI[1]->SetSize(0.35f);
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(false);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_CancelBtn", m_Btns[1].pUI[1]);


	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CExitPopupWin::OnMouseMoveEvent(stMouseInfo stPos)
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

void CExitPopupWin::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
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
				//팝업창 OK 버튼 
				if (m_pSelectPlane->GetName() == "D_OkBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					Dprintf("D_OkBtn\n");

					D_WORLD->WindowsDestroy();
				}

				//팝업창 Cancel
				if (m_pSelectPlane->GetName() == "D_CancelBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					Dprintf("D_CancelBtn\n");

					//ExitPopupWin를 안보이게한다.
					SetShow(false);

					//BaseMenuWin 충돌처리를 가능하게한다.
					CMenuScene_Ext* pMenuScene = (CMenuScene_Ext*)D_SCENE->GetCurScene();
					pMenuScene->m_BaseMenuWin.SetCollisionFlag(true);
				}
			}
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
		}
	}

}