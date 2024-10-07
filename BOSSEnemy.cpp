#include "stdafx.h"

CBossEnemy::CBossEnemy()
{

}
CBossEnemy::~CBossEnemy()
{

}
void CBossEnemy::Update(CEMPlane* m_CMap, CHero* Hero)
{
	if (g_GMng.m_BOSSUse &&
		m_Enemy[E_BOSS_MOVE_UP]->GetShow() ||
		m_Enemy[E_BOSS_MOVE_DOWN]->GetShow() ||
		m_Enemy[E_BOSS_MOVE_RIGHT]->GetShow() ||
		m_Enemy[E_BOSS_MOVE_LEFT]->GetShow() ||
		m_Enemy[E_BOSS_DIE]->GetShow() ||
		m_Enemy[E_BOSS_JUMP]->GetShow()
		)
	{
		if (pattern == 1)
		{
			CreateBullet1(Hero);
			Move();
			CreatEn();

		}
		else if (pattern == 2)
		{
			if (g_GMng.m_BOSSHP == 0)
			{
				m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(FALSE);
				m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
				m_Enemy[E_BOSS_MOVE_UP]->SetShow(FALSE);
				m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(FALSE);
				m_Enemy[E_BOSS_JUMP]->SetShow(FALSE);
				m_Enemy[E_BOSS_DIE]->SetShow(TRUE);
				m_Enemy[E_BOSS_JUMP]->SetPause(TRUE);
				m_Enemy[E_BOSS_DIE]->SetPause(FALSE);
				if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_BOOSDIE]) && D_MNG->m_bSound)
					D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_BOOSDIE], D_MNG->GetSoundVolume());
				g_GMng.m_nKillScore += 1000;
				g_GMng.m_nLiveEny--;
				Disable(0);
			}
			else if (g_GMng.m_BOSSHP > 0)
			{
				m_fUpTime += D_WORLD->GetDeltaTime();
				if (m_fUpTime >= 0.1f)
				{
					m_fUpTime = 0;
					if (nMove == 0)
					{
						m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(FALSE);
						m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
						m_Enemy[E_BOSS_MOVE_UP]->SetShow(FALSE);
						m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(TRUE);
						m_Enemy[E_BOSS_JUMP]->SetShow(FALSE);
						m_Enemy[E_BOSS_JUMP]->SetPause(TRUE);
						nMove = 1;
					}
					else if (nMove == 1)
					{
						m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(FALSE);
						m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(TRUE);
						m_Enemy[E_BOSS_MOVE_UP]->SetShow(FALSE);
						m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(FALSE);
						nMove = 2;
					}
					else if (nMove == 2)
					{
						m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(FALSE);
						m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
						m_Enemy[E_BOSS_MOVE_UP]->SetShow(TRUE);
						m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(FALSE);
						nMove = 3;
					}
					else if (nMove == 3)
					{
						m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(TRUE);
						m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
						m_Enemy[E_BOSS_MOVE_UP]->SetShow(FALSE);
						m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(FALSE);
						nMove = 0;
					}
				}
				CreateBullet2(Hero);
			}
		}
		m_CEnyBullet.Update(D_WORLD->GetDeltaTime(), 0);
		CEMAnimation* m_pCurAni2 = NULL;
		m_pCurAni2 = (CEMAnimation*)m_pScene->IsCollision(E_SPHERE_VS_SPHERE, (CEMAnimation*)m_Enemy[E_BOSS_MOVE_LEFT], -1);
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
					g_GMng.m_BOSSHP--;
					m_pCurAni2->SetPause(FALSE);
					g_GMng.m_nScore += 50;
				}
			}
		}
	}
}
void CBossEnemy::Enable(stEMVec2 stCreateVec2)
{
	g_GMng.m_BOSSUse = TRUE;
	pattern = 1;
	UP = TRUE;
	m_Enemy[E_BOSS_MOVE_LEFT]->SetPause(TRUE);
	g_GMng.m_nLiveEny++;
	if (!g_GMng.m_bF5)
		g_GMng.m_BOSSHP = 1;
	else
		g_GMng.m_BOSSHP = 1;

	for (int i = 0; i < E_BOSS_MAX; i++)
	{
		m_Enemy[i]->SetPos(stCreateVec2);
	}
	m_stVec2 = stCreateVec2;
	stEMNowVec2 = stCreateVec2;
	m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(TRUE);
	//g_GMng.m_fMEMoveTime[E_BOSS_MOVE_UP] = CEMMath::RandomIntInRange(0, 4);
	g_GMng.m_fBossFireTime1 = -4;
	nMove = 0;
	m_fPatternChangeTime = 0;
	m_fCreatEnemyTime = -5;
	m_fUpTime = 0;
	m_bType = FALSE;
}
void CBossEnemy::Disable(int nIndex)
{
	for (int i = 0; i < E_BOSS_MAX; i++)
	{
		m_Enemy[i]->SetShow(FALSE);
	}
	g_GMng.m_BOSSUse = FALSE;
	for (int i = 0; i < 30; i++)
	{
		m_CEnyBullet.Disable(i);
	}
}
void CBossEnemy::CreateObj(CRootScene* pScene)
{
	g_GMng.m_BOSSUse = FALSE;
	pattern = -1;
	m_Enemy[E_BOSS_MOVE_UP] = new CEMAnimation(1);
	m_Enemy[E_BOSS_MOVE_UP]->SetTexture(pScene, 1, "Data/Image/보스/상.png", GL_REPEAT, GL_NEAREST);
	m_Enemy[E_BOSS_MOVE_UP]->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_Enemy[E_BOSS_MOVE_UP]->SetSize(0.7f, 0.7f);
	m_Enemy[E_BOSS_MOVE_UP]->SetTime(0.2f);
	//m_Enemy[E_BOSS_MOVE_UP]->SetPause(TRUE);
	m_Enemy[E_BOSS_MOVE_UP]->SetShow(FALSE);
	m_Enemy[E_BOSS_MOVE_UP]->SetBlend(TRUE);
	m_Enemy[E_BOSS_MOVE_UP]->SetBoundingBoxCalc(TRUE);
	m_Enemy[E_BOSS_MOVE_UP]->SetFrstumCullingFlag(FALSE);

	m_Enemy[E_BOSS_MOVE_DOWN] = new CEMAnimation(1);
	m_Enemy[E_BOSS_MOVE_DOWN]->SetTexture(pScene, 1, "Data/Image/보스/하.png", GL_REPEAT, GL_NEAREST);
	m_Enemy[E_BOSS_MOVE_DOWN]->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_Enemy[E_BOSS_MOVE_DOWN]->SetSize(0.7f, 0.7f);
	m_Enemy[E_BOSS_MOVE_DOWN]->SetTime(0.2f);
	m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(FALSE);
	m_Enemy[E_BOSS_MOVE_DOWN]->SetBlend(TRUE);
	m_Enemy[E_BOSS_MOVE_DOWN]->SetBoundingBoxCalc(TRUE);
	m_Enemy[E_BOSS_MOVE_DOWN]->SetFrstumCullingFlag(FALSE);

	m_Enemy[E_BOSS_MOVE_RIGHT] = new CEMAnimation(1);
	m_Enemy[E_BOSS_MOVE_RIGHT]->SetTexture(pScene, 1, "Data/Image/보스/우.png", GL_REPEAT, GL_NEAREST);
	m_Enemy[E_BOSS_MOVE_RIGHT]->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_Enemy[E_BOSS_MOVE_RIGHT]->SetSize(0.7f, 0.7f);
	m_Enemy[E_BOSS_MOVE_RIGHT]->SetTime(0.2f);
	m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
	m_Enemy[E_BOSS_MOVE_RIGHT]->SetBlend(TRUE);
	m_Enemy[E_BOSS_MOVE_RIGHT]->SetBoundingBoxCalc(TRUE);
	m_Enemy[E_BOSS_MOVE_RIGHT]->SetFrstumCullingFlag(FALSE);

	m_Enemy[E_BOSS_MOVE_LEFT] = new CEMAnimation(1);
	m_Enemy[E_BOSS_MOVE_LEFT]->SetTexture(pScene, 1, "Data/Image/보스/좌.png", GL_REPEAT, GL_NEAREST);
	m_Enemy[E_BOSS_MOVE_LEFT]->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_Enemy[E_BOSS_MOVE_LEFT]->SetSize(0.7f, 0.7f);
	m_Enemy[E_BOSS_MOVE_LEFT]->SetTime(0.2f);
	m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(FALSE);
	m_Enemy[E_BOSS_MOVE_LEFT]->SetBlend(TRUE);
	m_Enemy[E_BOSS_MOVE_LEFT]->SetBoundingBoxCalc(TRUE);
	m_Enemy[E_BOSS_MOVE_LEFT]->SetFrstumCullingFlag(FALSE);

	m_Enemy[E_BOSS_JUMP] = new CEMAnimation(11);
	m_Enemy[E_BOSS_JUMP]->SetTexture(pScene, 11,
		"Data/Image/보스/Ready.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/점프.png",
		"Data/Image/보스/Ready.png",
		GL_REPEAT, GL_NEAREST);
	m_Enemy[E_BOSS_JUMP]->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_Enemy[E_BOSS_JUMP]->SetSize(0.7f, 0.7f);
	m_Enemy[E_BOSS_JUMP]->SetTime(0.17f);
	m_Enemy[E_BOSS_JUMP]->SetPause(TRUE);
	m_Enemy[E_BOSS_JUMP]->SetShow(FALSE);
	m_Enemy[E_BOSS_JUMP]->SetBlend(TRUE);
	m_Enemy[E_BOSS_JUMP]->SetBoundingBoxCalc(TRUE);
	m_Enemy[E_BOSS_JUMP]->SetFrstumCullingFlag(FALSE);

	m_Enemy[E_BOSS_DIE] = new CEMAnimation(8);
	m_Enemy[E_BOSS_DIE]->SetTexture(pScene, 8,
		"Data/Image/보스/죽음1.png",
		"Data/Image/보스/죽음2.png",
		"Data/Image/보스/죽음3.png",
		"Data/Image/보스/죽음4.png",
		"Data/Image/보스/죽음5.png",
		"Data/Image/보스/죽음6.png",
		"Data/Image/보스/죽음7.png",
		"Data/Image/보스/죽음7.png",
		GL_REPEAT, GL_NEAREST);
	m_Enemy[E_BOSS_DIE]->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_Enemy[E_BOSS_DIE]->SetSize(0.7f, 0.7f);
	m_Enemy[E_BOSS_DIE]->SetPause(TRUE);
	m_Enemy[E_BOSS_DIE]->SetTime(0.3f);
	m_Enemy[E_BOSS_DIE]->SetShow(FALSE);
	m_Enemy[E_BOSS_DIE]->SetBlend(TRUE);
	m_Enemy[E_BOSS_DIE]->SetBoundingBoxCalc(TRUE);
	m_Enemy[E_BOSS_DIE]->SetFrstumCullingFlag(FALSE);

	m_crack = new CEMPlane();
	m_crack->SetTexture(pScene,
		"Data/Image/보스/죽음1.png",
		GL_REPEAT, GL_NEAREST);
	m_crack->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_crack->SetSize(0.7f, 0.7f);
	m_crack->SetShow(FALSE);
	m_crack->SetBlend(TRUE);
	m_crack->SetBoundingBoxCalc(TRUE);
	m_crack->SetFrstumCullingFlag(FALSE);


	stdEMString stTemp = "BOSSUP";
	pScene->Commit(2, stTemp, m_Enemy[E_BOSS_MOVE_UP]);
	stTemp = "BOSSRIGHT";
	pScene->Commit(2, stTemp, m_Enemy[E_BOSS_MOVE_RIGHT]);
	stTemp = "BOSSLEFT";
	pScene->Commit(2, stTemp, m_Enemy[E_BOSS_MOVE_LEFT]);
	stTemp = "BOSSDOWN";
	pScene->Commit(2, stTemp, m_Enemy[E_BOSS_MOVE_DOWN]);
	stTemp = "BOSSDIE";
	pScene->Commit(2, stTemp, m_Enemy[E_BOSS_DIE]);
	stTemp = "BOSSJUMP";
	pScene->Commit(2, stTemp, m_Enemy[E_BOSS_JUMP]);
	stTemp = "BOSSCRACK";
	pScene->Commit(3, stTemp, m_crack);
	//g_GMng.m_fSEMoveTime = CEMMath::RandomIntInRange(0, 4);
	//g_GMng.m_fSEFireTime = CEMMath::RandomIntInRange(-4, 0);

	m_CEnyBullet.CreateObj(pScene, "BOSSBullet", 00, 3, 4);
	m_pScene = pScene;

}

