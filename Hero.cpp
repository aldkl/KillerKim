#include "stdafx.h"

CHero::CHero()
{
	m_fSpeed = 300;
}
CHero::~CHero()
{

}

void CHero::Update(float dt)
{

	//m_pPlane->SetPos()
	if (g_GMng.m_nHeroHP == -1)
	{
		g_GMng.m_nHeroHP = -2;
		m_pAnimation->SetLoopType(E_ANI_ONE, 18, 25, E_ANI_ENDING_TYPE_SHOW_FALSE);
		m_pAnimation->SetTime(0.3f);
	}
	else if (g_GMng.m_nHeroHP == -2)
	{
		if (m_pAnimation->GetCurFrameNumber() == 25)
		{
			g_GMng.m_bUP2 = TRUE;
			g_GMng.m_bStart = TRUE;
			g_GMng.m_bmission = FALSE;
		}
	}
	else
	{
		Move(dt);
		Hit();
		if (g_GMng.m_bSkillOn)
		{
			m_pSkill->SetPos(m_pAnimation->GetPosVec2());
			if (m_fSpeed == 300)
			{
				m_fSpeed = 500;
			}
			if (g_GMng.m_bHit == TRUE)
			{
				g_GMng.m_bHit = FALSE;
			}
			if (g_GMng.m_bHit == TRUE)
			{
				g_GMng.m_bHit = FALSE;
			}
		}
		else
		{
			if (m_fSpeed == 500)
			{
				m_fSpeed = 300;
			}
			if (g_GMng.m_bHit == FALSE)
			{
				g_GMng.m_bHit = TRUE;
			}

			if (m_pSkill->GetPosVec2().m_fX != -150.0f)
			{
				m_pSkill->SetPos(-150.0f, 350.0f, 0.0f);
			}
		}

	}

}
void CHero::Hit()
{
	if (g_GMng.m_bHitHero)
	{
		g_GMng.m_fHitHero += D_WORLD->GetDeltaTime();
		if (g_GMng.m_fHitHero >= 0.1f)
		{
			g_GMng.m_fHitHero = 0;
			if (g_GMng.m_bAlphaCheck)
			{
				g_GMng.m_nCheckHeroAlpha++;
				g_GMng.m_bAlphaCheck = FALSE;
			}
			else
			{
				g_GMng.m_nCheckHeroAlpha++;
				g_GMng.m_bAlphaCheck = TRUE;
			}
			if (g_GMng.m_nCheckHeroAlpha > 6)
			{
				m_pAnimation->SetAlpha(1);
				g_GMng.m_nCheckHeroAlpha = 0;
				g_GMng.m_bHitHero = FALSE;
			}
		}
		if (g_GMng.m_bAlphaCheck)
		{
			m_pAnimation->SetAlpha(m_pAnimation->GetAlpha() - 0.1f/* * D_WORLD->GetDeltaTime()*/);
		}
		else
		{
			m_pAnimation->SetAlpha(m_pAnimation->GetAlpha() + 0.1f/* * D_WORLD->GetDeltaTime()*/);
		}
	}
}
void CHero::Enable(stEMVec3 Vec)
{

}
void CHero::Disable()
{

}
void CHero::CreateObj(CRootScene* pScene)
{
	m_pAnimation = NULL;
	m_pAnimation = new CEMAnimation(26);
	m_pAnimation->SetTexture(pScene, 26,
		"Data/Image/HeroAni/R2.png",
		"Data/Image/HeroAni/R1.png",
		"Data/Image/HeroAni/R2.png",
		"Data/Image/HeroAni/R3.png",
		"Data/Image/HeroAni/R2.png",
		"Data/Image/HeroAni/R1.png",
		"Data/Image/HeroAni/R2.png",
		"Data/Image/HeroAni/R3.png",//8(7)
		"Data/Image/HeroAni/L2.png",//9(8)
		"Data/Image/HeroAni/L1.png",
		"Data/Image/HeroAni/L2.png",
		"Data/Image/HeroAni/L3.png",
		"Data/Image/HeroAni/L2.png",
		"Data/Image/HeroAni/L1.png",
		"Data/Image/HeroAni/L2.png",
		"Data/Image/HeroAni/L3.png",
		"Data/Image/HeroAni/¾ÆÇÄ ÁÂ.png",//17(16)
		"Data/Image/HeroAni/¾ÆÇÄ ¿ì.png",//18(17)
		"Data/Image/HeroAni/¿ìÃø Á×À½ 1.png",
		"Data/Image/HeroAni/¿ìÃø Á×À½ 2.png",
		"Data/Image/HeroAni/¿ìÃø Á×À½ 3.png",
		"Data/Image/HeroAni/¿ìÃø Á×À½ 4.png",
		"Data/Image/HeroAni/¿ìÃø Á×À½ 5.png",
		"Data/Image/HeroAni/¿ìÃø Á×À½ 6.png",
		"Data/Image/HeroAni/¿ìÃø Á×À½ 7.png",
		"Data/Image/HeroAni/¿ìÃø Á×À½ 8.png",
		GL_REPEAT, GL_NEAREST);
	m_pAnimation->SetPos(150.0f, -350.0f, 0.0f);
	m_pAnimation->SetSize(0.45f, 0.42);
	m_pAnimation->SetBlend(TRUE);
	m_pAnimation->SetTime(0.1f);
	//m_pAnimation->SetPause(TRUE);
	m_pAnimation->SetLoopType(E_ANI_LOOP, 0, 0);

	m_pAnimation->SetBoundingBoxCalc(TRUE);
	m_pAnimation->SetFrstumCullingFlag(FALSE);

	m_pArm = new CEMPlane();
	m_pArm->SetTexture("Data/Image/HeroAni/Gun.png", GL_REPEAT, GL_NEAREST);
	m_pArm->SetOffset(+44.0f, 0);
	//m_pArm->SetZRot(-16.0f);
	m_pArm->SetPos(m_pAnimation->GetPosVec2().m_fX - 20, m_pAnimation->GetPosVec2().m_fY - 10);
	m_pArm->SetSize(0.37f, 0.42f);
	m_pArm->SetBlend(TRUE);
	m_pArm->SetBoundingBoxCalc(FALSE);
	m_pArm->SetFrstumCullingFlag(FALSE);
	pScene->Commit(0, "hero", m_pAnimation);
	pScene->Commit(0, "hero_arm", m_pArm);

	m_pSkill = NULL;

	m_pSkill = new CEMAnimation(4);

	m_pSkill->SetTexture(pScene, 4,
		"Data/Image/HeroAni/1.png",
		"Data/Image/HeroAni/2.png",
		"Data/Image/HeroAni/3.png",
		"Data/Image/HeroAni/4.png",

		GL_REPEAT, GL_NEAREST);
	m_pSkill->SetPos(150.0f, 350.0f, 0.0f);
	m_pSkill->SetSize(0.4f, 0.4f);
	m_pSkill->SetBlend(TRUE);
	m_pSkill->SetTime(0.1f);
	//m_pSkill->SetPause(TRUE);
	//m_pSkill->SetLoopType(E_ANI_LOOP, 0, 0);

	m_pSkill->SetBoundingBoxCalc(TRUE);
	m_pSkill->SetFrstumCullingFlag(FALSE);
	m_Fire = new CEMPlane();
	m_Fire->SetOffset(0, 0);
	m_Fire->SetSize(0.5, 0.5);
	m_Fire->SetAlpha(0.0);
	m_Fire->SetBlend(TRUE);
	m_Fire->SetBoundingBoxCalc(FALSE);
	m_Fire->SetFrstumCullingFlag(FALSE);
	pScene->Commit(0, "hero_fire", m_Fire);

	pScene->Commit(0, "heroskill", m_pSkill);

}

