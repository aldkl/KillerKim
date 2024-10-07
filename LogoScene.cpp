#include "stdafx.h"

void CLogoScene::Enter(CSceneWork* pSceneWork)
{
	D_MNG->CreateSound();
	//로고 배경
	m_pBg1 = new CEMPlane();
	m_pBg1->SetTexture("Data/Image/메뉴/메인/배경 상.png", GL_REPEAT, GL_NEAREST);
	m_pBg1->SetSize(1.0f);
	m_pBg1->SetPos(stEMVec3(0, 155, 0));
	m_pBg1->SetBlend(true);
	m_pBg1->SetBackFaceCulling(true);
	m_pBg1->SetBoundingBoxCalc(false);
	m_pBg1->SetFrstumCullingFlag(false);
	Commit(0, "Bg1", m_pBg1);

	m_pBg2 = new CEMPlane();
	m_pBg2->SetTexture("Data/Image/메뉴/메인/배경 하.png", GL_REPEAT, GL_NEAREST);
	m_pBg2->SetSize(1.0f);
	m_pBg2->SetPos(stEMVec3(0, 0, 0));
	m_pBg2->SetBlend(true);
	m_pBg2->SetBackFaceCulling(true);
	m_pBg2->SetBoundingBoxCalc(false);
	m_pBg2->SetFrstumCullingFlag(false);
	Commit(0, "Bg2", m_pBg2);

	m_pBg7 = new CEMPlane();
	m_pBg7->SetTexture("Data/Image/메뉴/배경 그림자.png", GL_REPEAT, GL_NEAREST);
	m_pBg7->SetSize(1.0f);
	m_pBg7->SetPos(stEMVec3(0, 0, 0));
	m_pBg7->SetBlend(true);
	m_pBg7->SetBackFaceCulling(true);
	m_pBg7->SetBoundingBoxCalc(false);
	m_pBg7->SetFrstumCullingFlag(false);
	Commit(0, "Bg7", m_pBg7);

	m_pPressAnyKey = new CEMPlane();
	m_pPressAnyKey->SetTexture("Data/Image/로고/press key.png", GL_REPEAT, GL_NEAREST);
	m_pPressAnyKey->SetSize(1.0f);
	m_pPressAnyKey->SetPos(stEMVec3(0, -270, 0));
	m_pPressAnyKey->SetBlend(true);
	m_pPressAnyKey->SetBackFaceCulling(true);
	m_pPressAnyKey->SetBoundingBoxCalc(false);
	m_pPressAnyKey->SetFrstumCullingFlag(false);
	m_pPressAnyKey->SetShow(false);
	Commit(0, "PressAnyKey", m_pPressAnyKey);

	m_pBackground = new CEMAnimation(4);
	m_pBackground->SetTexture(this, 4, "Data/Image/로고/로고1.png", "Data/Image/로고/로고2.png", "Data/Image/로고/로고3.png", "Data/Image/로고/로고2.png", GL_REPEAT, GL_NEAREST);
	m_pBackground->SetSize(0.7f);
	m_pBackground->SetTime(0.4f);
	m_pBackground->SetPos(stEMVec3(0, 0, 0));
	m_pBackground->SetBlend(true);
	m_pBackground->SetBackFaceCulling(true);
	m_pBackground->SetBoundingBoxCalc(false);
	m_pBackground->SetFrstumCullingFlag(false);
	Commit(0, "back", m_pBackground);

	//===================================================================================

	//로고 위아래 왔다갔다 하는거
	//=====================================================================================

	m_pBg11 = new CEMPlane();
	m_pBg11->SetTexture("Data/Image/메뉴/메인/배경 상.png", GL_REPEAT, GL_NEAREST);
	m_pBg11->SetSize(1.0f);
	m_pBg11->SetPos(stEMVec3(0, m_nUpY, 0));
	m_pBg11->SetBlend(true);
	m_pBg11->SetBackFaceCulling(true);
	m_pBg11->SetBoundingBoxCalc(false);
	m_pBg11->SetFrstumCullingFlag(false);
	Commit(-2, "Bg11", m_pBg11);

	m_pBg12 = new CEMPlane();
	m_pBg12->SetTexture("Data/Image/메뉴/메인/배경 하.png", GL_REPEAT, GL_NEAREST);
	m_pBg12->SetSize(1.0f);
	m_pBg12->SetPos(stEMVec3(0, m_nDownY, 0));
	m_pBg12->SetBlend(true);
	m_pBg12->SetBackFaceCulling(true);
	m_pBg12->SetBoundingBoxCalc(false);
	m_pBg12->SetFrstumCullingFlag(false);
	Commit(-2, "Bg12", m_pBg12);

	m_pBg13 = new CEMPlane();
	m_pBg13->SetTexture("Data/Image/메뉴/메인/톱니1.png", GL_REPEAT, GL_NEAREST);
	m_pBg13->SetSize(1.0f);
	m_pBg13->SetPos(stEMVec3(-630, 350, 0));
	m_pBg13->SetBlend(true);
	m_pBg13->SetBackFaceCulling(true);
	m_pBg13->SetBoundingBoxCalc(false);
	m_pBg13->SetFrstumCullingFlag(false);
	Commit(-1, "Bg13", m_pBg13);

	m_pBg14 = new CEMPlane();
	m_pBg14->SetTexture("Data/Image/메뉴/메인/톱니2.png", GL_REPEAT, GL_NEAREST);
	m_pBg14->SetSize(0.8f);
	m_pBg14->SetPos(stEMVec3(650, -300, 0));
	m_pBg14->SetBlend(true);
	m_pBg14->SetBackFaceCulling(true);
	m_pBg14->SetBoundingBoxCalc(false);
	m_pBg14->SetFrstumCullingFlag(false);
	Commit(-1, "Bg14", m_pBg14);

	m_pBg15 = new CEMPlane();
	m_pBg15->SetTexture("Data/Image/메뉴/메인/톱니3.png", GL_REPEAT, GL_NEAREST);
	m_pBg15->SetSize(0.8f);
	m_pBg15->SetPos(stEMVec3(650, 80, 0));
	m_pBg15->SetBlend(true);
	m_pBg15->SetBackFaceCulling(true);
	m_pBg15->SetBoundingBoxCalc(false);
	m_pBg15->SetFrstumCullingFlag(false);
	Commit(-1, "Bg15", m_pBg15);

	m_pBg16 = new CEMPlane();
	m_pBg16->SetTexture("Data/Image/메뉴/메인/톱니4.png", GL_REPEAT, GL_NEAREST);
	m_pBg16->SetSize(1.0f);
	m_pBg16->SetPos(stEMVec3(-620, -330, 0));
	m_pBg16->SetBlend(true);
	m_pBg16->SetBackFaceCulling(true);
	m_pBg16->SetBoundingBoxCalc(false);
	m_pBg16->SetFrstumCullingFlag(false);
	Commit(-1, "Bg16", m_pBg16);
}