void CBossEnemy::Move()
{
	if (g_GMng.m_BOSSHP <= 30)
	{
		if (m_Enemy[E_BOSS_MOVE_UP]->GetPosVec2().m_fY < -330 && m_Enemy[E_BOSS_MOVE_UP]->GetPosVec2().m_fY > -340)
		{
			nMove = 1111;
			if (m_Enemy[E_BOSS_JUMP]->GetCurFrameNumber() == 10)
			{
				pattern = 2;
				m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(TRUE);
				m_Enemy[E_BOSS_JUMP]->SetShow(FALSE);
				m_Enemy[E_BOSS_JUMP]->SetPause(TRUE);
				m_crack->SetShow(TRUE);
				nMove = 0;
			}
			for (int i = 0; i < E_BOSS_MAX; i++)
			{
				m_Enemy[i]->MoveX(-300 * D_WORLD->GetDeltaTime());
			}
			m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_UP]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(FALSE);
			m_Enemy[E_BOSS_JUMP]->SetShow(TRUE);
			m_Enemy[E_BOSS_JUMP]->SetPause(FALSE);
		}
	}
	if (UP)
	{
		if (m_Enemy[E_BOSS_MOVE_UP]->GetPosVec2().m_fY < -100 && nMove == 0)//위로
		{
			for (int i = 0; i < E_BOSS_MAX; i++)
			{
				m_Enemy[i]->MoveY(300 * D_WORLD->GetDeltaTime());
			}
		}
		else if (nMove == 0)//바뀜
		{
			m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_UP]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(TRUE);
			nMove = 1;
		}
		if (m_Enemy[E_BOSS_MOVE_UP]->GetPosVec2().m_fX > m_stVec2.m_fX - 800 && nMove == 1)//위_왼쪽으로
		{
			for (int i = 0; i < E_BOSS_MAX; i++)
			{
				m_Enemy[i]->MoveX(-300 * D_WORLD->GetDeltaTime());
			}
		}
		else if (nMove == 1)//바뀜
		{
			nMove = 2;
		}
		if (m_Enemy[E_BOSS_MOVE_UP]->GetPosVec2().m_fX < m_stVec2.m_fX - 100 && nMove == 2)//위 오른쪽으로
		{
			for (int i = 0; i < E_BOSS_MAX; i++)
			{
				m_Enemy[i]->MoveX(300 * D_WORLD->GetDeltaTime());
			}
		}
		else if (nMove == 2)//바뀜
		{
			m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(TRUE);
			m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_UP]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(FALSE);
			nMove = -1;
			UP = FALSE;
		}
	}
	else
	{
		if (m_Enemy[E_BOSS_MOVE_UP]->GetPosVec2().m_fY > -500 && nMove == -1)//아래로
		{
			for (int i = 0; i < E_BOSS_MAX; i++)
			{
				m_Enemy[i]->MoveY(-300 * D_WORLD->GetDeltaTime());
			}
		}
		else if (nMove == -1)//바뀜
		{
			m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_UP]->SetShow(TRUE);
			m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(FALSE);
			nMove = -2;
		}
		if (m_Enemy[E_BOSS_MOVE_UP]->GetPosVec2().m_fX > m_stVec2.m_fX - 800 && nMove == -2)//아래_오른쪽으로
		{
			for (int i = 0; i < E_BOSS_MAX; i++)
			{
				m_Enemy[i]->MoveX(-300 * D_WORLD->GetDeltaTime());
			}

		}
		else if (nMove == -2)//바뀜
		{
			nMove = -3;
		}
		if (m_Enemy[E_BOSS_MOVE_UP]->GetPosVec2().m_fX < m_stVec2.m_fX - 100 && nMove == -3)//아래_왼쪽으로
		{
			for (int i = 0; i < E_BOSS_MAX; i++)
			{
				m_Enemy[i]->MoveX(300 * D_WORLD->GetDeltaTime());
			}
		}
		else if (nMove == -3)//바뀜
		{
			m_Enemy[E_BOSS_MOVE_LEFT]->SetShow(TRUE);
			m_Enemy[E_BOSS_MOVE_RIGHT]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_UP]->SetShow(FALSE);
			m_Enemy[E_BOSS_MOVE_DOWN]->SetShow(FALSE);
			nMove = 0;
			UP = TRUE;
		}
	}
}
void CBossEnemy::Clipping(int i, CEMPlane* m_CMap)
{

}
void CBossEnemy::CreatEn()
{
}
void CBossEnemy::CreateBullet1(CHero* Hero)
{
	g_GMng.m_fBossFireTime1 += D_WORLD->GetDeltaTime();
	if (g_GMng.m_fBossFireTime1 >= 1.2f)
	{
		g_GMng.m_fBossFireTime1 = 0;
		int nTemp = 0;

		if (nMove == 0 || nMove == -1)
		{
			Dprintf("옆를 보고쏨");
			for (int j = 0; j < D_BULLET_MAX; j++)
			{
				if (m_CEnyBullet.m_pAnimation[j]->GetShow() == FALSE && nTemp < 3)
				{
					switch (nTemp)
					{
					case 0:
						m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(), stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 500, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ), g_GMng.m_nStage);
						break;
					case 1:
						m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(), stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 500, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ), g_GMng.m_nStage);
						break;
					case 2:
						m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(), stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 500, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ), g_GMng.m_nStage);
						break;
					}
					nTemp++;
				}
				else
				{
					nTemp = 0;
					if (!D_SOUND->IsPlaying(D_MNG->m_SEkSnd[4][0]) && D_MNG->m_bSound)
						D_SOUND->Play(D_MNG->m_SEkSnd[4][0], D_MNG->GetSoundVolume());
					break;
				}
			}
		}
		else if (nMove == 1 || nMove == 2)
		{
			Dprintf("아래를 보고쏨");
			for (int j = 0; j < D_BULLET_MAX; j++)
			{
				if (m_CEnyBullet.m_pAnimation[j]->GetShow() == FALSE && nTemp < 3)
				{
					switch (nTemp)
					{
					case 0:
						m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(), stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 500, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ), g_GMng.m_nStage);
						break;
					case 1:
						m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(), stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 500, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ), g_GMng.m_nStage);
						break;
					case 2:
						m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(), stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 500, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ), g_GMng.m_nStage);
						break;
					}
					nTemp++;
				}
				else
				{
					nTemp = 0;
					if (!D_SOUND->IsPlaying(D_MNG->m_SEkSnd[3][0]) && D_MNG->m_bSound)
						D_SOUND->Play(D_MNG->m_SEkSnd[3][0], D_MNG->GetSoundVolume());
					break;
				}
			}
		}
		else if (nMove == -2 || nMove == -3)
		{
			Dprintf("위를 보고쏨");
			for (int j = 0; j < D_BULLET_MAX; j++)
			{
				if (m_CEnyBullet.m_pAnimation[j]->GetShow() == FALSE && nTemp < 3)
				{
					switch (nTemp)
					{
					case 0:
						m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(), stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 500, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ), g_GMng.m_nStage);
						break;
					case 1:
						m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(), stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 500, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ), g_GMng.m_nStage);
						break;
					case 2:
						m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(), stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 500, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ), g_GMng.m_nStage);
						break;
					}
					nTemp++;
				}
				else
				{
					nTemp = 0;
					if (!D_SOUND->IsPlaying(D_MNG->m_SEkSnd[3][0]) && D_MNG->m_bSound)
						D_SOUND->Play(D_MNG->m_SEkSnd[3][0], D_MNG->GetSoundVolume());
					break;
				}
			}
		}
	}
}

