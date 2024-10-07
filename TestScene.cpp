#include "stdafx.h"

void CTestScene::Enter(CSceneWork* pSceneWork)
{
	D_CAMERA->SetPos(640.0f, -360.0f, 620.0f);

	m_pBlackground = new CEMPlane();
	CEMColor ColorBlackground;
	ColorBlackground.m_fR = 0.0f;
	ColorBlackground.m_fG = 0.0f;
	ColorBlackground.m_fB = 0.0f;
	ColorBlackground.m_fA = 1.0f;

	m_pBlackground->SetColor(ColorBlackground);
	m_pBlackground->SetPos(640.0f, -360.0f,0);
	//m_pBlackground->SetPos(-5000,500);
	m_pBlackground->SetSize(1, 1);
	m_pBlackground->SetBlend(true);
	m_pBlackground->SetShow(true);
	m_pBlackground->SetBoundingBoxCalc(FALSE);
	m_pBlackground->SetFrstumCullingFlag(FALSE);
	Commit(-1, "black", m_pBlackground);
}

void CTestScene::Update(CSceneWork* pSceneWork, float dt)
{
	if (D_INPUT->IsKeyUp(VK_F4))
	{
		D_SCENE->ChangeSceneFade("Test");
	}
	if (D_INPUT->IsKeyDown(VK_W))
	{
		m_pBlackground->MoveY(100 * D_WORLD->GetDeltaTime());
	}
	if (D_INPUT->IsKeyDown(VK_A))
	{
		m_pBlackground->MoveX(-100 * D_WORLD->GetDeltaTime());
	}
	if (D_INPUT->IsKeyDown(VK_S))
	{
		m_pBlackground->MoveY(-100 * D_WORLD->GetDeltaTime());
	}
	if (D_INPUT->IsKeyDown(VK_D))
	{
		m_pBlackground->MoveX(100 * D_WORLD->GetDeltaTime());
	}
	CRootScene::Update(pSceneWork, dt);
}

void CTestScene::Render(CSceneWork* pSceneWork)
{

	CRootScene::Render(pSceneWork);
}

void CTestScene::Exit(CSceneWork* pSceneWork)
{
	Destroy();
}

void CTestScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	stEMVec2 stDesPos(0.0f, 0.0f);

	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{


	}break;
	}
}

void CTestScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{
		Dprintf("Left Click Btn");
	}break;

	case E_MOUSE_RIGHT:
	{

	}break;
	}
}

void CTestScene::MouseMoveEvent(stMouseInfo stPos)
{


}

void CTestScene::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{

}

HRESULT CTestScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		int x = 0;
	}break;
	}

	return msg;
}