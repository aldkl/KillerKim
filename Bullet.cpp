#include "stdafx.h"

CBullet::CBullet()
{
	m_fSpeed = 2.5f;
}
CBullet::~CBullet()
{

}

void CBullet::Update(float dt, int nType)
{
	Move(dt, nType);
	//for (int i = 0; i < D_MONSTER_MAX; i++)
	//{
	//	m_Effect[i].Update(dt);
	//}
}
void CBullet::Enable(int nIndex, stEMVec3 StVec, stMouseInfo EdVec, int nStage)
{
	if (m_pAnimation[nIndex]->GetShow() == FALSE)
	{
		m_pAnimation[nIndex]->SetPos(StVec.m_fX, StVec.m_fY, StVec.m_fZ);
		m_pSheldH[nIndex]->SetPos(StVec.m_fX, StVec.m_fY, StVec.m_fZ);
		/*m_pAnimation[nIndex]->SetSize(0.5f, 0.5f);*/
		m_pAnimation[nIndex]->SetShow(TRUE);
		m_stHeroVec3 = StVec;
		stEMVec2 stDesPos(0.0f, 0.0f);

		stDesPos = CEMMath::ScreenToWorld(EdVec.m_nX, EdVec.m_nY);

		m_stClickDestPos[nIndex] = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);

		stEMVec3 stTemp = m_stClickDestPos[nIndex] - m_stHeroVec3;
		stTemp.Normalize();
		m_stHeroDirVec3.Normalize();

		// ³»Àû °è»ê
		m_fDot = stEMVec3::Dot(m_stHeroDirVec3, stTemp);

		// °¢µµ ±¸ÇÏ±â^^
		m_fRadian = (float)acos(m_fDot);

		// ÁÖÀÎ°øÀÇ ¾÷º¤ÅÍ ±¸ÇÏ±â
		m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));

		if (stEMVec3::Dot(m_stHeroRightVec3, stTemp) > 0.0f)
		{
			m_pAnimation[nIndex]->SetZRot(CEMMath::ToDegrees(m_fRadian) + 90);
			m_pSheldH[nIndex]->SetZRot(CEMMath::ToDegrees(m_fRadian) + 90);
			//Dprintf("¿ÞÂÊ %f\n", m_fRadian);
		}
		else
		{
			m_pAnimation[nIndex]->SetZRot(CEMMath::ToDegrees(-m_fRadian) + 90);
			m_pSheldH[nIndex]->SetZRot(CEMMath::ToDegrees(-m_fRadian) + 90);
			//Dprintf("¿À¸¥ÂÊ %f\n", m_fRadian);
		}
		if (stDesPos.m_fX < m_pAnimation[nIndex]->GetPosVec2().m_fX)
		{
			if (m_pAnimation[nIndex]->GetCurFrameNumber() == 0)
			{
				//m_pAnimation[nIndex]->SetLoopType(E_ANI_LOOP, 1, 2);
			}
		}
		//´ÜÀ§º¤ÅÍ ¸¸µåÈÄ ±æÀÌ¸¦ ´Ã·ÁÁÝ´Ï´Ù^^
		stTemp = stTemp * 270.0f;
		m_stClickDestPos[nIndex] = stTemp;


		//m_pAnimation[nIndex]->SetFrstumCullingFlag(FALSE);
	}
}
void CBullet::Enable(int nIndex, stEMVec3 StVec, stEMVec3 EdVec, int nStage)
{
	if (m_pAnimation[nIndex]->GetShow() == FALSE)
	{
		m_pAnimation[nIndex]->SetPos(StVec.m_fX, StVec.m_fY, StVec.m_fZ);
		m_pSheldH[nIndex]->SetPos(StVec.m_fX, StVec.m_fY, StVec.m_fZ);
		/*m_pAnimation[nIndex]->SetSize(0.5f, 0.5f);*/
		m_pAnimation[nIndex]->SetShow(TRUE);
		m_stHeroVec3 = StVec;
		stEMVec2 stDesPos(0.0f, 0.0f);

		stDesPos = stEMVec2(EdVec.m_fX, EdVec.m_fY);

		m_stClickDestPos[nIndex] = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);

		stEMVec3 stTemp = m_stClickDestPos[nIndex] - m_stHeroVec3;
		stTemp.Normalize();
		m_stHeroDirVec3.Normalize();

		// ³»Àû °è»ê
		m_fDot = stEMVec3::Dot(m_stHeroDirVec3, stTemp);

		// °¢µµ ±¸ÇÏ±â^^
		m_fRadian = (float)acos(m_fDot);

		// ÁÖÀÎ°øÀÇ ¾÷º¤ÅÍ ±¸ÇÏ±â
		m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));

		if (stEMVec3::Dot(m_stHeroRightVec3, stTemp) > 0.0f)
		{
			if (m_nWho == 4)
			{
				m_pAnimation[nIndex]->SetZRot(CEMMath::ToDegrees(m_fRadian) - 90);
				m_pSheldH[nIndex]->SetZRot(CEMMath::ToDegrees(m_fRadian) - 90);
			}
			else
			{
				m_pAnimation[nIndex]->SetZRot(CEMMath::ToDegrees(m_fRadian));
				m_pSheldH[nIndex]->SetZRot(CEMMath::ToDegrees(m_fRadian));
			}
			//Dprintf("¿ÞÂÊ %f\n", m_fRadian);
		}
		else
		{
			if (m_nWho == 4)
			{
				m_pAnimation[nIndex]->SetZRot(CEMMath::ToDegrees(-m_fRadian) - 90);
				m_pSheldH[nIndex]->SetZRot(CEMMath::ToDegrees(-m_fRadian) - 90);
			}
			else
			{
				m_pAnimation[nIndex]->SetZRot(CEMMath::ToDegrees(-m_fRadian));
				m_pSheldH[nIndex]->SetZRot(CEMMath::ToDegrees(-m_fRadian));
			}
			//Dprintf("¿À¸¥ÂÊ %f\n", m_fRadian);
		}
		if (stDesPos.m_fX < m_pAnimation[nIndex]->GetPosVec2().m_fX)
		{
			if (m_pAnimation[nIndex]->GetCurFrameNumber() == 0)
			{
				//m_pAnimation[nIndex]->SetLoopType(E_ANI_LOOP, 1, 2);
			}
		}
		//´ÜÀ§º¤ÅÍ ¸¸µåÈÄ ±æÀÌ¸¦ ´Ã·ÁÁÝ´Ï´Ù^^
		stTemp = stTemp * 270.0f;
		m_stClickDestPos[nIndex] = stTemp;
	}
}
void CBullet::Disable(int nIndex)
{
	if (m_pAnimation[nIndex] != NULL)
	{
		m_pAnimation[nIndex]->SetAlpha(1);
		m_pAnimation[nIndex]->SetPos(-1000.0f, -300, 0.0f);
		/*m_pAnimation[nIndex]->SetSize(0.5f, 0.5f);*/
		m_pAnimation[nIndex]->SetLoopType(E_ANI_LOOP, 0, 4);
		if (m_pAnimation[nIndex]->GetCurFrameNumber() == 0)
		{
			m_pAnimation[nIndex]->SetPause(TRUE);
		}
		m_pAnimation[nIndex]->SetShow(FALSE);

		//m_stClickDestPos[nIndex] = NULL;
		g_GMng.m_nPlayAni[nIndex] = 0;

		m_pSheldH[nIndex]->SetPos(-1000.0f, -300, 0.0f);
		/*m_pAnimation[nIndex]->SetSize(0.5f, 0.5f);*/
		m_pSheldH[nIndex]->SetLoopType(E_ANI_LOOP, 0, 4);
		if (m_pSheldH[nIndex]->GetCurFrameNumber() == 0)
		{
			m_pSheldH[nIndex]->SetPause(TRUE);
		}
		m_pSheldH[nIndex]->SetShow(FALSE);
	}
}
void CBullet::CreateObj(CRootScene* pScene, stdEMString stTemp, int nIndex, int nIndx2, int k)
{
	for (int i = 0; i < D_BULLET_MAX - nIndex; i++)
	{

		m_pAnimation[i] = new CEMAnimation(5);
		m_pSheldH[i] = new CEMAnimation(5);
		if (k == 1)
		{
			m_pAnimation[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/µü 1.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/µü 2.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/µü 3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/µü 4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/µü 1.png",
				GL_REPEAT, GL_NEAREST);
			m_pSheldH[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/µü Èí¼ö 1.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/µü Èí¼ö 2.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/µü Èí¼ö 3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/µü Èí¼ö 4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/µü Èí¼ö 5.png",
				GL_REPEAT, GL_NEAREST);
			m_pAnimation[i]->SetSize(1.0f, 1.0f);
		}
		else if (k == 2)
		{
			m_pAnimation[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¸Á 1.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¸Á 2.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¸Á 3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¸Á 4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¸Á 1.png",
				GL_REPEAT, GL_NEAREST);
			m_pSheldH[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¸Á Èí¼ö 1.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¸Á Èí¼ö 2.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¸Á Èí¼ö 3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¸Á Èí¼ö 4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¸Á Èí¼ö 5.png",
				GL_REPEAT, GL_NEAREST);
			m_pAnimation[i]->SetSize(1.0f, 1.0f);
		}
		else if (k == 3)
		{
			m_pAnimation[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¼¦ 1.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¼¦ 2.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¼¦ 3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¼¦ 4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/¼¦ 1.png",
				GL_REPEAT, GL_NEAREST);
			m_pSheldH[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¼¦ Èí¼ö 1.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¼¦ Èí¼ö 2.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¼¦ Èí¼ö 3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¼¦ Èí¼ö 4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/¼¦ Èí¼ö 5.png",
				GL_REPEAT, GL_NEAREST);
			m_pAnimation[i]->SetSize(1.0f, 1.0f);
		}
		else if (k == 4)
		{
			m_pAnimation[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/º¸½º 1.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/º¸½º 2.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/º¸½º 3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/º¸½º 4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/Àû ÃÑ¾Ë/º¸½º 1.png",
				GL_REPEAT, GL_NEAREST);
			m_pSheldH[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/º¸½º Èí¼ö 1.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/º¸½º Èí¼ö 2.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/º¸½º Èí¼ö 3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/º¸½º Èí¼ö 4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/º¸È£¸· Èí¼ö ÀÌÆåÆ®/º¸½º Èí¼ö 5.png",
				GL_REPEAT, GL_NEAREST);
			m_pAnimation[i]->SetSize(1.0f, 1.0f);
		}
		else
		{
			m_pAnimation[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/5.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/6.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/3.png",
				GL_REPEAT, GL_NEAREST);
			m_pSheldH[i]->SetTexture(pScene, 5,
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/4.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/W 1.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/W 2.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/W 3.png",
				"Data/Image/ÀÌÆåÆ®/ÃÑ¾Ë/ÃÑ¾Ë/W 4.png",
				GL_REPEAT, GL_NEAREST);
			m_pAnimation[i]->SetSize(0.5f, 0.5f);
			m_pSheldH[i]->SetSize(0.5f, 0.5f);
		}
		m_pAnimation[i]->SetPos(-1000.0f, -300, 0.0f);
		//m_pAnimation[i]->SetSize(1.0f, 1.0f);
		m_pAnimation[i]->SetShow(FALSE);
		m_pAnimation[i]->SetBlend(TRUE);
		m_pAnimation[i]->SetBoundingBoxCalc(TRUE);
		m_pAnimation[i]->SetFrstumCullingFlag(FALSE);
		m_pAnimation[i]->SetTime(0.1f);
		m_pAnimation[i]->SetBoundingSphereRadius(-20.0f);
		//m_pAnimation[i]->SetBoundingSphereOffset(10,0);
		m_pAnimation[i]->SetPause(TRUE);
		stdEMString stTemp2 = stTemp + IntToEMString(i);
		pScene->Commit(nIndx2, stTemp2, m_pAnimation[i]);

		m_pSheldH[i]->SetPos(-1000.0f, -300, 0.0f);
		//m_pAnimation[i]->SetSize(1.0f, 1.0f);
		m_pSheldH[i]->SetShow(FALSE);
		m_pSheldH[i]->SetBlend(TRUE);
		m_pSheldH[i]->SetBoundingBoxCalc(FALSE);
		m_pSheldH[i]->SetFrstumCullingFlag(FALSE);
		m_pSheldH[i]->SetTime(0.1f);
		m_pSheldH[i]->SetBoundingSphereRadius(-20.0f);
		//m_pAnimation[i]->SetBoundingSphereOffset(10,0);
		m_pSheldH[i]->SetPause(TRUE);
		stTemp2 = stTemp + "sheld" + IntToEMString(i);
		pScene->Commit(nIndx2, stTemp2, m_pSheldH[i]);
		m_stHeroDirVec3 = stEMVec3(0.0f, 1.0f, 0.0f);
		m_nWho = k;
	}
	//m_BulletSnd = D_SOUND->FileOpen("Data/Sound/")

	m_nMinusBullet = D_BULLET_MAX - nIndex;
	m_pScene = pScene;
}