void CHero::Move(float dt)
{

	if (D_INPUT->IsKeyDown(VK_D))
	{
		//m_pAnimation->SetLoopType(E_ANI_LOOP, 0, 0);
		m_pAnimation->MoveX(m_fSpeed * dt);
		g_GMng.m_bHeroMove = TRUE;

	}
	if (D_INPUT->IsKeyDown(VK_A))
	{
		//m_pAnimation->SetLoopType(E_ANI_LOOP, 1, 2);
		m_pAnimation->MoveX(-m_fSpeed * dt);
		g_GMng.m_bHeroMove = TRUE;
	}
	if (D_INPUT->IsKeyDown(VK_W))
	{
		m_pAnimation->MoveY(m_fSpeed * dt);
		g_GMng.m_bHeroMove = TRUE;
	}
	if (D_INPUT->IsKeyDown(VK_S))
	{
		m_pAnimation->MoveY(-m_fSpeed * dt);
		g_GMng.m_bHeroMove = TRUE;
	}
	if (!D_INPUT->IsKeyDown(VK_A) && !D_INPUT->IsKeyDown(VK_W) && !D_INPUT->IsKeyDown(VK_S) && !D_INPUT->IsKeyDown(VK_D))
	{
		if (g_GMng.m_bHeroSide)
		{
			m_pAnimation->SetLoopType(E_ANI_LOOP, 8, 8);
		}
		else
		{
			m_pAnimation->SetLoopType(E_ANI_LOOP, 0, 0);
		}
		g_GMng.m_bHeroMove = FALSE;
		g_GMng.m_bHeroFrame = FALSE;
	}
	if (g_GMng.m_bHeroMove == TRUE)
	{
		if (g_GMng.m_bHeroSide)
		{
			if (m_pAnimation->GetCurFrameNumber() == 8 && g_GMng.m_bHeroFrame == FALSE)
			{
				m_pAnimation->SetLoopType(E_ANI_LOOP, 8, 15);
				g_GMng.m_bHeroFrame = TRUE;
			}
		}
		else
		{
			if (m_pAnimation->GetCurFrameNumber() == 0 && g_GMng.m_bHeroFrame == FALSE)
			{
				m_pAnimation->SetLoopType(E_ANI_LOOP, 0, 7);
				g_GMng.m_bHeroFrame = TRUE;
			}

		}
	}
	if (D_INPUT->IsKeyDown(VK_SPACE))
	{
		if (g_GMng.m_bSkillToggle)
		{
			g_GMng.m_fHeroGaugeTime += dt;
			if (g_GMng.m_fHeroGaugeTime >= 0.03f)
			{
				g_GMng.m_fHeroGaugeTime = 0;
				//g_GMng.m_fHeroToggleTime = 0;
				if (g_GMng.m_nGauge > 0)
				{
					//Dprintf("½ºÅ³ »ç¿ëÁß");
					g_GMng.m_bSkillOn = TRUE;
					if (!g_GMng.m_bF8)
					{
						g_GMng.m_nGauge -= 1;
					}
					if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_BARRIER]) && D_MNG->m_bSound)
						D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_BARRIER], D_MNG->GetSoundVolume());
				}
				else
				{
					//Dprintf("½ºÅ³ ²¨Áü");
					D_SOUND->Stop(D_MNG->m_ClickSnd[E_FXSND_BARRIER]);
					g_GMng.m_bSkillOn = FALSE;
					g_GMng.m_bSkillToggle = FALSE;
				}
			}
		}
	}
	else
	{
		if (g_GMng.m_bSkillOn)
			g_GMng.m_bSkillOn = FALSE;
		if (!g_GMng.m_bSkillToggle)
			g_GMng.m_bSkillToggle = TRUE;
		D_SOUND->Stop(D_MNG->m_ClickSnd[E_FXSND_BARRIER]);
		if (g_GMng.m_nGauge < 100)
		{
			g_GMng.m_fHeroToggleTime += dt;

			if (g_GMng.m_fHeroToggleTime >= 0.5f)
			{
				if (g_GMng.m_bSkillToggle == TRUE)
				{

					g_GMng.m_bSkillToggle = FALSE;
					g_GMng.m_fHeroToggleTime = 0;

				}
			}
			//if(!g_GMng.m_bSkillToggle)
			g_GMng.m_fHeroGaugeTime += dt;
			if (g_GMng.m_fHeroGaugeTime >= 0.15f)
			{
				//Dprintf("½ºÅ³ °ÔÀÌÁö Â÷´ÂÁß");
				g_GMng.m_fHeroGaugeTime = 0;
				g_GMng.m_nGauge += 1;
			}
		}
	}
	//if(D_INPUT->IsKeyUp(VK_SPACE))

	stEMVec2 stTempVec2;
	stTempVec2 = m_pArm->GetPosVec2();
	stTempVec2.m_fX = m_pAnimation->GetPosVec2().m_fX - 24;
	stTempVec2.m_fY = m_pAnimation->GetPosVec2().m_fY - 6;
	m_pArm->SetPos(stTempVec2);

}

void CHero::Clipping()
{

}