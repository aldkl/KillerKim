#include "stdafx.h"

CMachinegunEnemy::CMachinegunEnemy()
{
	for (int i = 0; i < D_ME_MAX; i++)
	{
		m_stHeroDirVec3[i] = stEMVec3(0.0f, 1.0f, 0.0f);
		g_GMng.m_bMEMove[i] = FALSE;
		g_GMng.m_bMEMoveFrame[i] = FALSE;
		g_GMng.m_bMEDOWNTime[i] = FALSE;
		//m_bHit[i] = FALSE;
		g_GMng.m_fMEHitTime[i] = 0;
	}
}
CMachinegunEnemy::~CMachinegunEnemy()
{

}

void CMachinegunEnemy::Update(CEMPlane* m_CMap, CHero* Hero)
{
	for (int i = 0; i < D_ME_MAX; i++)
	{
		if (m_Enemy[i]->GetShow() && !m_DownEnemy[i]->GetShow() && g_GMng.m_MEHP[i] >= 0 && !m_bFall[i])
		{
			if (m_bHit[i])
			{
				if (m_bSide[i])
				{
					if (m_Enemy[i]->GetCurFrameNumber() != 4)
					{
						stEMNowVec2[i] = stEMVec2(m_Enemy[i]->GetPosVec2().m_fX + 30, m_Enemy[i]->GetPosVec2().m_fY);
					}
					stEMVec2 stVec2 = CEMMath::Lerp(m_Enemy[i]->GetPosVec2(), stEMNowVec2[i], D_WORLD->GetDeltaTime() * 2.0f);
					m_Enemy[i]->SetLoopType(E_ANI_LOOP, 4, 4);
					m_Enemy[i]->SetPos(stVec2);
				}
				else
				{
					if (m_Enemy[i]->GetCurFrameNumber() != 5)
					{
						stEMNowVec2[i] = stEMVec2(m_Enemy[i]->GetPosVec2().m_fX - 30, m_Enemy[i]->GetPosVec2().m_fY);
					}
					stEMVec2 stVec2 = CEMMath::Lerp(m_Enemy[i]->GetPosVec2(), stEMNowVec2[i], D_WORLD->GetDeltaTime() * 2.0f);
					m_Enemy[i]->SetLoopType(E_ANI_LOOP, 5, 5);
					m_Enemy[i]->SetPos(stVec2);
				}
				g_GMng.m_fMEHitTime[i] += D_WORLD->GetDeltaTime();
				if (g_GMng.m_fMEHitTime[i] >= 1)
				{
					g_GMng.m_fMEHitTime[i] = 0;
					m_bHit[i] = FALSE;
				}
				//m_Enemy[i]->Move(0.01f, stEMVec3(stEMNowVec2[i].m_fX, stEMNowVec2[i].m_fY, 0));

			}
			else
			{
				Move(i);
				CreateBullet(i, Hero);
				if (m_bSide[i])
				{
					if (m_Enemy[i]->GetCurFrameNumber() != 0 && m_Enemy[i]->GetCurFrameNumber() != 1)
						m_Enemy[i]->SetLoopType(E_ANI_LOOP, 0, 1);
				}
				else
				{
					if (m_Enemy[i]->GetCurFrameNumber() != 2 && m_Enemy[i]->GetCurFrameNumber() != 3)
						m_Enemy[i]->SetLoopType(E_ANI_LOOP, 2, 3);
				}
			}
			if (m_Enemy[i]->GetCurFrameNumber() == 1)
			{
				m_Enemy[i]->GetShow();
			}
			Clipping(i, m_CMap);
			m_pArm[i]->SetPos(m_Enemy[i]->GetPosVec2().m_fX - 17, m_Enemy[i]->GetPosVec2().m_fY - 00);

			//----------------------------------------------------------------------------------------------------------------------------
			m_stDestPos[i] = stEMVec3(Hero->m_pAnimation->GetPosVec3().m_fX, Hero->m_pAnimation->GetPosVec3().m_fY, 0.0f);

			m_stEnemyPosToDestPosDir[i] = m_stDestPos[i] - m_Enemy[i]->GetPosVec3();

			// 단위벡터로 변경
			m_stEnemyPosToDestPosDir[i].Normalize();
			m_stHeroDirVec3[i].Normalize();

			// 내적 계산
			m_fDot[i] = stEMVec3::Dot(m_stHeroDirVec3[i], m_stEnemyPosToDestPosDir[i]);

			// 각도 구하기^^
			m_fRadian[i] = (float)acos(m_fDot[i]);

			// 주인공의 업벡터 구하기
			m_stHeroRightVec3[i] = m_stHeroDirVec3[i].Cross(stEMVec3(0.0f, 0.0f, -1.0f));

			if (stEMVec3::Dot(m_stHeroRightVec3[i], m_stEnemyPosToDestPosDir[i]) > 0.0f)
			{
				m_pArm[i]->SetZRot(CEMMath::ToDegrees(m_fRadian[i]) + 90);
				m_pArm[i]->SetMirrorType(E_UP_RIGHT_MIRROR);
				//Dprintf("왼쪽 %f\n", m_fRadian);
			}
			else
			{
				m_pArm[i]->SetZRot(CEMMath::ToDegrees(-m_fRadian[i]) + 90);
				m_pArm[i]->SetMirrorType(E_RIGHT_MIRROR);
				//Dprintf("오른쪽 %f\n", m_fRadian);
			}
			if (m_stDestPos[i].m_fX > m_Enemy[i]->GetPosVec2().m_fX)
			{
				m_bSide[i] = FALSE;
			}
			else
			{
				m_bSide[i] = TRUE;
			}
			if (g_GMng.m_MEHP[i] == 0)
			{
				g_GMng.m_MEHP[i] = -1;
				m_Enemy[i]->SetLoopType(E_ANI_LOOP, 6, 9, E_ANI_ENDING_TYPE_SHOW_FALSE);
				m_Enemy[i]->SetTime(0.2f);
				m_pArm[i]->SetShow(FALSE);
			}
		}
		else if (g_GMng.m_MEHP[i] == -1 && m_Enemy[i]->GetCurFrameNumber() == 6)
		{
		if (!D_SOUND->IsPlaying(D_MNG->m_PEkSnd[i][1]) && D_MNG->m_bSound)
			D_SOUND->Play(D_MNG->m_PEkSnd[i][1], D_MNG->GetSoundVolume());
		}
		else if (g_GMng.m_MEHP[i] == -1 && m_Enemy[i]->GetCurFrameNumber() == 9)
		{
			g_GMng.m_nLiveEny--;
			Disable(i);
			g_GMng.m_nKillScore += 300;
			Dprintf("현 몬스터 남은수 %d", g_GMng.m_nLiveEny);

		}
		if (m_DownEnemy[i]->GetShow() && !m_Enemy[i]->GetShow() && m_bFall[i])
		{
			g_GMng.m_bMEDOWNTime[i] += D_WORLD->GetDeltaTime();
			if (g_GMng.m_bMEDOWNTime[i] >= 1.0f)
			{
				g_GMng.m_bMEDOWNTime[i] = -100;
				m_DownEnemy[i]->SetPause(FALSE);
				m_pArm[i]->SetPos(-100, -1000);
			}
			if (m_DownEnemy[i]->GetCurFrameNumber() == 2)
			{
				m_DownEnemyEFT[i]->SetShow(TRUE);
				m_DownEnemyEFT[i]->SetPause(FALSE);
			}
			if (m_DownEnemy[i]->GetCurFrameNumber() == 4)
			{
				m_DownEnemy[i]->SetShow(FALSE);
				m_Enemy[i]->SetShow(TRUE);
				m_DownEnemyEFT[i]->SetShow(FALSE);
				m_DownEnemyEFT[i]->SetPause(TRUE);
				m_bFall[i] = FALSE;
			}
		}
		m_Fire[i]->SetPos(m_pArm[i]->GetPosVec3() + m_stEnemyPosToDestPosDir[i] * 75);
		m_CEnyBullet[i].Update(D_WORLD->GetDeltaTime(), 0);
	}
}
void CMachinegunEnemy::Enable(int nIndex, stEMVec2 stCreateVec2,bool Fall)
{
	m_Enemy[nIndex]->SetLoopType(E_ANI_LOOP, 0, 1);

	if (Fall)
	{
		m_DownEnemy[nIndex]->SetPause(TRUE);
		m_DownEnemy[nIndex]->SetShow(TRUE);
		m_Enemy[nIndex]->SetShow(FALSE);
		m_DownEnemy[nIndex]->SetPos(stCreateVec2);
		m_DownEnemyEFT[nIndex]->SetPause(TRUE);
		m_DownEnemyEFT[nIndex]->SetPos(stCreateVec2.m_fX, stCreateVec2.m_fY - 10);
		g_GMng.m_bMEDOWNTime[nIndex] = 0;
	}
	else
	{
		m_Enemy[nIndex]->SetShow(TRUE);
	}
	g_GMng.m_nLiveEny++;
	if(!g_GMng.m_bF5)
		g_GMng.m_MEHP[nIndex] = 2;
	else
		g_GMng.m_MEHP[nIndex] = 1;
	m_Enemy[nIndex]->SetPos(stCreateVec2);
	m_stVec2[nIndex] = stCreateVec2;
	stEMNowVec2[nIndex] = stCreateVec2;
	m_pArm[nIndex]->SetShow(TRUE);
	g_GMng.m_fMEMoveTime[nIndex] = CEMMath::RandomIntInRange(0, 4);
	g_GMng.m_fMEFireTime[nIndex] = -4;
	m_bHit[nIndex] = FALSE;
	m_bFall[nIndex] = Fall;
}
void CMachinegunEnemy::Disable(int nIndex)
{
	m_Enemy[nIndex]->SetShow(FALSE);
	//for (int i = 0; i < D_BULLET_MAX - 20; i++)
	//{
	//	m_CEnyBullet[nIndex].Disable(i);
	//
	//}
	m_DownEnemy[nIndex]->SetPause(TRUE);
	m_DownEnemy[nIndex]->SetShow(TRUE);
	g_GMng.m_MEHP[nIndex] = 2;
	m_DownEnemy[nIndex]->SetPos(-1000,-1000);
	
}
void CMachinegunEnemy::CreateObj(CRootScene* pScene)
{
	for (int i = 0; i < D_ME_MAX; i++)
	{
		m_Enemy[i] = new CEMAnimation(10);
		m_Enemy[i]->SetTexture(pScene, 10,
			"Data/Image/적 애니메이션/망 좌 1.png",
			"Data/Image/적 애니메이션/망 좌 2.png",
			"Data/Image/적 애니메이션/망 우 1.png",
			"Data/Image/적 애니메이션/망 우 2.png",
			"Data/Image/적 애니메이션/피격 망 좌.png",//4
			"Data/Image/적 애니메이션/피격 망 우.png",//5
			"Data/Image/적 애니메이션/망.png",
			"Data/Image/적 애니메이션/죽음 2.png",
			"Data/Image/적 애니메이션/죽음 3.png",
			"Data/Image/적 애니메이션/죽음 3.png",
			GL_REPEAT, GL_NEAREST);
		m_Enemy[i]->SetPos(-1000.0f, -1000.0f, 0.0f);
		m_Enemy[i]->SetSize(0.46f, 0.40f);
		m_Enemy[i]->SetLoopType(E_ANI_LOOP, 0, 0);
		m_Enemy[i]->SetPause(TRUE);
		m_Enemy[i]->SetBlend(TRUE);
		m_Enemy[i]->SetBoundingBoxCalc(TRUE);
		m_Enemy[i]->SetFrstumCullingFlag(FALSE);
		m_Enemy[i]->SetTime(0.2f);
		m_Enemy[i]->SetShow(FALSE);

		m_DownEnemy[i] = new CEMAnimation(5);
		m_DownEnemy[i]->SetTexture(pScene, 5,
			"Data/Image/적 애니메이션/그림자.png",
			"Data/Image/적 애니메이션/그림자.png",
			"Data/Image/적 애니메이션/엎어짐 망.png",
			"Data/Image/적 애니메이션/엎어짐 망.png",
			"Data/Image/적 애니메이션/엎어짐 망.png",
			GL_REPEAT, GL_NEAREST);
		m_DownEnemy[i]->SetPos(-1000.0f, -1000.0f, 0.0f);
		m_DownEnemy[i]->SetSize(0.46f, 0.40f);
		m_DownEnemy[i]->SetBlend(TRUE);
		m_DownEnemy[i]->SetBoundingBoxCalc(TRUE);
		m_DownEnemy[i]->SetFrstumCullingFlag(FALSE);
		m_DownEnemy[i]->SetTime(0.2f);
		m_DownEnemy[i]->SetShow(FALSE);

		m_DownEnemyEFT[i] = new CEMAnimation(2);
		m_DownEnemyEFT[i]->SetTexture(pScene, 2,
			"Data/Image/적 애니메이션/적 출현 1.png",
			"Data/Image/적 애니메이션/적 출현 2.png",
			GL_REPEAT, GL_NEAREST);
		m_DownEnemyEFT[i]->SetPos(-1000.0f, -1000.0f, 0.0f);
		m_DownEnemyEFT[i]->SetSize(0.46f, 0.40f);
		m_DownEnemyEFT[i]->SetBlend(TRUE);
		m_DownEnemyEFT[i]->SetBoundingBoxCalc(TRUE);
		m_DownEnemyEFT[i]->SetFrstumCullingFlag(FALSE);
		m_DownEnemyEFT[i]->SetTime(0.2f);
		m_DownEnemyEFT[i]->SetShow(FALSE);

		m_pArm[i] = new CEMPlane();
		m_pArm[i]->SetTexture("Data/Image/적 애니메이션/연사.png", GL_REPEAT, GL_NEAREST);
		m_pArm[i]->SetOffset(+69.5f, 0);
		//m_pA[i]rm->SetZRot(-16.0f);
		m_pArm[i]->SetPos(m_Enemy[i]->GetPosVec2().m_fX - 20, m_Enemy[i]->GetPosVec2().m_fY - 10);
		m_pArm[i]->SetSize(0.5f, 0.5f);
		m_pArm[i]->SetBlend(TRUE);
		m_pArm[i]->SetBoundingBoxCalc(FALSE);
		m_pArm[i]->SetFrstumCullingFlag(FALSE);
		stdEMString stTemp = "ME" + IntToEMString(i);
		pScene->Commit(2, stTemp, m_Enemy[i]);
		stTemp = "MEDOWN" + IntToEMString(i);
		pScene->Commit(2, stTemp, m_DownEnemy[i]);
		stTemp = "MEDOWNEFT" + IntToEMString(i);
		pScene->Commit(2, stTemp, m_DownEnemyEFT[i]);
		stTemp = "ME_arm" + IntToEMString(i);
		pScene->Commit(2, stTemp, m_pArm[i]);
		g_GMng.m_fMEMoveTime[i] = CEMMath::RandomIntInRange(0, 4);
		g_GMng.m_fMEFireTime[i] = -2;

		m_CEnyBullet[i].CreateObj(pScene, "MEBullet" + IntToEMString(i), 10, 3,2);
		m_pScene = pScene;
		m_Fire[i] = new CEMPlane();
		m_Fire[i]->SetOffset(0, 0);
		//m_pArm->SetZRot(-16.0f);
		m_Fire[i]->SetSize(0.5f, 0.5f);
		m_Fire[i]->SetAlpha(0);
		m_Fire[i]->SetBlend(TRUE);
		m_Fire[i]->SetBoundingBoxCalc(FALSE);
		m_Fire[i]->SetFrstumCullingFlag(FALSE);
		stTemp = "MEFIREPOS";
		pScene->Commit(2, stTemp, m_Fire[i]);
	}
}


