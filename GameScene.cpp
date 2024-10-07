#include "stdafx.h"


void CGameScene::Enter(CSceneWork* pSceneWork)
{
	//m_BaseUI.CreatePopupWindow(D_MNG->m_ClickSnd, -1, this, true);
	//m_GotoMenuPopup.CreatePopupWindow(D_MNG->m_ClickSnd, -2, this, false);
	D_CAMERA->SetPos(640.0f, -360.0f, 620.0f);


	CreateOBJ();
	g_GMng.m_fNextStageTime = 0;
	g_GMng.m_bNextStageTime = FALSE;
	g_GMng.m_bPause = FALSE;
	g_GMng.m_bF9 = FALSE;
	g_GMng.m_bF10 = FALSE;
	g_GMng.m_bHeroFrame = FALSE;
	g_GMng.m_bHeroSide = FALSE;
	g_GMng.m_bHeroMove = FALSE;
	g_GMng.m_bShakeFlag = FALSE;
	g_GMng.m_nGauge = 100;
	g_GMng.m_nMap = 1;
	g_GMng.m_fBulletCtrlTime = 0;
	g_GMng.m_fMonsterCtrlTime = 0;
	g_GMng.m_fHeroGaugeTime = 0;
	g_GMng.m_fScoreCtrlTime = 0;
	g_GMng.m_fHeroGaugeUpTime = 0;
	g_GMng.m_bSkillOn = FALSE;
	g_GMng.m_bSkillToggle = FALSE;
	g_GMng.m_nStage = 0;
	g_GMng.m_nScroll = 0;
	g_GMng.m_nHeroHP = 5;
	g_GMng.m_fBlackTime = 0;
	g_GMng.m_bNextStage = FALSE;
	g_GMng.m_bBlack = TRUE;
	g_GMng.m_bBlack2 = TRUE;
	g_GMng.m_bHit = TRUE;
	g_GMng.m_nLiveEny = 0;
	g_GMng.m_bStartStage = TRUE;
	g_GMng.m_bHitHero = FALSE;
	g_GMng.m_nCheckHeroAlpha = 0;
	g_GMng.m_nBullet = 40;
	g_GMng.m_fShakeCtrl = 0;
	g_GMng.m_fShakeCtrl2 = 0;
	g_GMng.m_fHeroToggleTime = 0;
	g_GMng.m_nScore = 0;
	g_GMng.m_nKillScore = 0;
	g_GMng.NowScene = this;
	g_GMng.m_fMINIBOSSFireTime1 = 0;
	g_GMng.m_bMINIBOSSMoveFrame = 0;
	g_GMng.m_bmission = FALSE;
	m_fSceneCntTime = 0;
	for (int i = 0; i < 4; i++)
	{
		m_bCheckEnySpn[i] = false;
	}
	for (int i = 0; i < D_PE_MAX; i++)
	{
		g_GMng.m_PEHP[i] = 3;
	}

	for (int i = 0; i < D_SE_MAX; i++)
	{
		g_GMng.m_SEHP[i] = 4;
	}

	for (int i = 0; i < D_ME_MAX; i++)
	{
		g_GMng.m_MEHP[i] = 2;
	}
}

