#include "stdafx.h"


//void CStage3::Enter(CSceneWork* pSceneWork)
//{
//	//m_pText = new CEMText("으뜸체", "여기는 game 입니다");
//	//m_pText->SetPos(0.0f, 50.0f);
//
//	//Commit(0, "테스트", m_pText);
//
//	//m_Monster.CreateObj(this);
//	m_BackGroundSnd = D_SOUND->FileOpen("Data/Sound/dragon_flight.mp3");
//	//D_SOUND->Play(m_BackGroundSnd, 0.5f);
//	m_CScore.CreateObj(this);
//	m_CMap.CreateObj(this);
//	m_PE.CreateObj(this);
//	m_SE.CreateObj(this);
//	m_ME.CreateObj(this);
//
//	D_CAMERA->SetPos(640.0f, -360.0f, 620.0f);
//	g_GMng.m_bScroll = FALSE;
//	g_GMng.m_fBulletCtrlTime = 0;
//	g_GMng.m_fMonsterCtrlTime = 0;
//	g_GMng.m_fScoreCtrlTime = 0;
//	g_GMng.m_nScore = 0;
//	g_GMng.m_nStage = 0;
//	g_GMng.m_fedX = 0;
//	g_GMng.m_nScroll = 0;
//	g_GMng.m_fMoveCamaraTime = 0;
//}
//
//void CStage3::Update(CHero* Hero,CSceneWork* pSceneWork, float dt)
//{
//
//	m_PE.Update(m_CMap.m_ClippingHero[g_GMng.m_nStage], Hero);
//	m_ME.Update(m_CMap.m_ClippingHero[g_GMng.m_nStage], Hero);
//	m_SE.Update(m_CMap.m_ClippingHero[g_GMng.m_nStage], Hero);
//
//	Score(dt);
//	GameInfo();
//
//	Scroll();
//	CRootScene::Update(pSceneWork, dt);
//}
//void CStage3::Scroll()
//{
//	if (g_GMng.m_bScroll)
//	{
//
//		float stCalsPos = D_CAMERA->GetPosVec3().m_fX;
//		stCalsPos = CEMMath::Lerp(stCalsPos, g_GMng.m_fedX, D_WORLD->GetDeltaTime() * 3.0f);
//		D_CAMERA->SetPosX(stCalsPos);
//		g_GMng.m_nScroll += stCalsPos / (g_GMng.m_nStage * 1280);
//		//if (g_GMng.m_nScroll >= 1280)
//		//{
//		//	g_GMng.m_nScroll = 0;
//		//	g_GMng.m_bScroll = FALSE;
//		//}
//	}
//}
//
//void CStage3::Render(CSceneWork* pSceneWork)
//{
//
//	CRootScene::Render(pSceneWork);
//}
//
//void CStage3::Exit(CSceneWork* pSceneWork)
//{
//	Destroy();
//}
//
//void CStage3::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
//{
//	int x = 0;
//	stEMVec2 stDesPos(0.0f, 0.0f);
//	stEMVec3 stTemp = NULL;
//	switch (eButton)
//	{
//	case E_MOUSE_LEFT:
//
//		//stDesPos = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);
//
//		//m_stClickDestPos = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);
//
//		//stTemp = m_stClickDestPos - m_Hero.m_pAnimation->GetPosVec3();
//		//stTemp.Normalize();
//
//		////단위벡터 만드후 길이를 늘려줍니다^^
//		//stTemp = stTemp * 270.0f;
//		//m_stClickDestPos = stTemp;
//		//x = 0;
//		break;
//	case E_MOUSE_RIGHT:
//		x = 5;
//		break;
//	}
//}
//void CStage3::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
//{
//	m_Bullet.MouseUpEvent(stPos, eButton, m_Hero);
//}
//
//void CStage3::MouseMoveEvent(stMouseInfo stPos)
//{
//	m_Bullet.MouseMoveEvent(stPos, &m_Hero);
//	DestDirAngleCalc(stPos);
//}
//void CStage3::DestDirAngleCalc(stMouseInfo stPos)
//{
//	stEMVec2 stDesPos(0.0f, 0.0f);
//	stDesPos = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);
//
//	m_stDestPos = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);
//
//	m_stHeroPosToDestPosDir = m_stDestPos - m_Hero.m_pAnimation->GetPosVec3();
//
//	// 단위벡터로 변경
//	m_stHeroPosToDestPosDir.Normalize();
//	m_stHeroDirVec3.Normalize();
//
//	// 내적 계산
//	m_fDot = stEMVec3::Dot(m_stHeroDirVec3, m_stHeroPosToDestPosDir);
//
//	// 각도 구하기^^
//	m_fRadian = (float)acos(m_fDot);
//
//	// 주인공의 업벡터 구하기
//	m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));
//
//	if (stEMVec3::Dot(m_stHeroRightVec3, m_stHeroPosToDestPosDir) > 0.0f)
//	{
//		m_Hero.m_pArm->SetZRot(CEMMath::ToDegrees(m_fRadian) + 90);
//		//Dprintf("왼쪽 %f\n", m_fRadian);
//	}
//	else
//	{
//		m_Hero.m_pArm->SetZRot(CEMMath::ToDegrees(-m_fRadian) + 90);
//		//Dprintf("오른쪽 %f\n", m_fRadian);
//	}
//	if (stDesPos.m_fX < m_Hero.m_pAnimation->GetPosVec2().m_fX)
//	{
//		if (m_Hero.m_pAnimation->GetCurFrameNumber() == 0)
//		{
//			m_Hero.m_pAnimation->SetLoopType(E_ANI_LOOP, 1, 2);
//
//		}
//	}
//	else
//	{
//		if (m_Hero.m_pAnimation->GetCurFrameNumber() != 0)
//		{
//			m_Hero.m_pAnimation->SetLoopType(E_ANI_LOOP, 0, 0);
//		}
//	}
//}
//
//HRESULT CStage3::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg)
//	{
//	case WM_LBUTTONDOWN:
//	{
//		int x = 0;
//	}break;
//	}
//	return msg;
//}
//
//void CStage3::CreateBullet(float dt)
//{
//
//	g_GMng.m_fBulletCtrlTime += dt;
//	if (D_INPUT->IsKeyDown(VK_LBUTTON))
//	{
//		if (g_GMng.m_fBulletCtrlTime >= 0.5f)
//		{
//			g_GMng.m_fBulletCtrlTime = 0;
//			for (int i = 0; i < D_BULLET_MAX; i++)
//			{
//				if (m_Bullet.m_pAnimation[i]->GetShow() == FALSE)
//				{
//					m_Bullet.Enable(i, stEMVec3(m_Hero.m_pArm->GetPosVec3().m_fX, m_Hero.m_pArm->GetPosVec3().m_fY, m_Hero.m_pArm->GetPosVec3().m_fZ), D_INPUT->GetMouseMovePos(), g_GMng.m_nStage);
//					break;
//				}
//			}
//		}
//	}
//}
//
//void CStage3::CreateMonster(int nStage)
//{
//
//	switch (nStage)
//	{
//	case 1:
//	{
//		stEMVec2 Vec2(900 + 1280,-400);
//		m_PE.Enable(0, Vec2);
//		Vec2 = stEMVec2(1000 + 1280, -400);
//		m_PE.Enable(1, Vec2);
//	}
//		break;
//	case 2:
//	{
//		stEMVec2 Vec2(700 + 2560, -400);
//		m_PE.Enable(0, Vec2);
//		Vec2 = stEMVec2(700 + 2560, -200);
//		m_PE.Enable(1, Vec2);
//	}
//		break;
//	case 3:
//	{
//		stEMVec2 Vec2(900 + 3840, -300);
//		m_PE.Enable(0, Vec2);
//		Vec2 = stEMVec2(700 + 3840, -400);
//		m_PE.Enable(1, Vec2);		
//		Vec2 = stEMVec2(700 + 3840, -200);
//		m_PE.Enable(2, Vec2);
//	}
//		break;
//	case 4:
//	{
//		stEMVec2 Vec2(900 + 5120, -150);
//		m_PE.Enable(0, Vec2);
//		Vec2 = stEMVec2(900 + 5120, -250);
//		m_PE.Enable(1, Vec2);
//		Vec2 = stEMVec2(900 + 5120, -350);
//		m_PE.Enable(2, Vec2);
//		Vec2 = stEMVec2(900 + 5120, -450);
//		m_PE.Enable(3, Vec2);
//
//	}
//		break;
//	default:
//		break;
//	}
//}
//
//void CStage3::Score(float dt)
//{
//	g_GMng.m_fScoreCtrlTime += dt;
//	if (g_GMng.m_fScoreCtrlTime >= 0.1f)
//	{
//		g_GMng.m_fScoreCtrlTime = 0;
//		g_GMng.m_nScore += 10;
//	}
//}
//
//
//void CStage3::MoveStage(int nStage)
//{
//	if (nStage == 5)//추가--------------------------------------------------------------------------------------보스 죽으면 넘어가게 추가바람
//	{
//		D_SCENE->ChangeSceneFade("Stage2");
//	}
//	if (m_Hero.m_pAnimation->GetBoundingBox().stRB.m_fX < m_CMap.m_Door[nStage]->GetBoundingBox().stRT.m_fX &&
//		m_Hero.m_pAnimation->GetBoundingBox().stRB.m_fY < m_CMap.m_Door[nStage]->GetBoundingBox().stRT.m_fY &&
//		m_Hero.m_pAnimation->GetBoundingBox().stRB.m_fX > m_CMap.m_Door[nStage]->GetBoundingBox().stLB.m_fX &&
//		m_Hero.m_pAnimation->GetBoundingBox().stRB.m_fY > m_CMap.m_Door[nStage]->GetBoundingBox().stLB.m_fY)
//	{
//		if (D_INPUT->IsKeyDown(VK_D))
//		{
//			int nIndex = D_PE_MAX;
//			for (int i = 0; i < D_PE_MAX; i++)
//			{
//				if (!m_PE.m_Enemy[i]->GetShow())
//				{
//					nIndex--;
//				}
//			}
//			if (nIndex == 0)
//			{
//				g_GMng.m_bNextStage = TRUE;
//			}
//			else
//			{
//				g_GMng.m_bNextStage = FALSE;
//			}
//			if (g_GMng.m_bNextStage)
//			{
//				g_GMng.m_fMoveCamaraTime += D_WORLD->GetDeltaTime();
//
//				if (g_GMng.m_fMoveCamaraTime >= 1.5f)
//				{
//					//m_Hero.m_pAnimation->SetPos(m_Hero.m_pAnimation->GetPosVec2().m_fX, m_Hero.m_pAnimation->GetPosVec2().m_fY);
//					g_GMng.m_fMoveCamaraTime = 0;
//					g_GMng.m_bScroll = TRUE;
//					m_CScore.m_pNum->MoveX(1280.0f);
//					g_GMng.m_nStage++;
//					m_Bullet.m_nStage = g_GMng.m_nStage;
//					//D_CAMERA->MoveX(1280);
//					g_GMng.m_fedX = D_CAMERA->GetPosVec2().m_fX + 1280;
//					CreateMonster(g_GMng.m_nStage);
//				}
//				m_CMap.m_Door[nStage]->SetPause(false);
//			}
//		}
//	}
//}
//void CStage3::GameInfo()
//{
//	Clipping(g_GMng.m_nStage);
//	MoveStage(g_GMng.m_nStage);
//}
//void CStage3::Clipping(int nStage)
//{
//	if (m_Hero.m_pAnimation->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
//	{
//		m_Hero.m_pAnimation->SetPos(m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX + 32, m_Hero.m_pAnimation->GetPosVec2().m_fY);
//	}
//	if (m_Hero.m_pAnimation->GetBoundingBox().stLB.m_fY < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY)
//	{
//		m_Hero.m_pAnimation->SetPos(m_Hero.m_pAnimation->GetPosVec2().m_fX, m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY + 40);
//	}
//	if (m_Hero.m_pAnimation->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
//	{
//		m_Hero.m_pAnimation->SetPos(m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX - 32, m_Hero.m_pAnimation->GetPosVec2().m_fY);
//	}
//	if (m_Hero.m_pAnimation->GetBoundingBox().stRT.m_fY > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY)
//	{
//		m_Hero.m_pAnimation->SetPos(m_Hero.m_pAnimation->GetPosVec2().m_fX, m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY - 40);
//	}
//
//	for (int i = 0; i < D_BULLET_MAX; i++)
//	{
//		if (m_Bullet.m_pAnimation[i]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
//		{
//			m_Bullet.Disable(i);
//		}
//		if (m_Bullet.m_pAnimation[i]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
//		{
//			m_Bullet.Disable(i);
//		}
//	}
//	ClippingEnemy(nStage);
//	m_Hero.m_pArm->SetPos(m_Hero.m_pAnimation->GetPosVec2().m_fX - 20, m_Hero.m_pAnimation->GetPosVec2().m_fY - 10);
//}
//
//void CStage3::ClippingEnemy(int nStage)
//{
//	for (int i = 0; i < D_PE_MAX; i++)
//	{
//		if (m_PE.m_Enemy[i]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
//		{
//			m_PE.stEMNowVec2[i] = stEMVec2(m_PE.m_Enemy[i]->GetPosVec2().m_fX + 50, m_PE.m_Enemy[i]->GetPosVec2().m_fY);
//		}
//		if (m_PE.m_Enemy[i]->GetBoundingBox().stLB.m_fY < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY)
//		{
//			m_PE.stEMNowVec2[i] = stEMVec2(m_PE.m_Enemy[i]->GetPosVec2().m_fX, m_PE.m_Enemy[i]->GetPosVec2().m_fY + 50);
//		}
//		if (m_PE.m_Enemy[i]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
//		{
//			m_PE.stEMNowVec2[i] = stEMVec2(m_PE.m_Enemy[i]->GetPosVec2().m_fX - 50, m_PE.m_Enemy[i]->GetPosVec2().m_fY);
//		}
//		if (m_PE.m_Enemy[i]->GetBoundingBox().stRT.m_fY > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY)
//		{
//			m_PE.stEMNowVec2[i] = stEMVec2(m_PE.m_Enemy[i]->GetPosVec2().m_fX, m_PE.m_Enemy[i]->GetPosVec2().m_fY - 50);
//		}
//
//		if (m_PE.m_Enemy[i]->GetShow())
//		{
//			for (int j = 0; j < D_BULLET_MAX - 20; j++)
//			{
//				if (m_PE.m_CEnyBullet[i].m_pAnimation[j]->GetShow())
//				{
//					if (m_PE.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
//					{
//						m_PE.m_CEnyBullet[i].Disable(j);
//					}
//					if (m_PE.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
//					{
//						m_PE.m_CEnyBullet[i].Disable(j);
//					}
//				}
//			}
//		}
//	}
//	for (int i = 0; i < D_ME_MAX; i++)
//	{
//		if (m_ME.m_Enemy[i]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
//		{
//			m_ME.stEMNowVec2[i] = stEMVec2(m_ME.m_Enemy[i]->GetPosVec2().m_fX + 50, m_ME.m_Enemy[i]->GetPosVec2().m_fY);
//		}
//		if (m_ME.m_Enemy[i]->GetBoundingBox().stLB.m_fY < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY)
//		{
//			m_ME.stEMNowVec2[i] = stEMVec2(m_ME.m_Enemy[i]->GetPosVec2().m_fX, m_ME.m_Enemy[i]->GetPosVec2().m_fY + 50);
//		}
//		if (m_ME.m_Enemy[i]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
//		{
//			m_ME.stEMNowVec2[i] = stEMVec2(m_ME.m_Enemy[i]->GetPosVec2().m_fX - 50, m_ME.m_Enemy[i]->GetPosVec2().m_fY);
//		}
//		if (m_ME.m_Enemy[i]->GetBoundingBox().stRT.m_fY > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY)
//		{
//			m_ME.stEMNowVec2[i] = stEMVec2(m_ME.m_Enemy[i]->GetPosVec2().m_fX, m_ME.m_Enemy[i]->GetPosVec2().m_fY - 50);
//		}
//
//		if (m_ME.m_Enemy[i]->GetShow())
//		{
//			for (int j = 0; j < D_BULLET_MAX - 20; j++)
//			{
//				if (m_ME.m_CEnyBullet[i].m_pAnimation[j]->GetShow())
//				{
//					if (m_ME.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
//					{
//						m_ME.m_CEnyBullet[i].Disable(j);
//					}
//					if (m_ME.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
//					{
//						m_ME.m_CEnyBullet[i].Disable(j);
//					}
//				}
//			}
//		}
//	}	
//	for (int i = 0; i < D_SE_MAX; i++)
//	{
//		if (m_SE.m_Enemy[i]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
//		{
//			m_SE.stEMNowVec2[i] = stEMVec2(m_SE.m_Enemy[i]->GetPosVec2().m_fX + 50, m_SE.m_Enemy[i]->GetPosVec2().m_fY);
//		}
//		if (m_SE.m_Enemy[i]->GetBoundingBox().stLB.m_fY < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fY)
//		{
//			m_SE.stEMNowVec2[i] = stEMVec2(m_SE.m_Enemy[i]->GetPosVec2().m_fX, m_SE.m_Enemy[i]->GetPosVec2().m_fY + 50);
//		}
//		if (m_SE.m_Enemy[i]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
//		{
//			m_SE.stEMNowVec2[i] = stEMVec2(m_SE.m_Enemy[i]->GetPosVec2().m_fX - 50, m_SE.m_Enemy[i]->GetPosVec2().m_fY);
//		}
//		if (m_SE.m_Enemy[i]->GetBoundingBox().stRT.m_fY > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fY)
//		{
//			m_SE.stEMNowVec2[i] = stEMVec2(m_SE.m_Enemy[i]->GetPosVec2().m_fX, m_SE.m_Enemy[i]->GetPosVec2().m_fY - 50);
//		}
//
//		if (m_SE.m_Enemy[i]->GetShow())
//		{
//			for (int j = 0; j < D_BULLET_MAX - 20; j++)
//			{
//				if (m_SE.m_CEnyBullet[i].m_pAnimation[j]->GetShow())
//				{
//					if (m_SE.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stLB.m_fX < m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stLB.m_fX)
//					{
//						m_SE.m_CEnyBullet[i].Disable(j);
//					}
//					if (m_SE.m_CEnyBullet[i].m_pAnimation[j]->GetBoundingBox().stRT.m_fX > m_CMap.m_ClippingHero[nStage]->GetBoundingBox().stRT.m_fX)
//					{
//						m_SE.m_CEnyBullet[i].Disable(j);
//					}
//				}
//			}
//		}
//	}
//
//}
