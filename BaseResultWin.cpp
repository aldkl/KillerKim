#include "stdafx.h"

void CBaseResultWin::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();

	//====================================================
	// ���
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/���/������.png");
	m_pBg->SetSize(1.0f);
	m_pBg->SetPos(stEMVec3(0, 0, 0));
	m_pBg->SetBlend(false);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "A_Background", m_pBg);

	//===================================================
	// �ٽý��� ��ư

	m_Btns[0].pUI[1] = new CEMPlane();
	m_Btns[0].pUI[1]->SetTexture("Data/Image/�޴�/���ӽ��۹�ư1.png");
	m_Btns[0].pUI[1]->SetPos(stEMVec3(-250, -100, 0));
	m_Btns[0].pUI[1]->SetBoundingBox_LTLB_Size(-120);
	m_Btns[0].pUI[1]->SetBoundingBox_RTRB_Size(120);
	m_Btns[0].pUI[1]->SetBoundingBox_LTRT_Size(15);
	m_Btns[0].pUI[1]->SetBoundingBox_LBRB_Size(-15);
	m_Btns[0].pUI[1]->SetBlend(true);
	m_Btns[0].pUI[1]->SetBackFaceCulling(true);
	m_Btns[0].pUI[1]->SetSize(1.0f);
	m_Btns[0].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_PlayTxt", m_Btns[0].pUI[1]);

	//====================================================
	// ������ ��ư

	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/�޴�/���ӳ���ư1.png");
	m_Btns[1].pUI[1]->SetPos(stEMVec3(250, -100, 0));
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetSize(1.0f);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_ExitTxt", m_Btns[1].pUI[1]);


	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CBaseResultWin::OnMouseMoveEvent(stMouseInfo stPos)
{
	if (GetCollisionFlag())
	{
		stEMVec2 stPosVec2 = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

		// ���� üũ
		m_pSelectPlane = m_pScene->AABBvsRay(stPos.m_nX, stPos.m_nY, m_nLayer);

		// ���콺 �̵��ø��� ���������� �����ϰ� �ϴ� �ڵ� �Դϴ�. 
		if (m_pPrevSelectPlane != NULL && m_pSelectPlane != NULL)
		{
			if (m_pSelectPlane != m_pPrevSelectPlane)
			{
				m_pPrevSelectPlane->SetColor(1, 1, 1, 1);
			}
		}

		if (m_pSelectPlane)
		{
			// ���õǾ����� ����Դϴ�.
			m_pPrevSelectPlane = m_pSelectPlane;

			// D�� �����ϴ� Plane�� ���������� �����ϰ� �ϴ� �ڵ� �Դϴ�. 
			if (m_pSelectPlane->GetName().c_str()[0] != 'D')
			{
				if (m_pPrevSelectPlane)
					m_pPrevSelectPlane->SetColor(1, 1, 1, 1);
			}
			else
			{
				m_pSelectPlane->SetColor((float)246 / 255, (float)198 / 255, (float)53 / 255, 1);
			}
		}
	}
}

void CBaseResultWin::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	if (GetCollisionFlag())
	{
		switch (eButton)
		{
		case E_MOUSE_LEFT:
		{
			stEMVec2 stPosVec2 = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

			// ���� üũ
			m_pSelectPlane = m_pScene->AABBvsRay(stPos.m_nX, stPos.m_nY, m_nLayer);

			if (m_pSelectPlane)
			{
				if (m_pSelectPlane->GetName() == "D_PlayTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					Dprintf("play\n");

					D_SCENE->ChangeSceneFade("menu_ext");

				}

				if (m_pSelectPlane->GetName() == "D_ExitTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					Dprintf("ExitBtn\n");

					D_WORLD->WindowsDestroy();
				}

			}
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
		}
	}

}