void CGameScene::CreateOBJ()
{
	m_pWin = new CEMWindow("Game", stEMRect(0, 0, 1280, 720), this, CEMColor(1.0f, 1.0f, 1.0f, 0.0f));
	m_pWin->AddWindow("Game1", "Data/Image/게임/일시 정지/테두리.png", stEMVec3(0.0f, 0.0f, 0.0f), CEMColor(1.0f, 1.0f, 1.0f, 1.0f));
	//게임옵션-배경소리끄기
	m_pWin->GetWindow("Game1")->AddTexture(0, "Data/Image/게임/일시 정지/일시 정지 타이틀.png", stEMVec3(615.0f, 150.0f, 0.0f));
	m_pWin->GetWindow("Game1")->AddButton(1, "Data/Image/게임/일시 정지/계속1.png",
		"Data/Image/게임/일시 정지/계속2.png",
		"Data/Image/게임/일시 정지/계속2.png",
		stEMVec3(560.0f, 250.0f, 0.0f));
	//게임옵션-배경소리켜기
	m_pWin->GetWindow("Game1")->AddButton(2, "Data/Image/게임/일시 정지/처음부터1.png",
		"Data/Image/게임/일시 정지/처음부터2.png",
		"Data/Image/게임/일시 정지/처음부터2.png",
		stEMVec3(525.0f, 350.0f, 0.0f));
	//게임옵션-효과소리끄기
	m_pWin->GetWindow("Game1")->AddButton(3, "Data/Image/게임/일시 정지/메인 메뉴1.png",
		"Data/Image/게임/일시 정지/메인 메뉴2.png",
		"Data/Image/게임/일시 정지/메인 메뉴2.png",
		stEMVec3(510.0f, 450.0f, 0.0f));
	m_pWin->GetWindow("Game1")->SetLock(E_STATIC);

	m_pWin->GetWindow("Game1")->SetVisible(false);

	Commit(m_pWin, E_STATIC);
	m_BackUpCamera = D_CAMERA->GetPosVec3();
	m_pText[0] = new CEMPlane();
	m_pText[0]->SetTexture("Data/Image/Map/스테이지 1.png", GL_REPEAT, GL_NEAREST);
	m_pText[0]->SetPos(-1000.0f, 50.0f);
	m_pText[0]->SetAlpha(0);
	m_pText[0]->SetShow(TRUE);
	m_pText[0]->SetSize(1.0f);
	m_pText[0]->SetBlend(TRUE);
	m_pText[0]->SetFrstumCullingFlag(FALSE);

	Commit(-3, "NextText1", m_pText[0]);
	m_pText[1] = new CEMPlane();
	m_pText[1]->SetTexture("Data/Image/Map/스테이지 2.png", GL_REPEAT, GL_NEAREST);
	m_pText[1]->SetPos(-1000.0f, 50.0f);
	m_pText[1]->SetShow(TRUE);
	m_pText[1]->SetAlpha(0);
	m_pText[1]->SetSize(1.0f);
	m_pText[1]->SetBlend(TRUE);
	m_pText[1]->SetFrstumCullingFlag(FALSE);

	m_pTutorial[0] = new CEMPlane();
	m_pTutorial[0]->SetTexture("Data/Image/Map/조작.png", GL_REPEAT, GL_NEAREST);
	m_pTutorial[0]->SetPos(640.0f, -360.0f);
	m_pTutorial[0]->SetShow(TRUE);
	m_pTutorial[0]->SetSize(1.0f);
	m_pTutorial[0]->SetBlend(TRUE);
	m_pTutorial[0]->SetFrstumCullingFlag(FALSE);

	Commit(8, "Tutorial1", m_pTutorial[0]);
	m_pTutorial[1] = new CEMPlane();
	m_pTutorial[1]->SetTexture("Data/Image/Map/주작.png", GL_REPEAT, GL_NEAREST);
	m_pTutorial[1]->SetPos(640.0f + 1280, -360.0f);
	m_pTutorial[1]->SetShow(FALSE);
	m_pTutorial[1]->SetSize(1.0f);
	m_pTutorial[1]->SetBlend(TRUE);
	m_pTutorial[1]->SetFrstumCullingFlag(FALSE);
	Commit(8, "Tutorial2", m_pTutorial[1]);
	m_pPauseBGB = new CEMPlane();
	m_pPauseBGB->SetSize(12.8f, 7.2f);
	m_pPauseBGB->SetPos(stEMVec3(640.0f, -360.0f, 0));
	m_pPauseBGB->SetColor(0, 0, 0, 0.7f);
	m_pPauseBGB->SetBlend(true);
	m_pPauseBGB->SetShow(false);
	m_pPauseBGB->SetBoundingBoxCalc(FALSE);
	m_pPauseBGB->SetFrstumCullingFlag(FALSE);
	Commit(-3, "back", m_pPauseBGB);
	Commit(-3, "NextText2", m_pText[1]);
	m_Bullet.CreateObj(this, "HeroBullet", 0, -1, 7);
	m_Hero.CreateObj(this);
	m_CMap.CreateObj(this);
	m_PE.CreateObj(this);
	m_SE.CreateObj(this);
	m_ME.CreateObj(this);
	m_CUI.CreateObj(this);
	m_BOSS.CreateObj(this);
	m_MiniBoss.CreateObj(this);
	m_pBlackground = new CEMPlane();
	CEMColor ColorBlackground;
	ColorBlackground.m_fR = 0.0f;
	ColorBlackground.m_fG = 0.0f;
	ColorBlackground.m_fB = 0.0f;
	ColorBlackground.m_fA = 1.0f;

	m_pBlackground->SetColor(ColorBlackground);
	m_pBlackground->SetPos(D_CAMERA->GetPosVec2());
	//m_pBlackground->SetPos(-5000,500);
	m_pBlackground->SetSize(12.8f, 7.2f);
	m_pBlackground->SetBlend(true);
	m_pBlackground->SetBoundingBoxCalc(FALSE);
	m_pBlackground->SetFrstumCullingFlag(FALSE);
	Commit(-2, "black", m_pBlackground);

	//===========================================================================================

	//결과 처음에 왼쪽 오른쪽 왔다갔다 하는거
	//============================================================================================
	m_nLeftX = -0;
	m_nRightX = 0;
	m_nUpY = 0;
	m_nDownY = -0;
	g_GMng.m_bStart = TRUE;
	g_GMng.m_bUP = TRUE;
	g_GMng.m_bUP2 = FALSE;
	g_GMng.m_bDOWN = FALSE;
	m_pBg11 = new CEMPlane();
	m_pBg11->SetTexture("Data/Image/메뉴/결과창/배경 좌.png", GL_REPEAT, GL_NEAREST);
	m_pBg11->SetSize(1.0f);
	m_pBg11->SetPos(stEMVec3(-500, 0 + 360.0f, 0));
	m_pBg11->SetBlend(true);
	m_pBg11->SetShow(TRUE);
	m_pBg11->SetOrtho2D(true);
	m_pBg11->SetBackFaceCulling(true);
	m_pBg11->SetBoundingBoxCalc(false);
	m_pBg11->SetFrstumCullingFlag(false);
	Commit(-5, "Bg11", m_pBg11);

	m_pBg12 = new CEMPlane();
	m_pBg12->SetTexture("Data/Image/메뉴/결과창/배경 우.png", GL_REPEAT, GL_NEAREST);
	m_pBg12->SetSize(1.0f);
	m_pBg12->SetPos(stEMVec3(1800, 0 + 360.0f, 0));
	m_pBg12->SetBlend(true);
	m_pBg12->SetOrtho2D(true);
	m_pBg12->SetShow(TRUE);
	m_pBg12->SetBackFaceCulling(true);
	m_pBg12->SetBoundingBoxCalc(false);
	m_pBg12->SetFrstumCullingFlag(false);
	Commit(-5, "Bg12", m_pBg12);

	//==================================================================================================

	//결과 마지막에 위아래 왔다갔다 하는거
	//==================================================================================================
	m_pBg13 = new CEMPlane();
	m_pBg13->SetTexture("Data/Image/메뉴/메인/배경 상.png", GL_REPEAT, GL_NEAREST);
	m_pBg13->SetSize(1.0f);
	m_pBg13->SetPos(stEMVec3(0 + 640.0f, 200, 0));
	m_pBg13->SetBlend(true);
	m_pBg13->SetShow(TRUE);
	m_pBg13->SetOrtho2D(true);
	m_pBg13->SetBackFaceCulling(true);
	m_pBg13->SetBoundingBoxCalc(false);
	m_pBg13->SetFrstumCullingFlag(false);
	Commit(-5, "Bg13", m_pBg13);

	m_pBg14 = new CEMPlane();
	m_pBg14->SetTexture("Data/Image/메뉴/메인/배경 하.png", GL_REPEAT, GL_NEAREST);
	m_pBg14->SetSize(1.0f);
	m_pBg14->SetPos(stEMVec3(0 + 640.0f, 355.0f, 0));
	m_pBg14->SetBlend(true);
	m_pBg14->SetShow(TRUE);
	m_pBg14->SetOrtho2D(true);
	m_pBg14->SetBackFaceCulling(true);
	m_pBg14->SetBoundingBoxCalc(false);
	m_pBg14->SetFrstumCullingFlag(false);
	Commit(-5, "Bg14", m_pBg14);
}
void CGameScene::Start()
{
	if (!g_GMng.m_bDOWN)
	{
		g_GMng.m_bDOWN = TRUE;
	}
	if (g_GMng.m_bDOWN)
	{
		m_fSceneCntTime += D_WORLD->GetDeltaTime();
		if (m_fSceneCntTime > 1.0f)
		{
			if (g_GMng.m_bStart)
			{
				if (g_GMng.m_bUP && !g_GMng.m_bUP2)
				{
					if (m_pBg13->GetPosVec2().m_fY > -163)
					{
						if ( !D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORUP]) && D_MNG->m_bSound)
							D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORUP], D_MNG->GetSoundVolume());
						m_pBg13->MoveY(-17);
						m_pBg14->MoveY(17);
						if (m_pBg11->GetShow() && m_pBg12->GetShow())
						{
							m_pBg11->SetShow(FALSE);
							m_pBg12->SetShow(FALSE);
						}
					}
					else
					{
						g_GMng.m_bUP = FALSE;
						g_GMng.m_bStart = FALSE;
						m_pBg13->SetShow(FALSE);
						m_pBg14->SetShow(FALSE);
						for (int i = 0; i < E_SND_MAX; i++)
						{
							D_SOUND->Stop(D_MNG->m_BackSnd[i]);
						}
					}
				}
				else if (!g_GMng.m_bUP2 && !g_GMng.m_bUP)
				{
					if (m_pBg13->GetPosVec2().m_fY < 200)
					{
						if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN]) && D_MNG->m_bSound)
							D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN], D_MNG->GetSoundVolume());
						m_pBg13->MoveY(17);
						m_pBg14->MoveY(-17);
						if (!m_pBg13->GetShow() && !m_pBg14->GetShow())
						{
							m_pBg13->SetShow(TRUE);
							m_pBg14->SetShow(TRUE);
						}

					}
					else
					{
						g_GMng.m_bUP = TRUE;
						D_SCENE->ChangeScene("game");
					}
				}
				if (g_GMng.m_bUP2 && !g_GMng.m_bUP)
				{
					if (m_pBg11->GetPosVec2().m_fX < 350)
					{
						if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN]) && D_MNG->m_bSound)
							D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN], D_MNG->GetSoundVolume());
						m_pBg11->MoveX(17);
						m_pBg12->MoveX(-17);
						if (!m_pBg11->GetShow() && !m_pBg12->GetShow())
						{
							m_pBg11->SetShow(TRUE);
							m_pBg12->SetShow(TRUE);
						}
						if (m_pBg13->GetShow() && m_pBg14->GetShow())
						{
							m_pBg13->SetShow(FALSE);
							m_pBg14->SetShow(FALSE);
						}
					}
					else
					{
						g_GMng.m_bUP2 = FALSE;
						g_GMng.m_bStart = FALSE;
						D_SCENE->ChangeScene("result");
					}
				}
			}
		}
	}
}
void CGameScene::Update(CSceneWork* pSceneWork, float dt)
{

	Start();
	if (!g_GMng.m_bStart)
	{
		if (D_INPUT->IsKeyUp(VK_ESCAPE))
		{
			m_pPauseBGB->SetPos(stEMVec2(D_CAMERA->GetPosVec3().m_fX, D_CAMERA->GetPosVec3().m_fY));
			if (!g_GMng.m_bPause)
			{
				g_GMng.m_bPause = TRUE;
				m_pWin->GetWindow("Game1")->SetVisible(true);
				m_pPauseBGB->SetShow(true);
				D_WORLD->SetTimeScale(0);
			}
			else
			{
				g_GMng.m_bPause = FALSE;
				m_pWin->GetWindow("Game1")->SetVisible(FALSE);
				m_pPauseBGB->SetShow(false);
				D_WORLD->SetTimeScale(1);
			}
		}
		if (D_INPUT->IsKeyUp(VK_F1))
		{
			D_SCENE->ChangeSceneFade("logo");
		}
		if (D_INPUT->IsKeyUp(VK_F2))
		{
			D_SCENE->ChangeSceneFade("menu");
		}

		if (!g_GMng.m_bPause && !m_bChangeStage)
		{
			m_Hero.Update(dt);
			m_Bullet.Update(dt, 3);
			m_PE.Update(m_CMap.m_ClippingHero[g_GMng.m_nStage], &m_Hero);
			m_ME.Update(m_CMap.m_ClippingHero[g_GMng.m_nStage], &m_Hero);
			m_SE.Update(m_CMap.m_ClippingHero[g_GMng.m_nStage], &m_Hero);
			m_BOSS.Update(m_CMap.m_ClippingHero[g_GMng.m_nStage], &m_Hero);
			m_MiniBoss.Update(m_CMap.m_ClippingHero[g_GMng.m_nStage], &m_Hero);

			m_Bullet.MouseMoveEvent(D_INPUT->GetMouseMovePos(), &m_Hero);
			DestDirAngleCalc(D_INPUT->GetMouseMovePos());
			CreateBullet(dt);
			CreateFallMonster(g_GMng.m_nStage);
			GameInfo();

			Scroll();
			//CameraShake();
		}
		ChangeStage();
		if (D_INPUT->IsKeyDown(VK_L))
		{
			D_CAMERA->MoveX(5.0f);
		}
		if (D_INPUT->IsKeyDown(VK_J))
		{
			D_CAMERA->MoveX(-5.0f);
		}
		if (D_INPUT->IsKeyDown(VK_I))
		{
			D_CAMERA->MoveY(5.0f);
		}
		if (D_INPUT->IsKeyDown(VK_K))
		{
			D_CAMERA->MoveY(-5.0f);
		}
		if (D_INPUT->IsKeyDown(VK_U))
		{
			D_CAMERA->MoveZ(5.0f);
		}
		if (D_INPUT->IsKeyDown(VK_O))
		{
			D_CAMERA->MoveZ(-5.0f);
		}
		if (D_INPUT->IsKeyUp(VK_F8))
		{
			Dprintf("에너지가 안달게됩니다.");
			if (g_GMng.m_bF8)
			{
				g_GMng.m_bF8 = FALSE;
			}
			else
			{
				g_GMng.m_bF8 = TRUE;
			}
		}
		if (D_INPUT->IsKeyUp(VK_F9))
		{
			Dprintf("무적이 됩니다 끄고킬수 있습니다.");
			if (g_GMng.m_bF9)
			{
				g_GMng.m_bF9 = FALSE;
			}
			else
			{
				g_GMng.m_bF9 = TRUE;
			}
		}
		if (D_INPUT->IsKeyUp(VK_F4))
		{

			if (g_GMng.m_bF10)
			{
				g_GMng.m_bF10 = FALSE;
			}
			else
			{
				g_GMng.m_bF10 = TRUE;
				Dprintf("총알이 무한이 됩니다 끄고킬수 있습니다.");
			}
		}
		if (D_INPUT->IsKeyUp(VK_F6))
		{

			if (g_GMng.m_bF5)
			{
				g_GMng.m_bF5 = FALSE;
			}
			else
			{
				g_GMng.m_bF5 = TRUE;
				Dprintf("적체력이 1이됩니다, 보스까지도.");
			}
		}
	}
	m_CUI.Update(dt);
	Die();
	CRootScene::Update(pSceneWork, dt);
}
void CGameScene::Scroll()
{
	if (g_GMng.m_bScroll)
	{

		float stCalsPos = D_CAMERA->GetPosVec3().m_fX;
		stCalsPos = CEMMath::Lerp(stCalsPos, g_GMng.m_fedX, D_WORLD->GetDeltaTime() * 5.0f);
		D_CAMERA->SetPosX(stCalsPos);
		g_GMng.m_nScroll += stCalsPos / (g_GMng.m_nStage * 1280);
		if (640.0f + 1280.0f * g_GMng.m_nStage == D_CAMERA->GetPosVec3().m_fX)
		{
			g_GMng.m_bScroll = FALSE;

		}
	}
}

