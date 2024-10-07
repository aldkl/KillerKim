#include "stdafx.h"

CUI::CUI()
{
}
CUI::~CUI()
{

}

void CUI::Update(float dt)
{
	m_CBulletNum.Update(dt, g_GMng.m_nBullet, g_GMng.m_nMap,g_GMng.m_nLiveEny,g_GMng.m_nScore + g_GMng.m_nKillScore, g_GMng.m_nStage + 1);

	if (g_GMng.m_BOSSUse)
	{
		if (!m_BOSSHPBar->GetShow())
		{
			m_BOSSHPBar->SetShow(TRUE);
			m_BOSSHPBarBG->SetShow(TRUE);
		}
		float fGague = m_BOSSHPBar->GetSize().m_fX;

		fGague = CEMMath::Lerp(fGague, (float)g_GMng.m_BOSSHP / 31.0f * 1.0f, 2.0f*dt);
		m_BOSSHPBar->SetUV(stEMVec2(0.0f, 0.0f), stEMVec2(fGague, 1.0f));
		m_BOSSHPBar->SetSize(fGague, 1.0f);
	}
	else
	{
		if (m_BOSSHPBar->GetShow())
		{
			m_BOSSHPBar->SetShow(FALSE);
			m_BOSSHPBarBG->SetShow(FALSE);
		}
	}
	float fGague1 = m_HeroSkillBar->GetSize().m_fX;

	fGague1 = CEMMath::Lerp(fGague1, (float)g_GMng.m_nGauge / 100.0f * 1.0f, 2.0f*dt);
	m_HeroSkillBar->SetSize(fGague1, 1.0f);
	UpdateHP();
}
void CUI::UpdateHP()
{
	switch (g_GMng.m_nHeroHP)
	{
	case 0:
		for (int i = 0; i < 5; i++)
		{
			m_HP[0][i]->SetPos(-700.0f + 60.0f * i, 50.0f, 0);
		}
		m_RED->SetAlpha(1);
		break;
	case 1:
		for (int i = 0; i < 5; i++)
		{
			m_HP[0][i]->SetPos(-700.0f + 60.0f * i, 50.0f, 0);
		}
		m_HP[0][0]->SetPos(60.0f + 60.0f * 0, 50.0f, 0);
		m_RED->SetAlpha(1.0f);
		break;
	case 2:
		for (int i = 0; i < 5; i++)
		{
			m_HP[0][i]->SetPos(-700.0f + 60.0f * i, 50.0f, 0);
		}
		m_HP[0][0]->SetPos(60.0f + 60.0f * 0, 50.0f, 0);
		m_HP[0][1]->SetPos(60.0f + 60.0f * 1, 50.0f, 0);
		m_RED->SetAlpha(0.75f);
		break;
	case 3:
		for (int i = 0; i < 5; i++)
		{
			m_HP[0][i]->SetPos(60.0f + 60.0f * i, 50.0f, 0);
		}
		m_HP[0][3]->SetPos(-700.0f + 60.0f, 50.0f, 0);//4
		m_HP[0][4]->SetPos(-700.0f + 60.0f, 50.0f, 0);//5
		m_RED->SetAlpha(0.5f);
		break;
	case 4:
		for (int i = 0; i < 5; i++)
		{
			m_HP[0][i]->SetPos(60.0f + 60.0f * i, 50.0f, 0);
		}
		m_HP[0][4]->SetPos(-700.0f + 60.0f, 50.0f, 0);
		m_RED->SetAlpha(0.25f);
		break;
	case 5:
		for (int i = 0; i < 5; i++)
		{
			m_HP[0][i]->SetPos(60.0f + 60.0f * i, 50.0f, 0);
		}
		m_RED->SetAlpha(0);
		break;
	}

	m_HeroSkillBarBG->SetPos(255, 670.0f);
	m_HeroSkillBar->SetPos(255 - 179.0f, 670.0f);
	m_STAGE->SetPos(710.0f, 60.0f);
	m_SCORE->SetPos(70.0f, 100.0f);
	m_HeroSkillSPR->SetPos(50.0f, 670.0f);
	m_Bullet->SetPos(1220.0f, 110.0f);
	m_Enemy->SetPos(1220.0f, 50.0f);
	m_BOSSHPBarBG->SetPos(667, 550);
	m_BOSSHPBar->SetPos(300, 550);
	m_STAGEMA->SetPos(620.0f, 60.0f);
	m_RED->SetPos(640, 360);
}
void CUI::CreateObj(CRootScene* pScene)
{
	m_HeroSkillBarBG = new CEMPlane();
	m_HeroSkillBarBG->SetTexture("Data/Image/UI/스킬게이지 Empty.png", GL_REPEAT, GL_NEAREST);
	m_HeroSkillBarBG->SetOrtho2D(true);
	m_HeroSkillBarBG->SetPos(255, 670.0f);
	m_HeroSkillBarBG->SetBlend(TRUE);
	m_HeroSkillBarBG->SetSize(1.0f, 1.0f);
	m_HeroSkillBarBG->SetFrstumCullingFlag(FALSE);
	m_HeroSkillBar = new CEMPlane();
	m_HeroSkillBar->SetTexture("Data/Image/UI/스킬게이지 Full.png", GL_REPEAT, GL_NEAREST);
	m_HeroSkillBar->SetOrtho2D(true);
	m_HeroSkillBar->SetPos(255 - 179.0f, 670.0f);
	m_HeroSkillBar->SetSize(1.0f, 1.0f);
	m_HeroSkillBar->SetOffset(179.0f, 0.0f);
	m_HeroSkillBar->SetBlend(TRUE);
	m_HeroSkillBar->SetFrstumCullingFlag(FALSE);

	m_HeroSkillBarbase = new CEMPlane();
	m_HeroSkillBarbase->SetTexture("Data/Image/UI/게이지_BASE.png", GL_REPEAT, GL_NEAREST);
	m_HeroSkillBarbase->SetOrtho2D(true);
	m_HeroSkillBarbase->SetPos(100.0f, 670.0f);
	m_HeroSkillBarbase->SetSize(1.0f, 1.0f);
	m_HeroSkillBarbase->SetBlend(TRUE);
	m_HeroSkillBarbase->SetShow(FALSE);
	m_HeroSkillBarbase->SetFrstumCullingFlag(FALSE);

	m_STAGE = new CEMPlane();
	m_STAGE->SetTexture("Data/Image/UI/단계.png", GL_REPEAT, GL_NEAREST);
	m_STAGE->SetOrtho2D(true);
	m_STAGE->SetPos(710.0f, 60.0f);
	m_STAGE->SetSize(1.0f, 1.0f);
	m_STAGE->SetBlend(TRUE);
	m_STAGE->SetFrstumCullingFlag(FALSE);

	m_SCORE = new CEMPlane();
	m_SCORE->SetTexture("Data/Image/UI/점수.png", GL_REPEAT, GL_NEAREST);
	m_SCORE->SetOrtho2D(true);
	m_SCORE->SetPos(70.0f, 100.0f);
	m_SCORE->SetSize(1.0f, 1.0f);
	m_SCORE->SetBlend(TRUE);
	m_SCORE->SetFrstumCullingFlag(FALSE);

	m_HeroSkillSPR = new CEMPlane();
	m_HeroSkillSPR->SetTexture("Data/Image/UI/방어 아이콘.png", GL_REPEAT, GL_NEAREST);
	m_HeroSkillSPR->SetOrtho2D(true);
	m_HeroSkillSPR->SetPos(50.0f, 670.0f);
	m_HeroSkillSPR->SetSize(1.0f, 1.0f);
	m_HeroSkillSPR->SetBlend(TRUE);
	m_HeroSkillSPR->SetFrstumCullingFlag(FALSE);

	m_Enemy = new CEMPlane();
	m_Enemy->SetTexture("Data/Image/UI/적 표시.png", GL_REPEAT, GL_NEAREST);
	m_Enemy->SetOrtho2D(true);
	m_Enemy->SetPos(1220.0f, 50.0f);
	m_Enemy->SetSize(1.0f, 1.0f);
	m_Enemy->SetBlend(TRUE);
	m_Enemy->SetFrstumCullingFlag(FALSE);
	

	m_Bullet = new CEMPlane();
	m_Bullet->SetTexture("Data/Image/UI/총알 표시.png", GL_REPEAT, GL_NEAREST);
	m_Bullet->SetOrtho2D(true);
	m_Bullet->SetPos(1220.0f, 110.0f);
	m_Bullet->SetSize(1.0f, 1.0f);
	m_Bullet->SetFrstumCullingFlag(FALSE);
	m_Bullet->SetBlend(TRUE);

	m_BOSSHPBarBG = new CEMPlane();
	m_BOSSHPBarBG->SetTexture("Data/Image/UI/보스 체력 EMPTY.png", GL_REPEAT, GL_NEAREST);
	m_BOSSHPBarBG->SetOrtho2D(true);
	m_BOSSHPBarBG->SetPos(667, 550);
	m_BOSSHPBarBG->SetBlend(TRUE);
	m_BOSSHPBarBG->SetShow(FALSE);
	m_BOSSHPBarBG->SetSize(1.0f, 1.0f);
	m_BOSSHPBarBG->SetFrstumCullingFlag(FALSE);
	m_BOSSHPBar = new CEMPlane();
	m_BOSSHPBar->SetTexture("Data/Image/UI/보스 체력 FULL1.png", GL_REPEAT, GL_NEAREST);
	m_BOSSHPBar->SetOrtho2D(true);
	m_BOSSHPBar->SetPos(300, 550);
	m_BOSSHPBar->SetSize(1.0f, 1.0f);
	m_BOSSHPBar->SetOffset(366.5f, 0.0f);
	m_BOSSHPBar->SetBlend(TRUE);
	m_BOSSHPBar->SetShow(FALSE);
	m_BOSSHPBar->SetFrstumCullingFlag(FALSE);

	m_STAGEMA = new CEMPlane();
	m_STAGEMA->SetTexture("Data/Image/UI/스테이지 -.png", GL_REPEAT, GL_NEAREST);
	m_STAGEMA->SetOrtho2D(true);
	m_STAGEMA->SetPos(620.0f, 60.0f);
	m_STAGEMA->SetSize(1.0f, 1.0f);
	m_STAGEMA->SetBlend(TRUE);
	m_STAGEMA->SetFrstumCullingFlag(FALSE);

	m_RED = new CEMPlane();
	m_RED->SetTexture("Data/Image/UI/피격.png", GL_REPEAT, GL_NEAREST);
	m_RED->SetOrtho2D(true);
	m_RED->SetPos(640, 360);
	m_RED->SetSize(1.0f, 1.0f);
	m_RED->SetBlend(TRUE);
	m_RED->SetAlpha(0);
	m_RED->SetFrstumCullingFlag(FALSE);

	pScene->Commit(-1, "0_GaugeBar", m_HeroSkillBarBG);
	pScene->Commit(-1, "GaugeBarBase", m_HeroSkillBarbase);
	pScene->Commit(-1, "1_GaugeBar", m_HeroSkillBar);
	pScene->Commit(-1, "GaugeBarBGIC", m_HeroSkillSPR);
	pScene->Commit(-1, "STAGE", m_STAGE);
	pScene->Commit(-1, "STAGE_", m_STAGEMA);
	pScene->Commit(-1, "SCORE", m_SCORE);
	pScene->Commit(-1, "HitRed", m_RED);
	pScene->Commit(-1, "Enemy", m_Enemy);
	pScene->Commit(-1, "BulletSprite", m_Bullet);
	pScene->Commit(-1, "BOSSGaugeBarBG", m_BOSSHPBarBG);
	pScene->Commit(-1, "BOSSGaugeBar___", m_BOSSHPBar);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m_HP[i][j] = new CEMPlane();
			if (i == 1)
			{
				m_HP[i][j]->SetTexture("Data/Image/UI/HP_NULL.png", GL_REPEAT, GL_NEAREST);
			}
			else
			{
				m_HP[i][j]->SetTexture("Data/Image/UI/HP_FULL.png", GL_REPEAT, GL_NEAREST);
			}
			m_HP[i][j]->SetOrtho2D(true);
			m_HP[i][j]->SetPos(60.0f + 60.0f * j, 50.0f, 0);
			m_HP[i][j]->SetSize(1.0f, 1.0f);
			m_HP[i][j]->SetBlend(TRUE);
			m_HP[i][j]->SetFrstumCullingFlag(FALSE);
			stdEMString stTemp2 = IntToEMString(i) + '_' + IntToEMString(j);
			if (i == 1)
			{
				pScene->Commit(-1, "HeroHPUI" + stTemp2, m_HP[i][j]);
			}
			else
			{
				pScene->Commit(-1, "HeroHPUI_" + stTemp2, m_HP[i][j]);
			}
		}
	}

	m_CBulletNum.CreateObj(pScene);
}

void CUI::Move()
{
	//m_HeroSkillBarBG->MoveX(1280.0f);
	//m_HeroSkillBar->MoveX(1280.0f);
	//m_Bullet->MoveX(1280.0f);
	//m_CBulletNum.m_pNum->MoveX(1280.0f);
}