#include "stdafx.h"
#define CRTDBG_MAP_ALLOC

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

CGameMng g_GMng;

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE, LPSTR,  int)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	D_WORLD->WorldInit("ų��Ŵ", 1280, 720, TRUE);	//!< ���带 �����մϴ�
	D_WORLD->SetBackColor(CEMColor(100, 100, 100));										//!< ������ �����մϴ�.
	//D_WORLD->Commit(new CEMGrid());													//!< �׸��� �߰��մϴ�.
	//D_WORLD->SetBoundingBoxShowFlag(true);											//!< �ٿ�� �ڽ� �����ְ��մϴ�
	//D_WORLD->SetPhysicBoundingBoxShowFlag(true);
	D_WORLD->SetFpsShowFlag(false);

	D_WORLD->SetMouseCursor("data/image/Mouse/mpt.png",
							stEMOffset(0.0f, 0.0f),
							"data/image/Mouse/mpt.png",
							stEMOffset(0.0f, 0.0f),			//!< �׸� �� �ǿ������� offset�� �̵��ؾ��ϹǷ� �׸� ������(32) - 16��ŭ ���ָ� �˴ϴ�
							1.0f);
	

	//D_SCENE->Commit(new CUI_Popup, "UI_Popup);
	D_SCENE->Commit(new CLogoScene, "logo");
	D_SCENE->Commit(new CMenuScene_Ext, "menu_ext");
	D_SCENE->Commit(new CGameScene, "game");
	D_SCENE->Commit(new CResultScene, "result");
	D_SCENE->Commit(new CTestScene, "Test");
	
	D_SCENE->ChangeScene("logo");									//!< �̰ž����ָ� �⺻ logo������ �ڵ� ���ϴ�.
	
	//MoveWindow(D_WORLD->GetWinHandle(), 500, 100, 1280, 720, TRUE);
	D_WORLD->RunLoop();

	return 1;
}