void CMachinegunEnemy::Move(int i)
{
	g_GMng.m_fMEMoveTime[i] += D_WORLD->GetDeltaTime();
	if (g_GMng.m_fMEMoveTime[i] >= 5)
	{
		g_GMng.m_fMEMoveTime[i] = CEMMath::RandomIntInRange(0, 4);
		//m_stVec2[i] = m_Enemy[i]->GetPosVec2();
		stEMNowVec2[i] = stEMVec2(CEMMath::RandomIntInRange(m_Enemy[i]->GetPosVec2().m_fX - 200, m_Enemy[i]->GetPosVec2().m_fX + 200),
			CEMMath::RandomIntInRange(m_Enemy[i]->GetPosVec2().m_fY - 200, m_Enemy[i]->GetPosVec2().m_fY + 200));
		g_GMng.m_bMEMove[i] = TRUE;
	}
	stEMVec2 Vec2_2 = CEMMath::SmoothStep(m_Enemy[i]->GetPosVec2(), stEMNowVec2[i], D_WORLD->GetDeltaTime() * 4.0f);
	//stEMVec3 Vec2_2 = stEMVec3(stEMNowVec2[i].m_fX, stEMNowVec2[i].m_fY, 0);
	//m_Enemy[i]->Move(0.01f, Vec2_2);
	m_Enemy[i]->SetPos(Vec2_2);

	CEMAnimation* m_pCurAni2 = NULL;
	m_pCurAni2 = (CEMAnimation*)m_pScene->IsCollision(E_SPHERE_VS_SPHERE, (CEMAnimation*)m_Enemy[i], -1);
	if (m_pCurAni2 != NULL)
	{
		//D_SOUND->Play(m_DieMonster[i], 0.5f);
		//m_Effect[i].Enable(m_pAnimation[i]->GetPosVec3(), m_pAnimation[i]->GetPosVec3().m_fX - 50, 0);
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
				g_GMng.m_MEHP[i]--;
				m_bHit[i] = TRUE;
				m_pCurAni2->SetPause(FALSE);
				g_GMng.m_nScore += 50;
			}
		}
	}
}