void CBossEnemy::CreateBullet2(CHero* Hero)
{
	g_GMng.m_fBossFireTime1 += D_WORLD->GetDeltaTime();
	if (g_GMng.m_fBossFireTime1 >= 1.2f)
	{
		g_GMng.m_fBossFireTime1 = 0;
		int nTemp = 0;

		if (m_bType)
		{
			for (int j = 0; j < D_BULLET_MAX; j++)
			{
				if (m_CEnyBullet.m_pAnimation[j]->GetShow() == FALSE)
				{
					if (nTemp < 12)
					{
						switch (nTemp)
						{
						case 0:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 1:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 2:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 3:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 4:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 5:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 150, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 6:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 7:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 150, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 8:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 80, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 9:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 80, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 10:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 80, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 11:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 80, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						}
						nTemp++;
					}
					else
					{
						nTemp = 0;
						m_bType = FALSE;
						if (!D_SOUND->IsPlaying(D_MNG->m_SEkSnd[3][0]) && D_MNG->m_bSound)
							D_SOUND->Play(D_MNG->m_SEkSnd[3][0], D_MNG->GetSoundVolume());
						break;
					}
				}
			}
		}
		else if (!m_bType)
		{
			for (int j = 0; j < D_BULLET_MAX; j++)
			{
				if (m_CEnyBullet.m_pAnimation[j]->GetShow() == FALSE)
				{
					if (nTemp < 12)
					{
						switch (nTemp)
						{
						case 0:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 1:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 300, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 2:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 300, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 3:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 4:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 5:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 300, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 6:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 300, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 7:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 50, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 8:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 9:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 10:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						case 11:
							m_CEnyBullet.Enable(j, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3(),
								stEMVec3(m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fX - 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fY + 100, m_Enemy[E_BOSS_MOVE_UP]->GetPosVec3().m_fZ),
								g_GMng.m_nStage);
							break;
						}
						nTemp++;
					}
					else
					{
						nTemp = 0;
						m_bType = TRUE;
						if (!D_SOUND->IsPlaying(D_MNG->m_SEkSnd[3][0]) && D_MNG->m_bSound)
							D_SOUND->Play(D_MNG->m_SEkSnd[3][0], D_MNG->GetSoundVolume());
						break;
					}
				}

			}
		}
	}
}