void CGameScene::Render(CSceneWork* pSceneWork)
{
	CRootScene::Render(pSceneWork);
}

void CGameScene::Exit(CSceneWork* pSceneWork)
{
	m_Hero.Disable();
	for (int i = 0; i < D_PE_MAX; i++)
	{
		m_PE.Disable(i);
	}

	for (int i = 0; i < D_SE_MAX; i++)
	{
		m_SE.Disable(i);
	}

	for (int i = 0; i < D_ME_MAX; i++)
	{
		m_ME.Disable(i);
	}
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_Bullet.Disable(i);
	}
	m_stDestPos = NULL;
	m_stClickDestPos = NULL;
	m_stHeroPosToDestPosDir = NULL;
	m_stHeroRightVec3 = NULL;
	m_BackUpCamera = NULL;
	Destroy();
}

void CGameScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	int x = 0;
	stEMVec2 stDesPos(0.0f, 0.0f);
	stEMVec3 stTemp = NULL;
	switch (eButton)
	{
	case E_MOUSE_LEFT:

		//stDesPos = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

		//m_stClickDestPos = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);

		//stTemp = m_stClickDestPos - m_Hero.m_pAnimation->GetPosVec3();
		//stTemp.Normalize();

		////단위벡터 만드후 길이를 늘려줍니다^^
		//stTemp = stTemp * 270.0f;
		//m_stClickDestPos = stTemp;
		//x = 0;

		break;
	case E_MOUSE_RIGHT:
		x = 5;
		break;
	}
}
void CGameScene::CameraShake()
{
	stEMVec3 stCPos = D_CAMERA->GetPosVec3();



	if (g_GMng.m_bShakeFlag)
	{
		g_GMng.m_fShakeCtrl += D_WORLD->GetDeltaTime();
		g_GMng.m_fShakeCtrl2 += D_WORLD->GetDeltaTime();

		if (g_GMng.m_fShakeCtrl > 0.01f)
		{
			g_GMng.m_fShakeCtrl = 0;

			m_stDestPos.m_fX = stCPos.m_fX + CEMMath::RandomFloatInRange(-10, 10);
			m_stDestPos.m_fY = stCPos.m_fY + CEMMath::RandomFloatInRange(-10, 10);
			m_stDestPos.m_fZ = stCPos.m_fZ;

		}
		if (g_GMng.m_fShakeCtrl2 > 0.1f)
		{
			g_GMng.m_fShakeCtrl = 0;
			g_GMng.m_fShakeCtrl2 = 0;
			g_GMng.m_bShakeFlag = FALSE;
			m_stDestPos = m_BackUpCamera;
		}
		stCPos = CEMMath::Lerp(stCPos, m_stDestPos, 30.0f * D_WORLD->GetDeltaTime());
		D_CAMERA->SetPos(stEMVec3(stCPos.m_fX,stCPos.m_fY,620.0f));
	}

}
void CGameScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	//m_BaseUI.OnMouseUpEvent(stPos, eButton);
	//m_GotoMenuPopup.OnMouseUpEvent(stPos, eButton);
	m_Bullet.MouseUpEvent(stPos, eButton, m_Hero);
}