void CBullet::Effect(int i)
{
	m_pAnimation[i]->SetPause(FALSE);
}
void CBullet::Move(float dt, int nType)
{
	for (int i = 0; i < m_nMinusBullet; i++)
	{
		if (m_pAnimation[i]->GetShow() == TRUE)
		{
			if (!m_pAnimation[i]->GetPause())
			{

				m_stClickDestPos[i] = stEMVec3(0.0f, 0.0f, 0.0f);

			}
			if (m_pAnimation[i]->GetCurFrameNumber() == 4 || m_pSheldH[i]->GetCurFrameNumber() == 4)
			{
				Disable(i);
			}
			stEMVec3 stCalsPos = m_pAnimation[i]->GetPosVec3();
			m_pAnimation[i]->Move(m_fSpeed, m_stClickDestPos[i]);//¼Óµµ, ¹æÇâº¤ÅÍ
			m_pSheldH[i]->Move(m_fSpeed, m_stClickDestPos[i]);
			CEMAnimation* m_pCurAni = NULL;
			switch (nType)
			{
			case 0:

				m_pCurAni = (CEMAnimation*)m_pScene->IsCollision(E_SPHERE_VS_SPHERE, m_pAnimation[i], nType);
				if (m_pCurAni != NULL)
				{
					if (g_GMng.m_bHitHero)
					{

					}
					else
					{
						if (g_GMng.m_bSkillOn)
						{
							if (m_pSheldH[i]->GetShow() == FALSE)
							{
								if (g_GMng.m_nBullet < 40)
								{
									g_GMng.m_nBullet += 3;
									if (g_GMng.m_nBullet > 40)
									{
										g_GMng.m_nBullet = 40;
									}
								}
								g_GMng.m_nScore += 50;
								m_stClickDestPos[i] = stEMVec3(0.0f, 0.0f, 0.0f);
								m_pAnimation[i]->SetAlpha(0);
								m_pSheldH[i]->SetShow(TRUE);
								m_pSheldH[i]->SetPause(FALSE);
							}
						}
						else
						{
							if (!g_GMng.m_bF9)
							{
								g_GMng.m_nHeroHP -= 1;
								m_pAnimation[i]->SetPause(FALSE);
								m_nPlayAni[i] = 0;
								g_GMng.m_bHitHero = TRUE;
								g_GMng.m_bShakeFlag = TRUE;
								Dprintf("ÇöÀçÇÇ %d", g_GMng.m_nHeroHP);
								
							}
						}
					}
				}
				break;
			}

			Clipping(i);
		}
	}
}

