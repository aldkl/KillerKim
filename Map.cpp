#include "stdafx.h"

CMap::CMap()
{

}
CMap::~CMap()
{

}

void CMap::Update(float dt)
{

}
void CMap::Disable()
{

}
void CMap::CreateObj(CRootScene* pScene)
{

	//m_pPlane->SetLifeTime(1.0f);


	for (int i = 0; i < D_ROOM_MAX; i++)
	{
		m_ClippingHero[i] = new CEMAnimation(3);
		m_ClippingHero[i]->SetPos(640.0f + 1280 * i, -360.0f, 0.0f);
		m_ClippingHero[i]->SetSize(1.0f, 1.0f);
		m_ClippingHero[i]->SetColor(255, 255, 255);
		m_ClippingHero[i]->SetTexture(pScene, 3,
			"Data/Image/Map/1스테이지.png",
			"Data/Image/Map/2스테이지.png",
			"Data/Image/Map/3스테이지.png",
			GL_REPEAT, GL_NEAREST);
		m_ClippingHero[i]->SetLoopType(E_ANI_LOOP, 0, 0);
		m_ClippingHero[i]->SetTime(1.0f);
		m_ClippingHero[i]->SetBoundingBoxOffset(-50, -50);
		//m_ClippingHero[i]->SetBoundingBox(
		//	stEMVec3(150.0f + 1280.0f * i, -100.0f, 0.0f),
		//	stEMVec3(150.0f + 1280.0f * i, -620.0f, 0.0f),
		//	stEMVec3(1150.0f + 1280.0f * i, -100.0f, 0.0f),
		//	stEMVec3(1150.0f + 1280.0f * i, -620.0f, 0.0f));
		m_ClippingHero[i]->SetFrstumCullingFlag(false);
		m_ClippingHero[i]->SetBlend(true);
		m_ClippingHero[i]->SetBoundingBoxCalc(true);
		m_ClippingHero[i]->SetBoundingBox_LBRB_Size(110);
		m_ClippingHero[i]->SetBoundingBox_LTLB_Size(120);
		m_ClippingHero[i]->SetBoundingBox_LTRT_Size(-50);
		m_ClippingHero[i]->SetBoundingBox_RTRB_Size(-120);
		if (i < D_DOOR_MAX)
		{
			m_Door[i] = new CEMAnimation(10);

			m_Door[i]->SetColor(255, 255, 255);
			m_Door[i]->SetBoundingBoxOffset(-50, -50);
			m_Door[i]->SetSize(1.0f, 1.0f);
			m_Door[i]->SetTexture(pScene, 10,
				"Data/Image/Map/1스테이지 문/1.png",		  //0
				"Data/Image/Map/1스테이지 문/2.png",		  //1
				"Data/Image/Map/1스테이지 문/3.png",		  //2
				"Data/Image/Map/1스테이지 문/4.png",		  //3
				"Data/Image/Map/1스테이지 문/4.png",		  //4
				"Data/Image/Map/2스테이지 문/1.png",		  //5
				"Data/Image/Map/2스테이지 문/2.png",		  //6
				"Data/Image/Map/2스테이지 문/3.png",		  //7
				"Data/Image/Map/2스테이지 문/4.png",		  //8
				"Data/Image/Map/2스테이지 문/4.png",		  //9
				GL_REPEAT, GL_NEAREST
			);
			m_Door[i]->SetTime(0.2f);
			m_Door[i]->SetLoopType(E_ANI_ONE, 0, 4, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
			m_Door[i]->SetPause(true);
			m_Door[i]->SetFrstumCullingFlag(FALSE);
			m_Door[i]->SetBlend(true);
			m_Door[i]->SetBoundingBoxCalc(true);
			m_Door[i]->SetBoundingBox_LBRB_Size(0);
			m_Door[i]->SetBoundingBox_LTLB_Size(-20);
			m_Door[i]->SetBoundingBox_LTRT_Size(0);
			m_Door[i]->SetBoundingBox_RTRB_Size(-20);
			m_Door[i]->SetPos(-1210.0f, -350.0f, 0.0f);
			if (i < 5)
			{
				m_Door[i]->SetPos(1210.0f + i * 1280, -350.0f, 0.0f);

			}
		}
	}

	//m_Door[1]->SetPos(1210.0f + 1280, -350.0f, 0.0f);
	//m_Door[2]->SetPos(1210.0f + 2560, -350.0f, 0.0f);
	//m_Door[3]->SetPos(1210.0f + 3840, -350.0f, 0.0f);
	//m_Door[4]->SetPos(1210.0f + 5120, -350.0f, 0.0f);

	for (int i = 0; i < D_ROOM_MAX; i++)
	{

		stdEMString stTemp;
		if (i < D_DOOR_MAX)
		{
			stTemp = "Door" + IntToEMString(i);
			pScene->Commit(59, stTemp, m_Door[i]);
		}
		stTemp = "ClippingHero" + IntToEMString(i);
		pScene->Commit(59, stTemp, m_ClippingHero[i]);
	}

}