#include "stdafx.h"

CMiniBoss::CMiniBoss()
{
	m_stHeroDirVec3 = stEMVec3(0.0f, 1.0f, 0.0f);
}
CMiniBoss::~CMiniBoss()
{

}
void CMiniBoss::Update(CEMPlane* m_CMap, CHero* Hero)
{
	if (g_GMng.m_BOSSUse && m_Enemy->GetShow())
	{
		if (g_GMng.m_BOSSHP > 0)
		{
			if (pattern == 1)
			{
				CreateBullet1(Hero);
				CreatEn();

			}
			Move();
			Clipping(m_CMap);
		}
		m_pArm->SetPos(m_Enemy->GetPosVec2().m_fX - 24, m_Enemy->GetPosVec2().m_fY - 0);

		//----------------------------------------------------------------------------------------------------------------------------
		m_stDestPos = stEMVec3(Hero->m_pAnimation->GetPosVec3().m_fX, Hero->m_pAnimation->GetPosVec3().m_fY, 0.0f);

		m_stEnemyPosToDestPosDir = m_stDestPos - m_Enemy->GetPosVec3();

		// 단위벡터로 변경
		m_stEnemyPosToDestPosDir.Normalize();
		m_stHeroDirVec3.Normalize();
		// 내적 계산
		m_fDot = stEMVec3::Dot(m_stHeroDirVec3, m_stEnemyPosToDestPosDir);

		// 각도 구하기^^
		m_fRadian = (float)acos(m_fDot);

		// 주인공의 업벡터 구하기
		m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));

		if (stEMVec3::Dot(m_stHeroRightVec3, m_stEnemyPosToDestPosDir) > 0.0f)
		{
			m_pArm->SetZRot(CEMMath::ToDegrees(m_fRadian) + 90);
			m_pArm->SetMirrorType(E_UP_RIGHT_MIRROR);
			//Dprintf("왼쪽 %f\n", m_fRadian);
		}
		else
		{

			m_pArm->SetZRot(CEMMath::ToDegrees(-m_fRadian) + 90);
			m_pArm->SetMirrorType(E_RIGHT_MIRROR);
			//Dprintf("오른쪽 %f\n", m_fRadian);
		}
		if (m_stDestPos.m_fX > m_Enemy->GetPosVec2().m_fX)
		{
			m_bSide = FALSE;//오른쪽
		}
		else
		{
			m_bSide = TRUE;//왼쪽
		}
		if (g_GMng.m_BOSSHP == 0)
		{
			g_GMng.m_BOSSHP = -1;
			m_Enemy->SetLoopType(E_ANI_LOOP, 4, 14, E_ANI_ENDING_TYPE_SHOW_FALSE);
			if (!m_bSide)
			{
				m_Enemy->SetMirrorType(E_RIGHT_MIRROR);
			}
			m_Enemy->SetTime(0.2f);
		}
		else if (g_GMng.m_BOSSHP == -1 && m_Enemy->GetCurFrameNumber() == 4 || m_Enemy->GetCurFrameNumber() == 6 ||
			m_Enemy->GetCurFrameNumber() ==  8 || m_Enemy->GetCurFrameNumber() == 10 || m_Enemy->GetCurFrameNumber() == 12)
		{
			if (D_MNG->m_bSound)
				D_SOUND->Play(D_MNG->m_SEkSnd[4][1], D_MNG->GetSoundVolume());
		}
		else if (g_GMng.m_BOSSHP == -1 && m_Enemy->GetCurFrameNumber() == 14)
		{
			g_GMng.m_nLiveEny--;
			Disable(0);
			g_GMng.m_nKillScore += 1000;
		}
		m_Fire->SetPos(m_pArm->GetPosVec3() + m_stEnemyPosToDestPosDir * 75);
		//Dprintf("현재 미니보스 프레임 %d", m_Enemy->GetCurFrameNumber());
		m_CEnyBullet.Update(D_WORLD->GetDeltaTime(), 0);

	}
}
void CMiniBoss::Enable(stEMVec2 stCreateVec2)
{
	g_GMng.m_BOSSUse = TRUE;
	pattern = 1;
	UP = TRUE;
	m_Enemy->SetPause(TRUE);
	g_GMng.m_nLiveEny++;
	if (!g_GMng.m_bF5)
	g_GMng.m_BOSSHP = 31;
	else
	g_GMng.m_BOSSHP = 31;
	
	m_Enemy->SetPos(stCreateVec2);
	m_stVec2 = stCreateVec2;
	stEMNowVec2 = stCreateVec2;
	m_Enemy->SetShow(TRUE);
	//g_GMng.m_fMINIBOSSMoveTime[E_BOSS_MOVE_UP] = CEMMath::RandomIntInRange(0, 4);
	g_GMng.m_fMINIBOSSFireTime1 = -4;
	nMove = 0;
	m_fPatternChangeTime = 0;
	m_fCreatEnemyTime = -5;
	m_fUpTime = 0;
	m_bType = FALSE;
}
void CMiniBoss::Disable(int nIndex)
{
	m_Enemy->SetShow(FALSE);
	g_GMng.m_BOSSUse = FALSE;
	m_pArm->SetShow(FALSE);
	for (int i = 0; i < 30; i++)
	{
		m_CEnyBullet.Disable(i);
	}
}
void CMiniBoss::CreateObj(CRootScene* pScene)
{
	g_GMng.m_BOSSUse = FALSE;
	pattern = -1;
	m_Enemy = new CEMAnimation(15);
	m_Enemy->SetTexture(pScene, 15,
		"Data/Image/보스/중 좌 1.png",
		"Data/Image/보스/중 좌 2.png",
		"Data/Image/보스/중 우 1.png",
		"Data/Image/보스/중 우 2.png",
		"Data/Image/보스/중 죽음 1.png",
		"Data/Image/보스/중 죽음 2.png",
		"Data/Image/보스/중 죽음 3.png",
		"Data/Image/보스/중 죽음 4.png",
		"Data/Image/보스/중 죽음 5.png",
		"Data/Image/보스/중 죽음 6.png",
		"Data/Image/보스/중 죽음 7.png",
		"Data/Image/보스/중 죽음 8.png",
		"Data/Image/보스/중 죽음 9.png",
		"Data/Image/보스/중 죽음 10.png",
		"Data/Image/보스/중 죽음 10.png",
		GL_REPEAT, GL_NEAREST);
	m_Enemy->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_Enemy->SetSize(0.55f, 0.55f);
	m_Enemy->SetTime(0.17f);
	m_Enemy->SetPause(TRUE);
	m_Enemy->SetShow(FALSE);
	m_Enemy->SetBlend(TRUE);
	m_Enemy->SetBoundingBoxCalc(TRUE);
	m_Enemy->SetFrstumCullingFlag(FALSE);


	m_pArm = new CEMPlane();
	m_pArm->SetTexture("Data/Image/보스/팔.png", GL_REPEAT, GL_NEAREST);
	m_pArm->SetOffset(+76.5f, 0);
	//m_pArm->SetZRot(-16.0f);
	m_pArm->SetPos(m_Enemy->GetPosVec2().m_fX - 20, m_Enemy->GetPosVec2().m_fY - 10);
	m_pArm->SetSize(0.5f, 0.5f);
	m_pArm->SetBlend(TRUE);
	m_pArm->SetBoundingBoxCalc(FALSE);
	m_pArm->SetFrstumCullingFlag(FALSE);
	stdEMString stTemp = "MINIBOSS";
	pScene->Commit(2, stTemp, m_Enemy);
	stTemp = "MINIBOSSarm";
	pScene->Commit(2, stTemp, m_pArm);
	//g_GMng.m_fSEMoveTime = CEMMath::RandomIntInRange(0, 4);
	//g_GMng.m_fSEFireTime = CEMMath::RandomIntInRange(-4, 0);

	m_CEnyBullet.CreateObj(pScene, "MINIBOSSBullet", 00, 3, 4);
	m_pScene = pScene;
	m_Fire = new CEMPlane();
	m_Fire->SetOffset(0, 0);
	//m_pArm->SetZRot(-16.0f);
	m_Fire->SetSize(0.5f, 0.5f);
	m_Fire->SetAlpha(0);
	m_Fire->SetBlend(TRUE);
	m_Fire->SetBoundingBoxCalc(FALSE);
	m_Fire->SetFrstumCullingFlag(FALSE);
	stTemp = "MINIBOSSFIREPOS";
	pScene->Commit(2, stTemp, m_Fire);
	
}