void CMachinegunEnemy::Clipping(int i, CEMPlane* m_CMap)
{
	if (m_Enemy[i]->GetBoundingBox().stLB.m_fX < m_CMap->GetBoundingBox().stLB.m_fX)
	{
		m_stVec2[i] = stEMVec2(m_Enemy[i]->GetPosVec2().m_fX + CEMMath::RandomIntInRange(10, 50), m_Enemy[i]->GetPosVec2().m_fY);

	}
	else if (m_Enemy[i]->GetBoundingBox().stLB.m_fY < m_CMap->GetBoundingBox().stLB.m_fY)
	{
		m_stVec2[i] = stEMVec2(m_Enemy[i]->GetPosVec2().m_fX, m_Enemy[i]->GetPosVec2().m_fY + CEMMath::RandomIntInRange(10, 50));
	}
	else if (m_Enemy[i]->GetBoundingBox().stRT.m_fX > m_CMap->GetBoundingBox().stRT.m_fX)
	{
		m_stVec2[i] = stEMVec2(m_Enemy[i]->GetPosVec2().m_fX - CEMMath::RandomIntInRange(10, 50), m_Enemy[i]->GetPosVec2().m_fY);
	}
	else if (m_Enemy[i]->GetBoundingBox().stRT.m_fY > m_CMap->GetBoundingBox().stRT.m_fY)
	{
		m_stVec2[i] = stEMVec2(m_Enemy[i]->GetPosVec2().m_fX, m_Enemy[i]->GetPosVec2().m_fY - CEMMath::RandomIntInRange(10, 50));
	}
}