void CGameScene::MouseMoveEvent(stMouseInfo stPos)
{
	//m_BaseUI.OnMouseMoveEvent(stPos);
	//m_GotoMenuPopup.OnMouseMoveEvent(stPos);


}
void CGameScene::DestDirAngleCalc(stMouseInfo stPos)
{
	stEMVec2 stDesPos(0.0f, 0.0f);
	stDesPos = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

	m_stDestPos = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);

	m_stHeroPosToDestPosDir = m_stDestPos - m_Hero.m_pAnimation->GetPosVec3();

	// 단위벡터로 변경
	m_stHeroPosToDestPosDir.Normalize();
	m_stHeroDirVec3.Normalize();

	// 내적 계산
	m_fDot = stEMVec3::Dot(m_stHeroDirVec3, m_stHeroPosToDestPosDir);

	// 각도 구하기^^
	m_fRadian = (float)acos(m_fDot);

	// 주인공의 업벡터 구하기
	m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));

	if (stEMVec3::Dot(m_stHeroRightVec3, m_stHeroPosToDestPosDir) > 0.0f)
	{
		m_Hero.m_pArm->SetZRot(CEMMath::ToDegrees(m_fRadian) + 90);
		m_Hero.m_pArm->SetMirrorType(E_UP_LEFT_MIRROR);
		//Dprintf("왼쪽 %f\n", m_fRadian);
	}
	else
	{
		m_Hero.m_pArm->SetZRot(CEMMath::ToDegrees(-m_fRadian) + 90);
		m_Hero.m_pArm->SetMirrorType(E_LEFT_MIRROR);
		//Dprintf("오른쪽 %f\n", m_fRadian);
	}
	if (stDesPos.m_fX < m_Hero.m_pAnimation->GetPosVec2().m_fX)
	{
		//if (m_Hero.m_pAnimation->GetCurFrameNumber() <= 5)
		//{
			//m_Hero.m_pAnimation->SetPause(TRUE);

		g_GMng.m_bHeroSide = TRUE;
		//}
	}
	else
	{
		//if (m_Hero.m_pAnimation->GetCurFrameNumber() >= 6)
		//{
			//m_Hero.m_pAnimation->SetPause(TRUE);
		g_GMng.m_bHeroSide = FALSE;
		//}
	}
	m_Hero.m_Fire->SetPos(m_Hero.m_pArm->GetPosVec3() + m_stHeroPosToDestPosDir * 50);
}

HRESULT CGameScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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


void CGameScene::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{
	int nX = 0;

	CEMWindow* pWin = NULL;
	pWin = GetUI("Game");

	if (sWindowName == "Game1")
	{
		switch (eType)
		{
		case E_BUTTON:
		{
			switch (id)
			{
			case 1:
			{
				Dprintf("계속 \n");
				g_GMng.m_bPause = FALSE;
				m_pWin->GetWindow("Game1")->SetVisible(FALSE);
				m_pPauseBGB->SetShow(false);
				D_WORLD->SetTimeScale(1);
			}break;
			case 2:
			{
				Dprintf("처음부터 \n");
				m_pWin->GetWindow("Game1")->SetVisible(FALSE);
				g_GMng.m_bPause = FALSE;
				g_GMng.m_bStart = TRUE;
				D_WORLD->SetTimeScale(1);
			}break;

			case 3:
			{
				Dprintf("메인 메뉴 \n");
				D_SCENE->ChangeSceneFade("menu_ext");
				D_WORLD->SetTimeScale(1);
			}break;
			}break;

		case E_CHECK_BOX:
		{

		}break;

		case E_RADIO_BUTTON:
		{

		}break;
		}
		}
	}
}

void CGameScene::CreateBullet(float dt)
{
	if (g_GMng.m_nBullet > 0)
	{
		if (!g_GMng.m_bSkillOn)
		{

			g_GMng.m_fBulletCtrlTime += dt;
			if (D_INPUT->IsKeyDown(VK_LBUTTON))
			{

				if (g_GMng.m_fBulletCtrlTime >= 0.5f)
				{
					//Dprintf("왼쪽 눌림   ");
					g_GMng.m_fBulletCtrlTime = 0;
					for (int i = 0; i < D_BULLET_MAX; i++)
					{
						if (!m_Bullet.m_pAnimation[i]->GetShow())
						{
							m_Bullet.Enable(i, m_Hero.m_Fire->GetPosVec3(), D_INPUT->GetMouseMovePos(), g_GMng.m_nStage);
							if (!g_GMng.m_bF10)
							{
								g_GMng.m_nBullet--;
							}
								if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_HEROFIRE]) && D_MNG->m_bSound)
									D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_HEROFIRE], D_MNG->GetSoundVolume());
							break;
						}
					}
				}
			}
		}
	}
}