void CMiniBoss::Move()
{
	g_GMng.m_fMINIBOSSMoveTime += D_WORLD->GetDeltaTime();
	if (g_GMng.m_fMINIBOSSMoveTime >= 5)
	{
		g_GMng.m_fMINIBOSSMoveTime = CEMMath::RandomIntInRange(0, 4);
		//m_stVec2 = m_Enemy->GetPosVec2();
		stEMNowVec2 = stEMVec2(CEMMath::RandomIntInRange(m_Enemy->GetPosVec2().m_fX - 200, m_Enemy->GetPosVec2().m_fX + 200),
			CEMMath::RandomIntInRange(m_Enemy->GetPosVec2().m_fY - 200, m_Enemy->GetPosVec2().m_fY + 200));
		g_GMng.m_bMINIBOSSMove = TRUE;
	}
	stEMVec2 Vec2_2 = CEMMath::Lerp(m_Enemy->GetPosVec2(), stEMNowVec2, D_WORLD->GetDeltaTime() * 2.0f);
	//m_Enemy->Move(0.01f, stEMVec3(stEMNowVec2.m_fX, stEMNowVec2.m_fY, 0));
	m_Enemy->SetPos(Vec2_2);
	if (Vec2_2.m_fX == m_Enemy->GetPosVec2().m_fX &&
		Vec2_2.m_fY == m_Enemy->GetPosVec2().m_fY)
	{
		if (!m_bSide)
		{
			m_Enemy->SetLoopType(E_ANI_LOOP, 2, 2);
		}
		else
		{
			m_Enemy->SetLoopType(E_ANI_LOOP, 0, 0);
		}
		g_GMng.m_bMINIBOSSMove = FALSE;
		g_GMng.m_bMINIBOSSMoveFrame = FALSE;
	}

	if (g_GMng.m_bMINIBOSSMove == TRUE)
	{
		if (m_bSide)
		{
			if (m_Enemy->GetCurFrameNumber() == 0 && g_GMng.m_bMINIBOSSMoveFrame == FALSE)
			{
				m_Enemy->SetLoopType(E_ANI_LOOP, 2, 3);
				g_GMng.m_bMINIBOSSMoveFrame = TRUE;
			}
		}
		else
		{
			if (m_Enemy->GetCurFrameNumber() == 0 && g_GMng.m_bMINIBOSSMoveFrame == FALSE)
			{
				m_Enemy->SetLoopType(E_ANI_LOOP, 0, 1);
				g_GMng.m_bMINIBOSSMoveFrame = TRUE;
			}

		}
	}
	CEMAnimation* m_pCurAni2 = NULL;
	m_pCurAni2 = (CEMAnimation*)m_pScene->IsCollision(E_SPHERE_VS_SPHERE, (CEMAnimation*)m_Enemy, -1);
	if (m_pCurAni2 != NULL)
	{
		//D_SOUND->Play(m_DieMonster, 0.5f);
		//m_Effect.Enable(m_pAnimation->GetPosVec3(), m_pAnimation->GetPosVec3().m_fX - 50, 0);
		if (m_pCurAni2->GetCurFrameNumber() == 0)
		{
			for (int i = 0; i < D_BULLET_MAX; i++)
			{
				if (m_pCurAni2 == g_GMng.NowScene->Find(stdEMString("HeroBullet" + IntToEMString(i))))
				{
					NowI = i;
				}
			}
			if (g_GMng.m_nPlayAni[NowI] == 0)
			{
				g_GMng.m_stClickDestPos[NowI] = 0;
				g_GMng.m_nPlayAni[NowI] = 1;
				g_GMng.m_stClickDestPos[NowI] = stEMVec3(0.0f, 0.0f, 0.0f);
				g_GMng.m_BOSSHP--;
				m_pCurAni2->SetPause(FALSE);
				g_GMng.m_nScore += 50;
			}
		}
	}
}
void CMiniBoss::Clipping(CEMPlane* m_CMap)
{
	if (m_Enemy->GetBoundingBox().stLB.m_fX < m_CMap->GetBoundingBox().stLB.m_fX)
	{
		m_stVec2 = stEMVec2(m_Enemy->GetPosVec2().m_fX + CEMMath::RandomIntInRange(10, 50), m_Enemy->GetPosVec2().m_fY);

	}
	else if (m_Enemy->GetBoundingBox().stLB.m_fY < m_CMap->GetBoundingBox().stLB.m_fY)
	{
		m_stVec2 = stEMVec2(m_Enemy->GetPosVec2().m_fX, m_Enemy->GetPosVec2().m_fY + CEMMath::RandomIntInRange(10, 50));
	}
	else if (m_Enemy->GetBoundingBox().stRT.m_fX > m_CMap->GetBoundingBox().stRT.m_fX)
	{
		m_stVec2 = stEMVec2(m_Enemy->GetPosVec2().m_fX - CEMMath::RandomIntInRange(10, 50), m_Enemy->GetPosVec2().m_fY);
	}
	else if (m_Enemy->GetBoundingBox().stRT.m_fY > m_CMap->GetBoundingBox().stRT.m_fY)
	{
		m_stVec2 = stEMVec2(m_Enemy->GetPosVec2().m_fX, m_Enemy->GetPosVec2().m_fY - CEMMath::RandomIntInRange(10, 50));
	}
}
void CMiniBoss::CreatEn()
{
}
void CMiniBoss::CreateBullet1(CHero * Hero)
{
	g_GMng.m_fMINIBOSSFireTime1 += D_WORLD->GetDeltaTime();
	if (g_GMng.m_fMINIBOSSFireTime1 >= 1.0f)
	{
		g_GMng.m_fMINIBOSSFireTime1 = CEMMath::RandomFloatInRange(-1.0, -0.5);

		float Ladian = stEMVec3::Dot(m_stHeroRightVec3, m_stEnemyPosToDestPosDir);
		if (Ladian > 0.9)
		{
			BulletFire(-300, -300, -300, -300, -300,
				100, 0.0f, -100.0f, 200, -200);
		}
		else if (Ladian < -0.9)
		{
			BulletFire(300, 300, 300, 300, 300,
				100, 0, -100, 200, -200);
		}


		else if (Ladian > 0.8f && Ladian < 0.9f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(-300.0f, -300.0f, -300.0f, -300.0f, -300.0f,
				300.0f, 200.0f, 100.0f, 400, 00);
		}
		else if (Ladian > 0.8f && Ladian < 0.9f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(-300.0f, -300.0f, -300.0f, -300.0f, -300.0f,
				-300.0f, -200.0f, -100.0f, -400, 00);
		}
		else if (Ladian < -0.8f && Ladian > -0.9f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(300.0f, 300.0f, 300.0f, 300.0f, 300.0f,
				300.0f, 200.0f, 100.0f, 400, 00);
		}
		else if (Ladian < -0.8f && Ladian > -0.9f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(300.0f, 300.0f, 300.0f, 300.0f, 300.0f,
				-300.0f, -200.0f, -100.0f, -400, 00);
		}



		else if (Ladian > 0.7f && Ladian < 0.8f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(-300.0f, -300.0f, -300.0f, -300, -300,
				600.0f, 300.0f, 100.0f, 800, -100);
		}
		else if (Ladian > 0.7f && Ladian < 0.8f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(-300.0f, -300.0f, -300.0f, -300, -300,
				-600.0f, -300.0f, -100.0f, -800, 100);
		}
		else if (Ladian < -0.7f && Ladian > -0.8f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(300.0f, 300.0f, 300.0f, 300.0f, 300.0f,
				600.0f, 300.0f, 100.0f, 800, -100);
		}
		else if (Ladian < -0.7f && Ladian > -0.8f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(300.0f, 300.0f, 300.0f, 300.0f, 300.0f,
				-600.0f, -300.0f, -100.0f, -800, 100);
		}



		else if (Ladian > 0.6f && Ladian < 0.7f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(-100.0f, -100.0f, -100.0f, -100.0f, -100.0f,
				500.0f, 100.0f, 25.0f, 550, -25);
		}
		else if (Ladian > 0.6f && Ladian < 0.7f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(-100.0f, -100.0f, -100.0f, -100.0f, -100.0f,
				-500.0f, -100.0f, -25.0f, -550, 25);
		}
		else if (Ladian < -0.6f && Ladian > -0.7f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(100.0f, 100.0f, 100.0f, 100.0f, 100.0f,
				500.0f, 100.0f, 25.0f, 550, -25);
		}
		else if (Ladian < -0.6f && Ladian > -0.7f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(100.0f, 100.0f, 100.0f, 100.0f, 100.0f,
				-500.0f, -100.0f, -25.0f, -550, 25);
		}



		else if (Ladian > 0.5f && Ladian < 0.6f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(-100.0f, -100.0f, -100.0f, 80.0f, -100.0f,
				200.0f, 700.0f, 50.0f, 1000, 100);
		}
		else if (Ladian > 0.5f && Ladian < 0.6f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(-100.0f, -100.0f, -100.0f, 100.0f, -100.0f,
				-200.0f, -700.0f, -100.0f, -500, -50);
		}
		else if (Ladian < -0.5f && Ladian > -0.6f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(100.0f, 100.0f, 100.0f, 100.0f, 100.0f,
				300.0f, 700.0f, 50.0f, 1000, 100);
		}
		else if (Ladian < -0.5f && Ladian > -0.6f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(100.0f, 100.0f, 100.0f, -100.0f, 100.0f,
				-200.0f, -700.0f, -100.0f, -500, -50);
		}



		else if (Ladian > 0.4f && Ladian < 0.5f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(-100.0f, -100.0f, -100.0f, 150.0f, -100.0f,
				200.0f, 700.0f, 90.0f, 600, 130);
		}
		else if (Ladian > 0.4f && Ladian < 0.5f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(-100.0f, -100.0f, -100.0f, 150.0f, -100.0f,
				-200.0f, -700.0f, -90.0f, -600, -130);
		}
		else if (Ladian < -0.4f && Ladian > -0.5f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(100.0f, 100.0f, 100.0f, -150.0f, 100.0f,
				200.0f, 700.0f, 90.0f, 600, 130);
		}
		else if (Ladian < -0.4f && Ladian > -0.5f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(100.0f, 100.0f, 100.0f, -150.0f, 100.0f,
				-200.0f, -700.0f, -90.0f, -600, -130);
		}



		else if (Ladian > 0.3f && Ladian < 0.4f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(100.0f, -100.0f, -100.0f, 100.0f, -100.0f,
				1000.0f, 300.0f, 150.0f, 300, 100);
		}
		else if (Ladian > 0.3f && Ladian < 0.4f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(100.0f, -100.0f, -100.0f, 100.0f, -100.0f,
				-1000.0f, -300.0f, -150.0f, -300, -100);
		}
		else if (Ladian < -0.3f && Ladian > -0.4f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(-100.0f, 100.0f, 100.0f, -100.0f, 100.0f,
				1000.0f, 300.0f, 150.0f, 300, 100);
		}
		else if (Ladian < -0.3f && Ladian > -0.4f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(-100.0f, 100.0f, 100.0f, -100.0f, 100.0f,
				-1000.0f, -300.0f, -150.0f, -300, -100);
		}



		else if (Ladian > 0.2f && Ladian < 0.3f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(100.0f, -100.0f, -100.0f, 100.0f, -100.0f,
				600.0f, 600.0f, 200.0f, 250, 100);
		}
		else if (Ladian > 0.2f && Ladian < 0.3f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(100.0f, -100.0f, -100.0f, 100.0f, -100.0f,
				-600.0f, -600.0f, -200.0f, -250, -100);
		}
		else if (Ladian < -0.2f && Ladian > -0.3f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(-100.0f, 100.0f, 100.0f, -100.0f, 100.0f,
				600.0f, 600.0f, 200.0f, 250, 100);
		}
		else if (Ladian < -0.2f && Ladian > -0.3f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(-100.0f, 100.0f, 100.0f, -100.0f, 100.0f,
				-600.0f, -600.0f, -200.0f, -250, -100);
		}



		else if (Ladian > 0.1f && Ladian < 0.2f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(100.0f, -100.0f, -100.0f, 100.0f, -100.0f,
				400.0f, 800.0f, 200.0f, 200, 130);
		}
		else if (Ladian > 0.1f && Ladian < 0.2f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(100.0f, -100.0f, -100.0f, 100.0f, -100.0f,
				-350.0f, -350.0f, -150.0f, -500, 0);
		}
		else if (Ladian < -0.1f && Ladian > -0.2f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(-100.0f, 100.0f, 100.0f, -100.0f, 100.0f,
				350.0f, 350.0f, 150.0f, 500, 0);
		}
		else if (Ladian < -0.1f && Ladian > -0.2f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(-100.0f, 100.0f, 100.0f, -100.0f, 100.0f,
				-350.0f, -350.0f, -150, -500, 100);
		}



		else if (Ladian > 0.0f && Ladian < 0.1f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(100.0f, 100.0f, -100.0f, 100.0f, -100.0f,
				300.0f, 900.0f, 250.0f, 150, 150);
		}
		else if (Ladian > 0.0f && Ladian < 0.1f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(100.0f, 100.0f, -100.0f, 100.0f, -100.0f,
				-300.0f, -900.0f, -250.0f, -150, -150);
		}
		else if (Ladian < -0.0f && Ladian > -0.1f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY > 0)
		{
			BulletFire(-100.0f, -100.0f, 100.0f, -100.0f, 100.0f,
				300.0f, 900.0f, 250.0f, 150, 150);
		}
		else if (Ladian < -0.0f && Ladian > -0.1f && Hero->m_pAnimation->GetPosVec3().m_fY - m_pArm->GetPosVec2().m_fY < 0)
		{
			BulletFire(-100.0f, -100.0f, 100.0f, -100.0f, 100.0f,
				-300.0f, -900.0f, -250.0f, -150, -150);
		}
	}
}


