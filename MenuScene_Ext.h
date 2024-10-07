#pragma once

#include "stdafx.h"


class CMenuScene_Ext : public CRootScene , public UIEvent
{
private:
	CEMText*	m_pTextYe;
	CEMWindow*	m_pWin;
	CEMPlane*	m_pBgd;
	stEMVec3	m_stCamPos;			// ī�޶� ��ġ

private:
	TwBar* m_pBar;

public:
	CPopupWinRoot * m_pPwr;
	CEMPlane * m_pBg1;
	CEMPlane * m_pBg2;
	CEMPlane * m_pBg3;
	CEMPlane * m_pBg4;
	CEMPlane * m_pBg11;
	CEMPlane * m_pBg12;
	CEMPlane * m_pBg13;
	CEMPlane * m_pBg14;
	CEMPlane * m_pBg15;
	CEMPlane * m_pBg16;
	CEMPlane * m_pSound;
	CBaseMenuWin m_BaseMenuWin;
	CExitPopupWin m_ExitPopupWin;
	CSettingPopupWin m_SettingPopupWin;
	CEMWindow*  m_pMusicOnWin;
	CEMWindow*  m_pSoundOnWin;
	CEMWindow*  m_pMusicOffWin;
	CEMWindow*  m_pSoundOffWin;
	CEMWindow*  m_pMusicWin[6];
	CEMWindow*  m_pSoundWin[6];

public:
	CEMPlane * m_pSelectPlane;
	CEMPlane * m_pPrevSelectPlane;


	CEMPlane * m_pOption;
public:

	int			m_nMapIndex;
	int 		m_nMusicIndex;
	int			m_nSoundIndex;
	int			m_nSoundEx;
	int			m_nUpY;
	int			m_nDownY;
	float		m_fIndex;		//��Ϲ��� ȸ��
	float		m_fSceneCntTime;
	bool		m_bEngMove;		//���� Ű
	bool		m_bArwMove;		//ȭ��ǥ Ű
	bool        m_bTurn;
	bool		m_bSceneChange;
	bool		m_bMenuWin;
	bool		m_bMusicOn;




public:
	CMenuScene_Ext(void)
	{	
		m_pSelectPlane = NULL;
		m_pPrevSelectPlane = NULL;
		m_stCamPos.m_fX = 0.0f;
		m_stCamPos.m_fY = 0.0f;
		m_stCamPos.m_fZ = 620.0f;
		m_pWin = NULL;
		m_nMapIndex = 0;
		m_nMusicIndex = 5;
		m_nSoundIndex = 5;
		m_nSoundEx = 0;
		m_nUpY = 163;
		m_nDownY = 10;
		m_fSceneCntTime = 0.0f;
		m_fIndex = 0.0f;
		m_bEngMove = true;
		m_bArwMove = false;
		m_bTurn = true;
		m_bSceneChange = false;
		m_bMenuWin = false;
		m_bMusicOn = true;

	};

	virtual ~CMenuScene_Ext(void)
	{
		
	};


public:
	virtual void MusicChange();
	virtual void MapChange();
	virtual void Enter				(CSceneWork* pSceneWork);								//!< ����(�ε�)
	virtual void Update				(CSceneWork*, float dt);								//!< Update
	virtual void Render				(CSceneWork*);											//!< Render
	virtual void Exit				(CSceneWork* pSceneWork);								//!< Ż��(�޸� ������)
	virtual void MouseDownEvent 	(stMouseInfo stPos, enumMouseButton eButton);			//!< ���콺 �ٿ� �̺�Ʈ
	virtual void MouseUpEvent		(stMouseInfo stPos, enumMouseButton eButton);			//!< ���콺 �� �̺�Ʈ
	virtual void MouseMoveEvent 	(stMouseInfo stPos);									//!< ���콺 �̵� �̺�Ʈ
	virtual HRESULT WindowMessage	(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	//!< ������ �̺�Ʈ//!< ���콺 �̵� �̺�Ʈ

	virtual void CALLBACK OnEvent	(stdEMString sWindowName, enumDialogType eType, UINT id);
};