void CLogoScene::Update(CSceneWork* pSceneWork, float dt)
{
	m_fSceneCntTime += dt;
	if (m_fSceneCntTime > 2.0f)
	{
		if (m_bSceneChange == false)
		{
			/*m_pBg11->SetShow(true);
			m_pBg12->SetShow(true);
			m_pBg13->SetShow(true);
			m_pBg14->SetShow(true);
			m_pBg15->SetShow(true);
			m_pBg16->SetShow(true);*/

			if (m_pBg11->GetPosVec2().m_fY < 800)
			{
				if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORUP]) && D_MNG->m_bSound)
					D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORUP], D_MNG->GetSoundVolume());
				m_pBg11->SetPos(stEMVec3(0, m_nUpY, 0));
				m_pBg12->SetPos(stEMVec3(0, m_nDownY, 0));
				m_pBg13->SetZRot(-m_fIndex);
				m_pBg14->SetZRot(-m_fIndex);
				m_pBg15->SetZRot(m_fIndex);
				m_pBg16->SetZRot(m_fIndex);
				m_nUpY += 17;
				m_nDownY -= 17;
				m_fIndex += 1;
			}
			if (m_pBg11->GetPosVec2().m_fY >= 800)
			{
				for (int i = 0; i < 256; i++)
				{
					if (D_INPUT->IsKeyUp(i))
					{
						m_bSceneChange = true;
					}
				}
			}
		}




		if (m_bSceneChange == true)
		{
			if (m_pBg11->GetPosVec2().m_fY > 163)
			{
				if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN]) && D_MNG->m_bSound)
					D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN], D_MNG->GetSoundVolume());
				m_pBg11->SetPos(stEMVec3(0, m_nUpY, 0));
				m_pBg12->SetPos(stEMVec3(0, m_nDownY, 0));
				m_pBg13->SetZRot(m_fIndex);
				m_pBg14->SetZRot(m_fIndex);
				m_pBg15->SetZRot(-m_fIndex);
				m_pBg16->SetZRot(-m_fIndex);
				m_nUpY -= 17;
				m_nDownY += 17;
				m_fIndex += 1;
			}
			else
			{
				D_SCENE->ChangeScene("menu_ext");
				m_bSceneChange = false;
			}
		}
		//--------------------------------------------------------
		// 로딩 0~100까지

		//-------------------------------------------------------
		// 스페이스 키 멘트 활성화
		if (m_bPressKeyFlag)
		{
			m_pPressAnyKey->SetShow(true);

			

			m_fAlphaTime += dt;

			if (m_fAlphaTime > 0.001f)
			{
				if (!m_bTurn)
				{
					m_fAlpha -= 2.0f*dt;

					if (m_fAlpha <= 0)
					{
						m_fAlpha = 0;
						m_bTurn = true;
					}
				}
				else
				{
					m_fAlpha += 2.0f*dt;

					if (m_fAlpha >= 1.0f)
					{
						m_fAlpha = 1.0f;
						m_bTurn = false;
					}
				}

				m_fAlphaTime = 0;
				m_pPressAnyKey->SetAlpha(m_fAlpha);
			}

		}
	}
	
	D_CAMERA->SetPos(m_stCamPos);

	CRootScene::Update(pSceneWork, dt);
}

void CLogoScene::Render(CSceneWork* pSceneWork)
{

	CRootScene::Render(pSceneWork);
}

void CLogoScene::Exit(CSceneWork* pSceneWork)
{
	Destroy();
}

void CLogoScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	stEMVec2 stDesPos(0.0f, 0.0f);

	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{


	}break;
	}
}

void CLogoScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{
		Dprintf("Left Click Btn");
	}break;

	case E_MOUSE_RIGHT:
	{

	}break;
	}
}

void CLogoScene::MouseMoveEvent(stMouseInfo stPos)
{


}

void CLogoScene::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{

}

HRESULT CLogoScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		int x = 0;
	}break;
	}

	return msg;
}