#pragma once
enum
{
	E_SND_MAIN,
	E_SND_STAGE1,
	E_SND_STAGE2,
	E_SND_STAGE3,
	E_SND_BOSS,
	E_SND_GAMEOVER,
	E_SND_MAX
};
enum
{
	E_FXSND_CLICK,
	E_FXSND_DOORUP,
	E_FXSND_DOORDOWN,
	E_FXSND_HEROFIRE,
	E_FXSND_DOOR1,
	E_FXSND_DOOR2,
	E_FXSND_END,
	E_FXSND_BOOSDIE,
	E_FXSND_BARRIER,
	E_FXSND_MAX
};

#define D_UI_MAX 2
#define D_BTN_MAX 10
//============================================
// define
#define D_BULLET_MAX 30
#define D_SE_MAX 5
#define D_ME_MAX 3
#define D_PE_MAX 4
#define D_DOOR_MAX 7
#define D_ROOM_MAX 8
#define D_EBULLET_MAX 20
#define D_ENEMY_MAX D_PE_MAX + D_SE_MAX + D_ME_MAX
//keys
#define VK_0           0x30
#define VK_1           0x31
#define VK_2           0x32
#define VK_3           0x33
#define VK_4           0x34
#define VK_5           0x35
#define VK_6           0x36
#define VK_7           0x37
#define VK_8           0x38
#define VK_9           0x39
/*
 * 0x3A - 0x40 : unassigned
 */
#define VK_A           0x41
#define VK_B           0x42
#define VK_C           0x43
#define VK_D           0x44
#define VK_E           0x45
#define VK_F           0x46
#define VK_G           0x47
#define VK_H           0x48
#define VK_I           0x49
#define VK_J           0x4A
#define VK_K           0x4B
#define VK_L           0x4C
#define VK_M           0x4D
#define VK_N           0x4E
#define VK_O           0x4F
#define VK_P           0x50
#define VK_Q           0x51
#define VK_R           0x52
#define VK_S           0x53
#define VK_T           0x54
#define VK_U           0x55
#define VK_V           0x56
#define VK_W           0x57
#define VK_X           0x58
#define VK_Y           0x59
#define VK_Z           0x5A
 //============================================



#include "EM2DEngine.h"

#include "Mng.h"
#include "manager.h"
#include "Unit.h"

#include "Hero.h"
#include "Effect.h"
#include "Bullet.h"
#include "Monster.h"
#include "MachinegunEnemy.h"
#include "ShotgunEnemy.h"
#include "PistolEnemy.h"
#include "BossEnemy.h"
#include "MiniBoss.h"
#include "Num.h"
#include "Map.h"
#include "UI.h"
#include "PopupWinRoot.h"
#include "ExitPopupWin.h"
#include "SettingPopupWin.h"
#include "BaseMenuWin.h"
#include "BaseResultWin.h"
#include "GameScene_BaseUI.h"
#include "GotoMenuPopupWin.h"
#include "SetPlayer.h"

#include "UI_Popup.h"
#include "LogoScene.h"
#include "MenuScene_Ext.h"
#include "ResultScene.h"
#include "GameScene.h"
#include "TestScene.h"
extern CGameMng g_GMng;

//========================================================
// 메니져
#define D_MNG	CMng::Instance()			//!< 메니져