void CBullet::DestDirAngleCalc(stMouseInfo stPos)
{

}


void CBullet::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton, CHero Hero)
{
	for (int i = 0; i < m_nMinusBullet; i++)
	{
		if (m_pAnimation[i]->GetShow() == TRUE)
		{

			switch (eButton)
			{
			case E_MOUSE_LEFT:
			{
				if (m_pAnimation[i]->GetShow() == false)
				{
					// ¸¶¿ì½º ÁÂÇ¥¸¦ ¿ùµå ÁÂÇ¥·Î º¯È¯ÇÕ´Ï´Ù.^^

				}
			}break;
			}
		}
	}

}

void CBullet::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton, CHero Hero)
{

}

void CBullet::MouseMoveEvent(stMouseInfo stPos, CHero* Hero)
{

	stEMVec2 stDesPos(0.0f, 0.0f);

	// ¸¶¿ì½º ÁÂÇ¥¸¦ ¿ùµå ÁÂÇ¥·Î º¯È¯ÇÕ´Ï´Ù.^^
	stDesPos = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

	m_stDestPos = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);
	//m_pTextYe->SetOutPutString(FloatToEMString(stDesPos.m_fX) + " " + FloatToEMString(stDesPos.m_fY) + " " + FloatToEMString(0.0f));

	//DestDirAngleCalc(stPos);
}
void CBullet::Clipping(int i)
{

	if (m_pAnimation[i]->GetBoundingBox().stRT.m_fY < -600)
	{
		m_stClickDestPos[i] = stEMVec3(0.0f, 0.0f, 0.0f);
		m_pAnimation[i]->SetPause(FALSE);
		m_nPlayAni[i] = 0;
		if (m_nWho == 7)
		{
			m_pSheldH[i]->SetShow(TRUE);
			m_pSheldH[i]->SetPause(FALSE);
			m_pAnimation[i]->SetAlpha(0);
			m_pSheldH[i]->SetZRot(-90);
		}
		else
		{
			m_pAnimation[i]->SetZRot(90);
		}
	}
	if (m_pAnimation[i]->GetBoundingBox().stLB.m_fY > -100)
	{
		m_stClickDestPos[i] = stEMVec3(0.0f, 0.0f, 0.0f);
		m_pAnimation[i]->SetPause(FALSE);
		m_nPlayAni[i] = 0;
		if (m_nWho == 7)
		{
			m_pSheldH[i]->SetShow(TRUE);
			m_pSheldH[i]->SetPause(FALSE);
			m_pAnimation[i]->SetAlpha(0);
			m_pSheldH[i]->SetZRot(90);
		}
		else
		{
			m_pAnimation[i]->SetZRot(-90);
		}
	}
}