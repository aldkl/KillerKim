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
	D_WORLD->WorldInit("킬러킴", 1280, 720, TRUE);	//!< 월드를 설정합니다
	D_WORLD->SetBackColor(CEMColor(100, 100, 100));										//!< 배경색을 지정합니다.
	//D_WORLD->Commit(new CEMGrid());													//!< 그리드 추가합니다.
	//D_WORLD->SetBoundingBoxShowFlag(true);											//!< 바운딩 박스 보여주게합니다
	//D_WORLD->SetPhysicBoundingBoxShowFlag(true);
	D_WORLD->SetFpsShowFlag(false);

	D_WORLD->SetMouseCursor("data/image/Mouse/mpt.png",
							stEMOffset(0.0f, 0.0f),
							"data/image/Mouse/mpt.png",
							stEMOffset(0.0f, 0.0f),			//!< 그림 의 맨왼쪽위로 offset이 이동해야하므로 그림 사이즈(32) - 16만큼 해주면 됩니다
							1.0f);
	

	//D_SCENE->Commit(new CUI_Popup, "UI_Popup);
	D_SCENE->Commit(new CLogoScene, "logo");
	D_SCENE->Commit(new CMenuScene_Ext, "menu_ext");
	D_SCENE->Commit(new CGameScene, "game");
	D_SCENE->Commit(new CResultScene, "result");
	D_SCENE->Commit(new CTestScene, "Test");
	
	D_SCENE->ChangeScene("logo");									//!< 이거안해주면 기본 logo씬으로 자동 갑니다.
	
	//MoveWindow(D_WORLD->GetWinHandle(), 500, 100, 1280, 720, TRUE);
	D_WORLD->RunLoop();

	return 1;
}