void CMiniBoss::BulletFire(float x1, float x2, float x3, float x4, float x5, float y1, float y2, float y3, float y4, float y5)
{
	int nTemp = 0;
	for (int j = 0; j < D_EBULLET_MAX; j++)
	{
		if (nTemp < 5)
		{
			if (m_CEnyBullet.m_pAnimation[j]->GetShow() == FALSE)
			{
				switch (nTemp)
				{
				case 0:
					m_CEnyBullet.Enable(j, m_Fire->GetPosVec3(),
						stEMVec3(m_pArm->GetPosVec3().m_fX + x1, m_pArm->GetPosVec3().m_fY + y1, m_pArm->GetPosVec3().m_fZ), g_GMng.m_nStage);
					break;
				case 1:
					m_CEnyBullet.Enable(j, m_Fire->GetPosVec3(),
						stEMVec3(m_pArm->GetPosVec3().m_fX + x2, m_pArm->GetPosVec3().m_fY + y2, m_pArm->GetPosVec3().m_fZ), g_GMng.m_nStage);
					break;
				case 2:
					m_CEnyBullet.Enable(j, m_Fire->GetPosVec3(),
						stEMVec3(m_pArm->GetPosVec3().m_fX + x3, m_pArm->GetPosVec3().m_fY + y3, m_pArm->GetPosVec3().m_fZ), g_GMng.m_nStage);
					break;
				case 3:
					m_CEnyBullet.Enable(j, m_Fire->GetPosVec3(),
						stEMVec3(m_pArm->GetPosVec3().m_fX + x4, m_pArm->GetPosVec3().m_fY + y4, m_pArm->GetPosVec3().m_fZ), g_GMng.m_nStage);
					break;
				case 4:
					m_CEnyBullet.Enable(j, m_Fire->GetPosVec3(),
						stEMVec3(m_pArm->GetPosVec3().m_fX + x5, m_pArm->GetPosVec3().m_fY + y5, m_pArm->GetPosVec3().m_fZ), g_GMng.m_nStage);
					break;
				default:
					break;
				}
				nTemp++;
			}
		}
		else
		{
			if (!D_SOUND->IsPlaying(D_MNG->m_SEkSnd[4][0]) && D_MNG->m_bSound)
				D_SOUND->Play(D_MNG->m_SEkSnd[4][0], D_MNG->GetSoundVolume());
			break;
		}
	}
}