#include "stdafx.h"

void CUI_Popup::Enter(CSceneWork* pSceneWork)
{
	//====================================================
	//! 글씨 출력
	m_pTextYe = new CEMText("정10", "로고씬");
	m_pTextYe->SetSize(1.7f);
	m_pTextYe->SetPos(400.0f, 24.0f*1.7f);
	Commit(0, "테스트", m_pTextYe);

	m_pWin = new CEMWindow("RadioButton", stEMRect(0,0,800,600), this, CEMColor(1.0f, 1.0f, 1.0f, 0.0f));

	//! 다음 페이지 가는 버튼 추가
	m_pWin->AddButton(4,  "Data/image/ui/left_button_1.png",
						  "Data/image/ui/left_button_2.png", 
						  "Data/image/ui/left_button_3.png", 
						  stEMVec3(10.0f, 600.0f-95.0f, 0.0f));

	m_pWin->AddButton(5,  "Data/image/ui/right_button_1.png",
						  "Data/image/ui/right_button_2.png", 
						  "Data/image/ui/right_button_3.png", 
						  stEMVec3(800.0f-90.0f, 600.0f-95.0f, 0.0f));

	m_pWin->AddWindow("EditBox","Data/image/ui/1 (8).png", stEMVec3(400.0f-175.0f, 300.0f-147.0f,0.0f), CEMColor(1.0f, 1.0f, 1.0f, 1.0f));

	m_pWin->GetWindow("EditBox")->AddEditBox(1, "으뜸체",  stEMRect(0.0f, 0.0f, 150.0f, 24.0f)+stEMVec2(76.0f, 200.0f));
	m_pWin->GetWindow("EditBox")->AddEditBox(2, "으뜸체",  stEMRect(0.0f, 0.0f, 150.0f, 24.0f)+stEMVec2(76.0f, 229.0f));
	m_pWin->GetWindow("EditBox")->GetEditBox(2)->SetPassWord(true);			//!< 2번재 edit box는 *로 출력하기
	m_pWin->GetWindow("EditBox")->GetEditBox(1)->SetFocus(true);			//!< 1번 Edit Box 포커스염

	m_pWin->GetWindow("EditBox")->AddButton(3, "Data/Image/ui/1 (4).png", 
												"Data/Image/ui/2 (7).png", 
												"Data/Image/ui/3 (3).png", 
												stEMVec3(245.0f, 193.0f, 0.0f));

	m_pWin->GetWindow("EditBox")->AddStatic(4, "정10", "1. 아이디와 패스워드를 입력하세요", stEMVec3(14.0f, 44.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox")->AddStatic(5, "정10", "2. 아이디는 영문(소문자) 10자리", stEMVec3(14.0f, 85.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox")->AddStatic(6, "정10", "3. 패스워드는 (소문자) 5자리", stEMVec3(14.0f, 122.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox")->SetLock(E_STATIC);
	
	m_pWin->AddWindow("EditBox2","Data/image/ui/1 (8).png", stEMVec3(100.0f-175.0f, 100.0f-147.0f,0.0f), CEMColor(1.0f, 1.0f, 1.0f, 1.0f));

	m_pWin->GetWindow("EditBox2")->AddEditBox(1, "으뜸체",  stEMRect(0.0f, 0.0f, 150.0f, 24.0f)+stEMVec2(76.0f, 200.0f));
	m_pWin->GetWindow("EditBox2")->AddEditBox(2, "으뜸체",  stEMRect(0.0f, 0.0f, 150.0f, 24.0f)+stEMVec2(76.0f, 229.0f));
	m_pWin->GetWindow("EditBox2")->GetEditBox(2)->SetPassWord(true);			//!< 2번재 edit box는 *로 출력하기
	m_pWin->GetWindow("EditBox2")->GetEditBox(1)->SetFocus(true);			//!< 1번 Edit Box 포커스염

	m_pWin->GetWindow("EditBox2")->AddButton(3, "Data/Image/ui/1 (4).png", 
												"Data/Image/ui/2 (7).png", 
												"Data/Image/ui/3 (3).png", 
												stEMVec3(245.0f, 193.0f, 0.0f));

	m_pWin->GetWindow("EditBox2")->AddStatic(4, "정10", "1. 아이디와 패스워드를 입력하세요", stEMVec3(14.0f, 44.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox2")->AddStatic(5, "정10", "2. 아이디는 영문(소문자) 10자리", stEMVec3(14.0f, 85.0f, 0.0f), 0.8f);
	m_pWin->GetWindow("EditBox2")->AddStatic(6, "정10", "3. 패스워드는 (소문자) 5자리", stEMVec3(14.0f, 122.0f, 0.0f), 0.8f);
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
						Dprintf("팝업창 버튼 3번 눌림\n");

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
					Dprintf("4번 눌림\n");
					//D_SCENE->ChangeScene("RadioUI");
				}break;

				case 5:
				{
					Dprintf("5번 눌림\n");
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