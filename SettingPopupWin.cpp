
#include "stdafx.h"


void CSettingPopupWin::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();

	//====================================================
	// Exit팝업창 윈도우
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/Imgs/SettingPopupBg.png");
	m_pBg->SetPos(stEMVec3(0, 0, 0));
	m_pBg->SetBlend(true);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "A_SettingPopupBG", m_pBg);

	//===============================================================
	// X 버튼
	m_Btns[0].pUI[0] = new CEMPlane();
	m_Btns[0].pUI[0]->SetTexture("Data/Image/Imgs/95.png");
	m_Btns[0].pUI[0]->SetPos(stEMVec3(314, 250, 0));
	m_Btns[0].pUI[0]->SetSize(0.4f);
	m_Btns[0].pUI[0]->SetBlend(true);
	m_Btns[0].pUI[0]->SetBackFaceCulling(true);
	m_Btns[0].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_SettingExitBtn", m_Btns[0].pUI[0]);

	//===============================================================
	// Sound 버튼 ON
	m_Btns[1].pUI[0] = new CEMPlane();
	m_Btns[1].pUI[0]->SetTexture("Data/Image/Imgs/99.png");
	m_Btns[1].pUI[0]->SetPos(stEMVec3(-100, 90, 0));
	m_Btns[1].pUI[0]->SetSize(1.5f);
	m_Btns[1].pUI[0]->SetBlend(true);
	m_Btns[1].pUI[0]->SetBackFaceCulling(true);
	m_Btns[1].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_SettingSound_ON", m_Btns[1].pUI[0]);

	//===============================================================
	// Sound 버튼 OFF
	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/Imgs/98.png");
	m_Btns[1].pUI[1]->SetPos(stEMVec3(-200, 90, 0));
	m_Btns[1].pUI[1]->SetSize(1.5f);
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_SettingSound_OFF", m_Btns[1].pUI[1]);

	// 라디오 버튼 설정
	m_Btns[1].SetType(E_RADIO_BTN);

	//===============================================================
	// Music 버튼 ON
	m_Btns[2].pUI[0] = new CEMPlane();
	m_Btns[2].pUI[0]->SetTexture("Data/Image/Imgs/96.png");
	m_Btns[2].pUI[0]->SetPos(stEMVec3(211, 85, 0));
	m_Btns[2].pUI[0]->SetSize(1.5f);
	m_Btns[2].pUI[0]->SetBlend(true);
	m_Btns[2].pUI[0]->SetBackFaceCulling(true);
	m_Btns[2].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_SettingMusic_ON", m_Btns[2].pUI[0]);

	//===============================================================
	// Music 버튼 OFF
	m_Btns[2].pUI[1] = new CEMPlane();
	m_Btns[2].pUI[1]->SetTexture("Data/Image/Imgs/97.png");
	m_Btns[2].pUI[1]->SetPos(stEMVec3(111, 85, 0));
	m_Btns[2].pUI[1]->SetSize(1.5f);
	m_Btns[2].pUI[1]->SetBlend(true);
	m_Btns[2].pUI[1]->SetBackFaceCulling(true);
	m_Btns[2].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_SettingMusic_OFF", m_Btns[2].pUI[1]);

	// 라디오 버튼 설정
	m_Btns[2].SetType(E_RADIO_BTN);

	//===============================================================
	// Volume Left Btn
	m_Btns[3].pUI[0] = new CEMPlane();
	m_Btns[3].pUI[0]->SetTexture("Data/Image/Imgs/36.png");
	m_Btns[3].pUI[0]->SetPos(stEMVec3(-230, -270, 0));
	m_Btns[3].pUI[0]->SetSize(1.3f);
	m_Btns[3].pUI[0]->SetBlend(true);
	m_Btns[3].pUI[0]->SetBackFaceCulling(true);
	m_Btns[3].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[3].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_Setting_Left_VolumeBtn", m_Btns[3].pUI[0]);


	//===============================================================
	// Volume Right Btn
	m_Btns[3].pUI[1] = new CEMPlane();
	m_Btns[3].pUI[1]->SetTexture("Data/Image/Imgs/35.png");
	m_Btns[3].pUI[1]->SetPos(stEMVec3(-78, -270, 0));
	m_Btns[3].pUI[1]->SetSize(1.3f);
	m_Btns[3].pUI[1]->SetBlend(true);
	m_Btns[3].pUI[1]->SetBackFaceCulling(true);
	m_Btns[3].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[3].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_Setting_Right_VolumeBtn", m_Btns[3].pUI[1]);

	//====================================================
	// Gauge Bar
	m_pEtcs[0] = new CEMPlane();
	m_pEtcs[0]->SetTexture("Data/Image/Imgs/100.png");
	m_pEtcs[0]->SetPos(stEMVec3(-220, -270, 0));
	m_pEtcs[0]->SetOffset(66.0f, 0);
	m_pEtcs[0]->SetBlend(false);
	m_pEtcs[0]->SetBackFaceCulling(true);
	m_pEtcs[0]->SetBoundingBoxCalc(false);
	m_pEtcs[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "C_SoundGaugeBar", m_pEtcs[0]);

	// 게이지바 설정
	CMenuScene_Ext* pMenuScene = (CMenuScene_Ext*)D_SCENE->GetCurScene();
	m_pEtcs[0]->SetSize(D_MNG->GetMusicVolume(), 1.0f);


	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CSettingPopupWin::OnMouseMoveEvent(stMouseInfo stPos)
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