void CGameScene::ChangeStage()
{
	if (g_GMng.m_nStage == 0 && g_GMng.m_nMap == 1 && g_GMng.m_bStartStage && !g_GMng.m_bStart)
	{
		if (!m_bChangeStage)
		{
			m_bChangeStage = TRUE;
		}
		D_CAMERA->SetPos(640.0f, -360.0f);
		//Dprintf("%d현재 알파값", m_pText->GetAlpha());
		if (m_pBlackground->GetAlpha() > 0.0f && !g_GMng.m_bBlack && !m_pText[0]->GetShow())
		{
			g_GMng.m_fBlackTime += D_WORLD->GetDeltaTime();
			if (g_GMng.m_fBlackTime > 0.05f)
			{

				g_GMng.m_fBlackTime = 0;
				m_pBlackground->SetAlpha(m_pBlackground->GetAlpha() - 0.05f);
			}
		}
		else
		{
			m_pText[0]->SetShow(TRUE);
			//m_pText->SetOutPutString("Next Stage : SEWER");
			m_pText[0]->SetPos(640.0f, -360.0f);
			if (m_pText[0]->GetAlpha() < 1.0f && g_GMng.m_bBlack2)
			{
				g_GMng.m_fBlackTime2 += D_WORLD->GetDeltaTime();
				if (g_GMng.m_fBlackTime2 > 0.1f)
				{
					g_GMng.m_fBlackTime2 = 0;
					m_pText[0]->SetAlpha(m_pText[0]->GetAlpha() + 0.05f);
				}
			}
			else if (m_pText[0]->GetAlpha() > 0.0f && !g_GMng.m_bBlack2)
			{
				g_GMng.m_fBlackTime2 += D_WORLD->GetDeltaTime();
				if (g_GMng.m_fBlackTime2 > 0.1f)
				{

					g_GMng.m_fBlackTime2 = 0;
					m_pText[0]->SetAlpha(m_pText[0]->GetAlpha() - 0.05f);
				}
			}
			else if (g_GMng.m_bBlack2)
			{
				g_GMng.m_bBlack2 = FALSE;
			}
			g_GMng.m_fBlackTime3 += D_WORLD->GetDeltaTime();
			if (g_GMng.m_fBlackTime3 >= 6.0f)
			{
				g_GMng.m_fBlackTime3 = 0;
				m_pText[0]->SetShow(FALSE);
				g_GMng.m_bBlack = FALSE;
				g_GMng.m_bBlack2 = TRUE;

				//m_Hero.m_pAnimation->SetPos(150.0f, -350.0f, 0.0f);
				D_CAMERA->SetPos(640.0f, -360.0f);
				m_BackUpCamera = D_CAMERA->GetPosVec3();
				m_pBlackground->SetPos(D_CAMERA->GetPosVec2());
				g_GMng.m_bScroll = FALSE;
			}
			//g_GMng.m_bBlack = TRUE;
		}
		g_GMng.m_fBlackTime4 += D_WORLD->GetDeltaTime();
		if (g_GMng.m_fBlackTime4 >= 7.0f)
		{
			//m_Hero.m_pAnimation->SetPos(150.0f, -350.0f, 0.0f);
			m_pText[0]->SetAlpha(0.0f);
			m_pText[0]->SetShow(FALSE);
			g_GMng.m_fBlackTime = 0;
			g_GMng.m_fBlackTime2 = 0;
			g_GMng.m_fBlackTime3 = 0;
			g_GMng.m_fBlackTime4 = 0;
			g_GMng.m_bBlack = TRUE;
			m_pBlackground->SetPos(-5000, 500);
			g_GMng.m_bStartStage = FALSE;
			g_GMng.m_nHeroHP = 5;

			for (int i = 0; i < E_SND_MAX; i++)
			{
				D_SOUND->Stop(D_MNG->m_BackSnd[i]);
			}
			if (D_MNG->m_bMusic)
			{
				D_SOUND->Play(D_MNG->m_BackSnd[E_SND_STAGE1], D_MNG->GetMusicVolume(), true);
			}
			if (m_bChangeStage)
			{
				m_bChangeStage = FALSE;
			}
		}
	}
	if (g_GMng.m_nStage == 5 && g_GMng.m_nMap == 1 && g_GMng.m_nLiveEny == 0)
	{
		if (g_GMng.m_bNextStageTime)
		{

			for (int i = 0; i < D_ROOM_MAX; i++)
			{
				m_CMap.m_ClippingHero[i]->SetLoopType(E_ANI_ONE, 1, 1, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
				if (i < D_DOOR_MAX - 1)
				{
					if (m_CMap.m_Door[i]->GetCurFrameNumber() != 5)
					{
						m_CMap.m_Door[i]->SetLoopType(E_ANI_ONE, 5, 9, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
					}
					else
					{
						m_CMap.m_Door[i]->SetPause(TRUE);
					}
				}
			}
			m_CMap.m_Door[5]->SetPos(1210.0f + 5 * 1280.0f, -350.0f);
			m_Hero.m_pAnimation->SetPos(150.0f, -350.0f, 0.0f);
			D_CAMERA->SetPos(640.0f, -360.0f);
			m_pBlackground->SetPos(D_CAMERA->GetPosVec2());
			for (int i = 0; i < E_SND_MAX; i++)
			{
				D_SOUND->Stop(D_MNG->m_BackSnd[i]);
			}
			if (m_pBlackground->GetAlpha() < 1.0f && g_GMng.m_bBlack)
			{
				g_GMng.m_fBlackTime += D_WORLD->GetDeltaTime();
				if (g_GMng.m_fBlackTime > 0.05f)
				{
					g_GMng.m_fBlackTime = 0;
					m_pBlackground->SetAlpha(m_pBlackground->GetAlpha() + 0.05f);
				}
			}
			else if (m_pBlackground->GetAlpha() > 0.0f && !g_GMng.m_bBlack && !m_pText[1]->GetShow())
			{
				g_GMng.m_fBlackTime += D_WORLD->GetDeltaTime();
				if (g_GMng.m_fBlackTime > 0.05f)
				{

					g_GMng.m_fBlackTime = 0;
					m_pBlackground->SetAlpha(m_pBlackground->GetAlpha() - 0.05f);
				}
			}
			else
			{
				if (m_pText[1]->GetAlpha() < 1.0f && g_GMng.m_bBlack2 && g_GMng.m_bBlack)
				{
					m_pText[1]->SetShow(TRUE);
					m_pText[1]->SetPos(640.0f, -360.0f);
					g_GMng.m_fBlackTime2 += D_WORLD->GetDeltaTime();
					if (g_GMng.m_fBlackTime2 > 0.1f)
					{
						g_GMng.m_fBlackTime2 = 0;
						m_pText[1]->SetAlpha(m_pText[1]->GetAlpha() + 0.05f);
					}
				}
				else if (m_pText[1]->GetAlpha() > 0.0f && !g_GMng.m_bBlack2)
				{
					g_GMng.m_fBlackTime2 += D_WORLD->GetDeltaTime();
					if (g_GMng.m_fBlackTime2 > 0.1f)
					{

						g_GMng.m_fBlackTime2 = 0;
						m_pText[1]->SetAlpha(m_pText[1]->GetAlpha() - 0.05f);
					}
				}
				else if (g_GMng.m_bBlack2)
				{
					g_GMng.m_bBlack2 = FALSE;
				}
				g_GMng.m_fBlackTime3 += D_WORLD->GetDeltaTime();
				if (g_GMng.m_fBlackTime3 >= 6.0f)
				{
					g_GMng.m_fBlackTime3 = 0;
					m_pText[1]->SetShow(FALSE);

					g_GMng.m_bBlack = FALSE;
					g_GMng.m_bBlack2 = TRUE;
					//m_pText->SetPos(10, -350.0f);
					m_Hero.m_pAnimation->SetPos(150.0f, -350.0f, 0.0f);
					D_CAMERA->SetPos(640.0f, -360.0f);
					m_pBlackground->SetPos(D_CAMERA->GetPosVec2());
					g_GMng.m_bScroll = FALSE;
				}
				//g_GMng.m_bBlack = TRUE;
			}
			g_GMng.m_fBlackTime4 += D_WORLD->GetDeltaTime();
			if (g_GMng.m_fBlackTime4 >= 8.45f)
			{
				m_Hero.m_pAnimation->SetPos(150.0f, -350.0f, 0.0f);
				m_pText[1]->SetAlpha(0.0f);
				m_pText[1]->SetShow(FALSE);
				g_GMng.m_fBlackTime = 0;
				g_GMng.m_fBlackTime2 = 0;
				g_GMng.m_fBlackTime3 = 0;
				g_GMng.m_fBlackTime4 = 0;
				g_GMng.m_bBlack = TRUE;
				g_GMng.m_nMap = 2;
				g_GMng.m_nStage = 0;
				m_pBlackground->SetPos(-5000, 500);
				g_GMng.m_nHeroHP = 5;
				g_GMng.m_bNextStageTime = FALSE;
				for (int i = 0; i < E_SND_MAX; i++)
				{
					D_SOUND->Stop(D_MNG->m_BackSnd[i]);
				}
				if (D_MNG->m_bMusic)
				{
					D_SOUND->Play(D_MNG->m_BackSnd[E_SND_STAGE2], D_MNG->GetMusicVolume(), true);
				}
				if (m_bChangeStage)
				{
					m_bChangeStage = FALSE;
				}
			}
		}
		else
		{
			g_GMng.m_fNextStageTime += D_WORLD->GetDeltaTime();
			if (g_GMng.m_fNextStageTime >= 3)
			{
				g_GMng.m_bNextStageTime = TRUE;
				g_GMng.m_fNextStageTime = 0;
			}
		}
	}
	if (g_GMng.m_nStage == 6 && g_GMng.m_nMap == 2 && g_GMng.m_nLiveEny == 0)
	{
		if (g_GMng.m_bNextStageTime)
		{
			g_GMng.m_bUP2 = TRUE;
			g_GMng.m_bStart = TRUE;
			g_GMng.m_bmission = TRUE;
		}
		else
		{
			g_GMng.m_fNextStageTime += D_WORLD->GetDeltaTime();
			if (g_GMng.m_fNextStageTime >= 3)
			{
				g_GMng.m_bNextStageTime = TRUE;
				g_GMng.m_fNextStageTime = 0;
			}
		}
	}
}

void CGameScene::CreateMonster(int nStage)
{
	switch (g_GMng.m_nMap)
	{
	case 1:
		switch (nStage)
		{
			break;
		case 1:
		{
			m_pTutorial[0]->SetShow(FALSE);
			m_pTutorial[1]->SetShow(TRUE);
			//stEMVec2 Vec2(1000 + 1280 * nStage, -350);
			//m_MiniBoss.Enable(Vec2);
			stEMVec2 Vec2 = stEMVec2(500 + 1280 * nStage, -300);
			//m_SE.Enable(0, Vec2, false);
			//Vec2 = stEMVec2(100 + 150 * 6 + 1280 * nStage, -100 - 50 * 6);
			//m_PE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 5 + 1280 * nStage, -400);
			m_PE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -400);
			m_SE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -400);
			m_ME.Enable(1, Vec2, false);
		}
		break;
		case 2:
		{
			m_pTutorial[0]->SetShow(FALSE);
			m_pTutorial[1]->SetShow(FALSE);
			stEMVec2 Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 2);
			m_PE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 5 + 1280 * nStage, -100 - 50 * 4);
			m_PE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 6);
			m_PE.Enable(2, Vec2, false);
		}
		break;
		case 3:
		{
			stEMVec2 Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 2);
			m_PE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 4);
			m_PE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 6);
			m_PE.Enable(2, Vec2, false);
		}
		break;
		case 4:
		{
			stEMVec2 Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 1);
			m_PE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 7);
			m_PE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 5 + 1280 * nStage, -100 - 50 * 2);
			m_PE.Enable(2, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 5 + 1280 * nStage, -100 - 50 * 6);
			m_PE.Enable(3, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 4);
			m_SE.Enable(0, Vec2, false);
		}
		break;
		case 5:
		{
			stEMVec2 Vec2(1000 + 1280 * 5, -350);
			m_MiniBoss.Enable(Vec2);
			for (int i = 0; i < E_SND_MAX; i++)
			{
				D_SOUND->Stop(D_MNG->m_BackSnd[i]);
			}
			if (D_MNG->m_bMusic)
			{
				D_SOUND->Play(D_MNG->m_BackSnd[E_SND_BOSS], D_MNG->GetMusicVolume(), true);
			}
		}
		}
		break;
	case 2:
		switch (nStage)
		{
		case 1:
		{

			stEMVec2 Vec2 = stEMVec2(100 + 150 * 5 + 1280 * nStage, -100 - 50 * 1);
			m_PE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 5 + 1280 * nStage, -100 - 50 * 7);
			m_PE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 6 + 1280 * nStage, -100 - 50 * 2);
			m_PE.Enable(2, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 6 + 1280 * nStage, -100 - 50 * 6);
			m_PE.Enable(3, Vec2, false);
		}
		break;
		case 2:
		{

			stEMVec2 Vec2 = stEMVec2(100 + 150 * 5 + 1280 * nStage, -100 - 50 * 4);
			m_PE.Enable(2, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 2);
			m_SE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 6);
			m_SE.Enable(1, Vec2, false);

		}
		break;
		case 3:
		{
			stEMVec2 Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 3);
			m_PE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 5);
			m_PE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -100 - 50 * 1);
			m_SE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -100 - 50 * 7);
			m_SE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -100 - 50 * 4);
			m_SE.Enable(2, Vec2, false);
		}
		break;
		case 4:
		{
			stEMVec2 Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -100 - 50 * 1);
			m_PE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -100 - 50 * 7);
			m_PE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 3);
			m_PE.Enable(2, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 5);
			m_PE.Enable(3, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -100 - 50 * 4);
			m_SE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 2);
			m_SE.Enable(1, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 6);
			m_SE.Enable(2, Vec2, false);
		}
		break;
		case 5:
		{
			stEMVec2 Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 4);
			m_PE.Enable(0, Vec2, false);
			Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -100 - 50 * 4);
			m_SE.Enable(0, Vec2, false);

		}
		break;
		case 6:
		{
			stEMVec2 Vec2(1150 + 1280 * nStage, -150);
			m_BOSS.Enable(Vec2);
			for (int i = 0; i < E_SND_MAX; i++)
			{
				D_SOUND->Stop(D_MNG->m_BackSnd[i]);
			}
			if (D_MNG->m_bMusic)
			{
				D_SOUND->Play(D_MNG->m_BackSnd[E_SND_BOSS], D_MNG->GetMusicVolume(), true);
			}
		}
		break;
		}
		break;
	}
}

