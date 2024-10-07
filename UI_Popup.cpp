#include "stdafx.h"

void CUI_Popup::Enter(CSceneWork* pSceneWork)
{
	//====================================================
	//! �۾� ���
	m_pTextYe = new CEMText("��10", "�ΰ��");
	m_pTextYe->SetSize(1.7f);
	m_pTextYe->SetPos(400.0f, 24.0f*1.7f);
	Commit(0, "�׽�Ʈ", m_pTextYe);

	m_pWin = new CEMWindow("RadioButton", stEMRect(0,0,800,600), this, CEMColor(1.0f, 1.0f, 1.0f, 0.0f));

	//! ���� ������ ���� ��ư �߰�
	m_pWin->AddButton(4,  "Data/image/ui/left_button_1.png",
						  "Data/image/ui/left_button_2.png", 
						  "Data/image/ui/left_button_3.png", 
						  stEMVec3(10.0f, 600.0f-95.0f, 0.0f));

	m_pWin->AddButton(5,  "Data/image/ui/right_button_1.png",
						  "Data/image/ui/right_button_2.png", 
						  "Data/image/ui/right_button_3.png", 
						  stEMVec3(800.0f-90.0f, 600.0f-95.0f, 0.0f));

	m_pWin->AddWindow("EditBox","Data/image/ui/1 (8).png", stEMVec3(400.0f-175.0f, 300.0f-147.0f,0.0f), CEMColor(1.0f, 1.0f, 1.0f, 1.0f));

	m_pWin->GetWindow("EditBox")->AddEditBox(1, "����ü",  stEMRect(0.0f, 0.0f, 150.0f, 24.0f)+stEMVec2(76.0f, 200.0f));
	m_pWin->GetWindow("EditBox")->AddEditBox(2, "����ü",  stEMRect(0.0f, 0.0f, 150.0f, 24.0f)+stEMVec2(76.0f, 229.0f));
	m_pWin->GetWindow("EditBox")->GetEditBox(2)->SetPassWord(true);			//!< 2���� edit box�� *�� ����ϱ�
	m_pWin->GetWindow("EditBox")->GetEditBox(1)->SetFocus(true);			//!< 1�� Edit Box ��Ŀ����

	m_pWin->GetWindow("EditBox")->AddButton(3, "Data/Image/ui/1 (4).png", 
												"Data/Image/ui/2 (7).png", 
												"Data/Image/ui/3 (3).png", 
												stEMVec3(245.0f, 193.0f, 0.0f));

	m_pWin->GetWindow("EditBox")->AddStatic(4, "��10", "1. ���̵�� �н����带 �Է��ϼ���", stEMVec3(14.0f, 44.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox")->AddStatic(5, "��10", "2. ���̵�� ����(�ҹ���) 10�ڸ�", stEMVec3(14.0f, 85.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox")->AddStatic(6, "��10", "3. �н������ (�ҹ���) 5�ڸ�", stEMVec3(14.0f, 122.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox")->SetLock(E_STATIC);
	
	m_pWin->AddWindow("EditBox2","Data/image/ui/1 (8).png", stEMVec3(100.0f-175.0f, 100.0f-147.0f,0.0f), CEMColor(1.0f, 1.0f, 1.0f, 1.0f));

	m_pWin->GetWindow("EditBox2")->AddEditBox(1, "����ü",  stEMRect(0.0f, 0.0f, 150.0f, 24.0f)+stEMVec2(76.0f, 200.0f));
	m_pWin->GetWindow("EditBox2")->AddEditBox(2, "����ü",  stEMRect(0.0f, 0.0f, 150.0f, 24.0f)+stEMVec2(76.0f, 229.0f));
	m_pWin->GetWindow("EditBox2")->GetEditBox(2)->SetPassWord(true);			//!< 2���� edit box�� *�� ����ϱ�
	m_pWin->GetWindow("EditBox2")->GetEditBox(1)->SetFocus(true);			//!< 1�� Edit Box ��Ŀ����

	m_pWin->GetWindow("EditBox2")->AddButton(3, "Data/Image/ui/1 (4).png", 
												"Data/Image/ui/2 (7).png", 
												"Data/Image/ui/3 (3).png", 
												stEMVec3(245.0f, 193.0f, 0.0f));

	m_pWin->GetWindow("EditBox2")->AddStatic(4, "��10", "1. ���̵�� �н����带 �Է��ϼ���", stEMVec3(14.0f, 44.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox2")->AddStatic(5, "��10", "2. ���̵�� ����(�ҹ���) 10�ڸ�", stEMVec3(14.0f, 85.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox2")->AddStatic(6, "��10", "3. �н������ (�ҹ���) 5�ڸ�", stEMVec3(14.0f, 122.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox2")->SetLock(E_STATIC);

	Commit(m_pWin, E_STATIC);
}

void CUI_Popup::Update(CSceneWork* pSceneWork, float dt)
{
	//if (D_INPUT->IsKeyUp(VK_LEFT))
	//{

	//	m_stWinPos = m_stLeftDestPos;
	//}

	//if (D_INPUT->IsKeyUp(VK_UP))
	//{
	//	m_stWinPos = m_stCenterDestPos;
	//}

	//if (D_INPUT->IsKeyUp(VK_RIGHT))
	//{
	//	m_stWinPos = m_stRightDestPos;
	//}

	//stEMVec3 stWinPos = m_pWin->GetPos();
	//stWinPos = CEMMath::Lerp(stWinPos, m_stWinPos, 5*dt);
	//m_pWin->SetPos(stWinPos);
	D_CAMERA->SetPos(640.0f, -360.0f, 620.0f);

	CRootScene::Update(pSceneWork, dt);
}

void CUI_Popup::Render(CSceneWork* pSceneWork)
{
	
	CRootScene::Render(pSceneWork);
}

void CUI_Popup::Exit(CSceneWork* pSceneWork)
{
	Destroy();
	TwDeleteBar(m_pBar);
}

void CUI_Popup::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	switch(eButton)
	{
	case E_MOUSE_LEFT:
		{

		}break;
	}
}

void CUI_Popup::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{

}

void CUI_Popup::MouseMoveEvent(stMouseInfo stPos)
{

}

void CUI_Popup::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{
	CEMWindow* pWin = NULL;
	pWin = GetUI("RadioButton");
	//pWin->SetLock(E_DYNAMIC);

	if (sWindowName == "EditBox")
	{
		switch (eType)
		{
			case E_BUTTON:
			{
				switch (id)
				{
					case 3:
					{
						Dprintf("�˾�â ��ư 3�� ����\n");

						CEMWindow* pWindow = NULL;
						pWindow = pWin->GetWindow(sWindowName.c_str());

						//if(pWindow)
						//	pWindow->SetVisible(false);

						if (pWindow)
							pWindow->SetPos(stEMVec3(-900.0f, 0.0f, 0.0f));

						//pWin->GetWindow(sWindowName.c_str())->GetEditBox(1)->Clear();
						//pWin->GetWindow(sWindowName.c_str())->GetEditBox(2)->Clear();
					}break;
				}
			}break;
		}
	}

	if (sWindowName == "RadioButton")
	{
		switch (eType)
		{
			case E_BUTTON:
			{
				switch (id)
				{
				case 4:
				{
					Dprintf("4�� ����\n");
					//D_SCENE->ChangeScene("RadioUI");
				}break;

				case 5:
				{
					Dprintf("5�� ����\n");
					// D_SCENE->ChangeScene("CheckUI");
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

HRESULT CUI_Popup::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_LBUTTONDOWN:
		{
			int x = 0;
		}break;
	}

	return msg;
}