void CSettingPopupWin::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
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
				// 세팅창 Exit
				if (m_pSelectPlane->GetName() == "D_SettingExitBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					Dprintf("D_SettingExitBtn\n");

					// SettingPoup창을 닫아준다.
					SetShow(false);

					// BaseMenuWin 충돌처리를 가능하게한다.
					CMenuScene_Ext* pMenuScene = (CMenuScene_Ext*)D_SCENE->GetCurScene();
					pMenuScene->m_BaseMenuWin.SetCollisionFlag(true);
				}

				if (m_pSelectPlane->GetName() == "D_SettingSound_ON")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					D_MNG->SetSoundVolume(0.0f);
					Dprintf("D_SettingSound_ON\n");

					m_Btns[1].SetRadioOnOff(E_OFF);
				}

				if (m_pSelectPlane->GetName() == "D_SettingSound_OFF")
				{
					D_MNG->SetSoundVolume(1.0f);
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					Dprintf("D_SettingSound_OFF\n");
					m_Btns[1].SetRadioOnOff(E_ON);
				}

				if (m_pSelectPlane->GetName() == "D_SettingMusic_ON")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					D_SOUND->Stop(D_MNG->m_BackSnd);
					Dprintf("D_SettingMusic_ON\n");
					m_Btns[2].SetRadioOnOff(E_OFF);
				}

				if (m_pSelectPlane->GetName() == "D_SettingMusic_OFF")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					D_SOUND->Play(D_MNG->m_BackSnd, D_MNG->GetMusicVolume());

					Dprintf("D_SettingMusic_OFF\n");
					m_Btns[2].SetRadioOnOff(E_ON);
				}

				if (m_pSelectPlane->GetName() == "D_Setting_Left_VolumeBtn")
				{
					Dprintf("D_Setting_Left_VolumeBtn\n");
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					float fVolume = D_MNG->GetMusicVolume();

					fVolume -= 0.1f;

					if (fVolume < 0)
						fVolume = 0;

					D_MNG->SetMusicVolume(fVolume);
					D_SOUND->SetVolume(D_MNG->m_BackSnd, fVolume);

					m_pEtcs[0]->SetSize(fVolume, 1.0f);
				}

				if (m_pSelectPlane->GetName() == "D_Setting_Right_VolumeBtn")
				{
					Dprintf("D_Setting_Right_VolumeBtn\n");
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					float fVolume = D_MNG->GetMusicVolume();

					fVolume += 0.1f;

					if (fVolume > 1.0f)
						fVolume = 1.0f;

					D_MNG->SetMusicVolume(fVolume);
					D_SOUND->SetVolume(D_MNG->m_BackSnd,fVolume);

					m_pEtcs[0]->SetSize(fVolume, 1.0f);
				}
			}
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
		}
	}

}