void CGameScene::CreateFallMonster(int nStage)
{
	switch (g_GMng.m_nMap)
	{
	case 1:
		switch (nStage)
		{
		case 2:
		{

		}
		break;
		case 3:
		{
			if (m_bCheckEnySpn[0] == false)
			{
				if (g_GMng.m_nLiveEny == 1)
				{
					stEMVec2 Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -100 - 50 * 4);
					m_SE.Enable(0, Vec2, true);
					m_bCheckEnySpn[0] = true;
				}
			}
		}
		break;
		case 4:
		{
			if (m_bCheckEnySpn[1] == false)
			{
				if (g_GMng.m_nLiveEny == 0)
				{
					stEMVec2 Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -100 - 50 * 1);
					m_PE.Enable(2, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -100 - 50 * 7);
					m_PE.Enable(3, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 2 + 1280 * nStage, -100 - 50 * 4);
					m_SE.Enable(2, Vec2, true);
					m_bCheckEnySpn[1] = true;
				}
			}
		}
		break;
		case 5:
		{
			if (g_GMng.m_BOSSUse)
				m_MiniBoss.m_fCreatEnemyTime += D_WORLD->GetDeltaTime();
			if (m_MiniBoss.m_fCreatEnemyTime >= 5)
			{
				m_MiniBoss.m_fCreatEnemyTime = 0;
				if (g_GMng.m_nLiveEny < 3)
				{
					for (int i = 0; i < 2; i++)
					{
						switch (CEMMath::RandomIntInRange(0, 2))
						{
						case 0:
						{
							if (!m_PE.m_Enemy[i]->GetShow())
							{
								stEMVec2 Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -300 - 100 * i);
								m_PE.Enable(i, Vec2, true);
							}
						}
						break;
						case 1:
						{
							if (!m_SE.m_Enemy[i]->GetShow())
							{
								stEMVec2 Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -300 - 100 * i);
								m_SE.Enable(i, Vec2, true);
							}
						}
						break;
						case 2:
						{
							if (!m_ME.m_Enemy[i]->GetShow())
							{
								stEMVec2 Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -300 - 100 * i);
								m_ME.Enable(i, Vec2, true);
							}
						}
						break;
						}
					}
				}

			}
		}
		}
		break;
	case 2:
		switch (nStage)
		{
		case 3:
		{
			if (m_bCheckEnySpn[2] == false)
			{
				if (g_GMng.m_nLiveEny == 3)
				{
					stEMVec2 Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -100 - 50 * 1);
					m_SE.Enable(3, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -100 - 50 * 7);
					m_SE.Enable(4, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 4);
					m_ME.Enable(0, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 2);
					m_ME.Enable(1, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 6);
					m_ME.Enable(2, Vec2, true);
					m_bCheckEnySpn[2] = true;
				}
			}
		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{
			if (m_bCheckEnySpn[3] == false)
			{
				if (g_GMng.m_nLiveEny == 0)
				{
					stEMVec2 Vec2 = stEMVec2(100 + 150 * 4 + 1280 * nStage, -100 - 50 * 1);
					m_PE.Enable(1, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 2 + 1280 * nStage, -100 - 50 * 1);
					m_SE.Enable(1, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 6 + 1280 * nStage, -100 - 50 * 1);
					m_ME.Enable(1, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 3 + 1280 * nStage, -100 - 50 * 7);
					m_PE.Enable(2, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 5 + 1280 * nStage, -100 - 50 * 7);
					m_SE.Enable(2, Vec2, true);
					Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -100 - 50 * 7);
					m_ME.Enable(2, Vec2, true);
					m_bCheckEnySpn[3] = true;
				}
			}
		}
		break;
		case 6:
		{
			//-----------------------------------보스 패턴 1 적 소환
			if (g_GMng.m_BOSSUse)
				m_BOSS.m_fCreatEnemyTime += D_WORLD->GetDeltaTime();
			if (m_BOSS.m_fCreatEnemyTime >= 5)
			{
				m_BOSS.m_fCreatEnemyTime = 0;
				if (g_GMng.m_nLiveEny < 3 && m_BOSS.pattern == 1)
				{
					for (int i = 0; i < 2; i++)
					{
						switch (CEMMath::RandomIntInRange(0, 2))
						{
						case 0:
						{
							if (!m_PE.m_Enemy[i]->GetShow())
							{
								stEMVec2 Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -300 - 100 * i);
								m_PE.Enable(i, Vec2, true);
							}
						}
						break;
						case 1:
						{
							if (!m_SE.m_Enemy[i]->GetShow())
							{
								stEMVec2 Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -300 - 100 * i);
								m_SE.Enable(i, Vec2, true);
							}
						}
						break;
						case 2:
						{
							if (!m_ME.m_Enemy[i]->GetShow())
							{
								stEMVec2 Vec2 = stEMVec2(100 + 150 * 1 + 1280 * nStage, -300 - 100 * i);
								m_ME.Enable(i, Vec2, true);
							}
						}
						break;
						}
					}
				}

			}
		}
		break;
		}
		break;
	}
}
void CGameScene::MoveStage(int nStage)
{
	if (m_Hero.m_pAnimation->GetBoundingBox().stRB.m_fX < m_CMap.m_Door[nStage]->GetBoundingBox().stRT.m_fX &&
		m_Hero.m_pAnimation->GetBoundingBox().stRB.m_fY < m_CMap.m_Door[nStage]->GetBoundingBox().stRT.m_fY &&
		m_Hero.m_pAnimation->GetBoundingBox().stRB.m_fX > m_CMap.m_Door[nStage]->GetBoundingBox().stLB.m_fX &&
		m_Hero.m_pAnimation->GetBoundingBox().stRB.m_fY > m_CMap.m_Door[nStage]->GetBoundingBox().stLB.m_fY)
	{
		if (D_INPUT->IsKeyDown(VK_D))
		{
			if (g_GMng.m_nLiveEny <= 0)
			{
				g_GMng.m_bNextStage = TRUE;
			}
			else
			{
				g_GMng.m_bNextStage = FALSE;
			}
			if (g_GMng.m_bNextStage)
			{
				if (m_CMap.m_Door[nStage]->GetCurFrameNumber() == 4 || m_CMap.m_Door[nStage]->GetCurFrameNumber() == 9)
				{

					//m_Hero.m_pAnimation->SetPos(m_Hero.m_pAnimation->GetPosVec2().m_fX, m_Hero.m_pAnimation->GetPosVec2().m_fY);
					g_GMng.m_fMoveCamaraTime = 0;
					g_GMng.m_bScroll = TRUE;
					//m_CScore.m_pNum->MoveX(1280.0f);
					g_GMng.m_nStage++;
					m_Bullet.m_nStage = g_GMng.m_nStage;
					g_GMng.m_fedX = D_CAMERA->GetPosVec2().m_fX + 1280;
					m_BackUpCamera.m_fX = g_GMng.m_fedX;
					CreateMonster(g_GMng.m_nStage);
					g_GMng.m_nScore += 50;
					if (g_GMng.m_nHeroHP < 5)
					{
						g_GMng.m_nHeroHP += 1;
					}
				}
			}
			if (m_CMap.m_Door[nStage]->GetCurFrameNumber() == 4 || m_CMap.m_Door[nStage]->GetCurFrameNumber() == 9)
			{
				m_CMap.m_Door[nStage]->SetPause(TRUE);
				if (nStage - 1 >= 0)
				{
					m_CMap.m_Door[nStage - 1]->SetPause(FALSE);

				}
			}
			else
			{
				m_CMap.m_Door[nStage]->SetPause(FALSE);
				if (g_GMng.m_nMap == 1)
				{
					if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOOR1]) && D_MNG->m_bSound)
						D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOOR1], D_MNG->GetSoundVolume());
				}
				else
				{
					if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOOR2]) && D_MNG->m_bSound)
						D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOOR2 ], D_MNG->GetSoundVolume());
				}
			}
		}
	}
}
void CGameScene::GameInfo()
{
	Clipping(g_GMng.m_nStage);
	MoveStage(g_GMng.m_nStage);
}
void CGameScene::Clipping(int nStage)
{
	if (m_Hero.m_pAnimation->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
	{
		m_Hero.m_pAnimation->SetPos(m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX + 32, m_Hero.m_pAnimation->GetPosVec2().m_fY);
	}
	if (m_Hero.m_pAnimation->GetBoundingBox().stLB.m_fY < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY)
	{
		m_Hero.m_pAnimation->SetPos(m_Hero.m_pAnimation->GetPosVec2().m_fX, m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY + 40);
	}
	if (m_Hero.m_pAnimation->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
	{
		m_Hero.m_pAnimation->SetPos(m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX - 32, m_Hero.m_pAnimation->GetPosVec2().m_fY);
	}
	if (m_Hero.m_pAnimation->GetBoundingBox().stRT.m_fY > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY)
	{
		m_Hero.m_pAnimation->SetPos(m_Hero.m_pAnimation->GetPosVec2().m_fX, m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY - 40);
	}

	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (m_Bullet.m_pAnimation[i]->GetShow())
		{
			if (m_Bullet.m_pAnimation[i]->GetBoundingBox().stLB.m_fX + 50 < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
			{
				m_Bullet.m_stClickDestPos[i] = stEMVec3(0.0f, 0.0f, 0.0f);
				m_Bullet.m_pAnimation[i]->SetPause(FALSE);
				m_Bullet.m_nPlayAni[i] = 0;
				m_Bullet.m_pSheldH[i]->SetShow(TRUE);
				m_Bullet.m_pSheldH[i]->SetPause(FALSE);
				m_Bullet.m_pAnimation[i]->SetAlpha(0);
				m_Bullet.m_pSheldH[i]->SetZRot(-180);
			}
			if (m_Bullet.m_pAnimation[i]->GetBoundingBox().stRT.m_fX - 50 > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
			{
				m_Bullet.m_stClickDestPos[i] = stEMVec3(0.0f, 0.0f, 0.0f);
				m_Bullet.m_pAnimation[i]->SetPause(FALSE);
				m_Bullet.m_nPlayAni[i] = 0;
				m_Bullet.m_pSheldH[i]->SetShow(TRUE);
				m_Bullet.m_pSheldH[i]->SetPause(FALSE);
				m_Bullet.m_pAnimation[i]->SetAlpha(0);
				m_Bullet.m_pSheldH[i]->SetZRot(0);
			}
		}
	}
	ClippingEnemy(nStage);
	m_Hero.m_pArm->SetPos(m_Hero.m_pAnimation->GetPosVec2().m_fX - 24, m_Hero.m_pAnimation->GetPosVec2().m_fY - 6);
}

void CGameScene::ClippingEnemy(int nStage)
{
	for (int i = 0; i < D_PE_MAX; i++)
	{
		if (m_PE.m_Enemy[i]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
		{
			m_PE.stEMNowVec2[i] = stEMVec2(m_PE.m_Enemy[i]->GetPosVec2().m_fX + 50, m_PE.m_Enemy[i]->GetPosVec2().m_fY);
		}
		if (m_PE.m_Enemy[i]->GetBoundingBox().stLB.m_fY < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY)
		{
			m_PE.stEMNowVec2[i] = stEMVec2(m_PE.m_Enemy[i]->GetPosVec2().m_fX, m_PE.m_Enemy[i]->GetPosVec2().m_fY + 50);
		}
		if (m_PE.m_Enemy[i]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
		{
			m_PE.stEMNowVec2[i] = stEMVec2(m_PE.m_Enemy[i]->GetPosVec2().m_fX - 50, m_PE.m_Enemy[i]->GetPosVec2().m_fY);
		}
		if (m_PE.m_Enemy[i]->GetBoundingBox().stRT.m_fY > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY)
		{
			m_PE.stEMNowVec2[i] = stEMVec2(m_PE.m_Enemy[i]->GetPosVec2().m_fX, m_PE.m_Enemy[i]->GetPosVec2().m_fY - 50);
		}

		//if (m_PE.m_Enemy[i]->GetShow())
		//{
		for (int j = 0; j < D_BULLET_MAX - 10; j++)
		{
			if (m_PE.m_CEnyBullet[i].m_pAnimation[j]->GetShow())
			{
				if (m_PE.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stLB.m_fX + 50 < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
				{
					m_PE.m_CEnyBullet[i].m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
					m_PE.m_CEnyBullet[i].m_pAnimation[j]->SetPause(FALSE);
					m_PE.m_CEnyBullet[i].m_nPlayAni[j] = 0;
					m_PE.m_CEnyBullet[i].m_pAnimation[i]->SetZRot(0);
				}
				if (m_PE.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stRT.m_fX - 50 > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
				{
					m_PE.m_CEnyBullet[i].m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
					m_PE.m_CEnyBullet[i].m_pAnimation[j]->SetPause(FALSE);
					m_PE.m_CEnyBullet[i].m_nPlayAni[j] = 0;
					m_PE.m_CEnyBullet[i].m_pAnimation[j]->SetZRot(-180);
				}
			}
		}
		//}
	}
	for (int i = 0; i < D_ME_MAX; i++)
	{
		if (m_ME.m_Enemy[i]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
		{
			m_ME.stEMNowVec2[i] = stEMVec2(m_ME.m_Enemy[i]->GetPosVec2().m_fX + 50, m_ME.m_Enemy[i]->GetPosVec2().m_fY);
		}
		if (m_ME.m_Enemy[i]->GetBoundingBox().stLB.m_fY < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY)
		{
			m_ME.stEMNowVec2[i] = stEMVec2(m_ME.m_Enemy[i]->GetPosVec2().m_fX, m_ME.m_Enemy[i]->GetPosVec2().m_fY + 50);
		}
		if (m_ME.m_Enemy[i]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
		{
			m_ME.stEMNowVec2[i] = stEMVec2(m_ME.m_Enemy[i]->GetPosVec2().m_fX - 50, m_ME.m_Enemy[i]->GetPosVec2().m_fY);
		}
		if (m_ME.m_Enemy[i]->GetBoundingBox().stRT.m_fY > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY)
		{
			m_ME.stEMNowVec2[i] = stEMVec2(m_ME.m_Enemy[i]->GetPosVec2().m_fX, m_ME.m_Enemy[i]->GetPosVec2().m_fY - 50);
		}

		//if (m_ME.m_Enemy[i]->GetShow())
		//{
		for (int j = 0; j < D_BULLET_MAX - 10; j++)
		{
			if (m_ME.m_CEnyBullet[i].m_pAnimation[j]->GetShow())
			{
				if (m_ME.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stLB.m_fX + 50 < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
				{
					m_ME.m_CEnyBullet[i].m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
					m_ME.m_CEnyBullet[i].m_pAnimation[j]->SetPause(FALSE);
					m_ME.m_CEnyBullet[i].m_nPlayAni[j] = 0;
					m_ME.m_CEnyBullet[i].m_pAnimation[i]->SetZRot(0);
				}
				if (m_ME.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stRT.m_fX - 50 > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
				{
					m_ME.m_CEnyBullet[i].m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
					m_ME.m_CEnyBullet[i].m_pAnimation[j]->SetPause(FALSE);
					m_ME.m_CEnyBullet[i].m_nPlayAni[j] = 0;
					m_ME.m_CEnyBullet[i].m_pAnimation[j]->SetZRot(-180);
				}
			}
		}
		//}
	}
	for (int i = 0; i < D_SE_MAX; i++)
	{
		if (m_SE.m_Enemy[i]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
		{
			m_SE.stEMNowVec2[i] = stEMVec2(m_SE.m_Enemy[i]->GetPosVec2().m_fX + 50, m_SE.m_Enemy[i]->GetPosVec2().m_fY);
		}
		if (m_SE.m_Enemy[i]->GetBoundingBox().stLB.m_fY < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY)
		{
			m_SE.stEMNowVec2[i] = stEMVec2(m_SE.m_Enemy[i]->GetPosVec2().m_fX, m_SE.m_Enemy[i]->GetPosVec2().m_fY + 50);
		}
		if (m_SE.m_Enemy[i]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
		{
			m_SE.stEMNowVec2[i] = stEMVec2(m_SE.m_Enemy[i]->GetPosVec2().m_fX - 50, m_SE.m_Enemy[i]->GetPosVec2().m_fY);
		}
		if (m_SE.m_Enemy[i]->GetBoundingBox().stRT.m_fY > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY)
		{
			m_SE.stEMNowVec2[i] = stEMVec2(m_SE.m_Enemy[i]->GetPosVec2().m_fX, m_SE.m_Enemy[i]->GetPosVec2().m_fY - 50);
		}

		//if (m_SE.m_Enemy[i]->GetShow())
		//{
		for (int j = 0; j < D_BULLET_MAX - 10; j++)
		{
			if (m_SE.m_CEnyBullet[i].m_pAnimation[j]->GetShow())
			{
				if (m_SE.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stLB.m_fX + 50 < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
				{
					m_SE.m_CEnyBullet[i].m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
					m_SE.m_CEnyBullet[i].m_pAnimation[j]->SetPause(FALSE);
					m_SE.m_CEnyBullet[i].m_nPlayAni[j] = 0;
					m_SE.m_CEnyBullet[i].m_pAnimation[j]->SetZRot(0);
				}
				if (m_SE.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stRT.m_fX - 50 > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
				{
					m_SE.m_CEnyBullet[i].m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
					m_SE.m_CEnyBullet[i].m_pAnimation[j]->SetPause(FALSE);
					m_SE.m_CEnyBullet[i].m_nPlayAni[j] = 0;
					m_SE.m_CEnyBullet[i].m_pAnimation[j]->SetZRot(-180);
				}
			}
		}
	}
	for (int j = 0; j < D_BULLET_MAX - 00; j++)
	{
		if (m_BOSS.m_CEnyBullet.m_pAnimation[j]->GetShow())
		{
			if (m_BOSS.m_CEnyBullet.m_pAnimation[j]->GetBoundingBox().stLB.m_fX + 50 < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
			{
				m_BOSS.m_CEnyBullet.m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
				m_BOSS.m_CEnyBullet.m_pAnimation[j]->SetPause(FALSE);
				m_BOSS.m_CEnyBullet.m_nPlayAni[j] = 0;
				m_BOSS.m_CEnyBullet.m_pAnimation[j]->SetZRot(0);
			}
			if (m_BOSS.m_CEnyBullet.m_pAnimation[j]->GetBoundingBox().stRT.m_fX - 50 > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
			{
				m_BOSS.m_CEnyBullet.m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
				m_BOSS.m_CEnyBullet.m_pAnimation[j]->SetPause(FALSE);
				m_BOSS.m_CEnyBullet.m_nPlayAni[j] = 0;
				m_BOSS.m_CEnyBullet.m_pAnimation[j]->SetZRot(-180);
			}
		}
	}
	if (m_MiniBoss.m_Enemy->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
	{
		m_MiniBoss.stEMNowVec2 = stEMVec2(m_MiniBoss.m_Enemy->GetPosVec2().m_fX + 50, m_MiniBoss.m_Enemy->GetPosVec2().m_fY);
	}
	if (m_MiniBoss.m_Enemy->GetBoundingBox().stLB.m_fY < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY)
	{
		m_MiniBoss.stEMNowVec2 = stEMVec2(m_MiniBoss.m_Enemy->GetPosVec2().m_fX, m_MiniBoss.m_Enemy->GetPosVec2().m_fY + 50);
	}
	if (m_MiniBoss.m_Enemy->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
	{
		m_MiniBoss.stEMNowVec2 = stEMVec2(m_MiniBoss.m_Enemy->GetPosVec2().m_fX - 50, m_MiniBoss.m_Enemy->GetPosVec2().m_fY);
	}
	if (m_MiniBoss.m_Enemy->GetBoundingBox().stRT.m_fY > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY)
	{
		m_MiniBoss.stEMNowVec2 = stEMVec2(m_MiniBoss.m_Enemy->GetPosVec2().m_fX, m_MiniBoss.m_Enemy->GetPosVec2().m_fY - 50);
	}
	for (int j = 0; j < D_BULLET_MAX - 00; j++)
	{
		if (m_MiniBoss.m_CEnyBullet.m_pAnimation[j]->GetShow())
		{
			if (m_MiniBoss.m_CEnyBullet.m_pAnimation[j]->GetBoundingBox().stLB.m_fX + 50 < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
			{
				m_MiniBoss.m_CEnyBullet.m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
				m_MiniBoss.m_CEnyBullet.m_pAnimation[j]->SetPause(FALSE);
				m_MiniBoss.m_CEnyBullet.m_nPlayAni[j] = 0;
				m_MiniBoss.m_CEnyBullet.m_pAnimation[j]->SetZRot(0);
			}
			if (m_MiniBoss.m_CEnyBullet.m_pAnimation[j]->GetBoundingBox().stRT.m_fX - 50 > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
			{
				m_MiniBoss.m_CEnyBullet.m_stClickDestPos[j] = stEMVec3(0.0f, 0.0f, 0.0f);
				m_MiniBoss.m_CEnyBullet.m_pAnimation[j]->SetPause(FALSE);
				m_MiniBoss.m_CEnyBullet.m_nPlayAni[j] = 0;
				m_MiniBoss.m_CEnyBullet.m_pAnimation[j]->SetZRot(-180);
			}
		}
	}
}
void CGameScene::Die()
{
	if (g_GMng.m_nHeroHP == -2)
	{
		if (m_Hero.m_pAnimation->GetCurFrameNumber() == 25)
		{

		}
	}
}