void CMachinegunEnemy::CreateBullet(int i, CHero* Hero)
{
	g_GMng.m_fMEFireTime[i] += D_WORLD->GetDeltaTime();
	if (g_GMng.m_fMEFireTime[i] >= 0.5f)
	{
		g_GMng.m_fMEFireTime[i] = 0;
			//CEMMath::RandomIntInRange(-2, 0);
		for (int j = 0; j < D_BULLET_MAX - 10; j++)
		{
			if (m_CEnyBullet[i].m_pAnimation[j]->GetShow() == FALSE)
			{
				if (Hero->m_pAnimation->GetPosVec3().m_fX - m_CEnyBullet[i].m_pAnimation[j]->GetPosVec2().m_fX > -30 &&
					Hero->m_pAnimation->GetPosVec3().m_fX - m_CEnyBullet[i].m_pAnimation[j]->GetPosVec2().m_fX < 30)
				{
					m_CEnyBullet[i].Enable(j, m_pArm[i]->GetPosVec3(), stEMVec3(Hero->m_pAnimation->GetPosVec3().m_fX, Hero->m_pAnimation->GetPosVec3().m_fY + CEMMath::RandomFloatInRange(-100, 100), Hero->m_pAnimation->GetPosVec3().m_fZ), g_GMng.m_nStage);
				}
				else
				{
					m_CEnyBullet[i].Enable(j, m_pArm[i]->GetPosVec3(), stEMVec3(Hero->m_pAnimation->GetPosVec3().m_fX + CEMMath::RandomFloatInRange(-100, 100), Hero->m_pAnimation->GetPosVec3().m_fY, Hero->m_pAnimation->GetPosVec3().m_fZ), g_GMng.m_nStage);
				}
				if (D_MNG->m_bSound)
					D_SOUND->Play(D_MNG->m_MEkSnd[i][0], D_MNG->GetSoundVolume());
				break;
			}
		}
	}
}