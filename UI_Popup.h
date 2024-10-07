#pragma once

#include "stdafx.h"

class CUI_Popup : public CRootScene, public UIEvent
{
private:
	CEMText*	m_pTextYe;
	stEMVec3	m_stCamPos;

private:
	CEMWindow*	m_pWin;



	stEMVec3 m_stLeftDestPos;
	stEMVec3 m_stCenterDestPos;
	stEMVec3 m_stRightDestPos;


	stEMVec3 m_stWinPos;

	TwBar* m_pBar;

public:
	CUI_Popup(void)
	{	
		m_stCamPos.m_fX 	= 0.0f;
		m_stCamPos.m_fY 	= 30.0f;
		m_stCamPos.m_fZ 	= 300.0f;
		m_pTextYe = NULL;
		m_pWin = NULL;

		m_stLeftDestPos.m_fX = -900;
		m_stLeftDestPos.m_fY = 0;
		m_stCenterDestPos.m_fX = 0;
		m_stCenterDestPos.m_fY = 0;
		m_stWinPos.m_fX = 0;
		m_stWinPos.m_fY = 0;
		m_stRightDestPos.m_fX = 900;
		m_stRightDestPos.m_fY = 0;
	};

	virtual ~CUI_Popup(void)
	{
		
	};

public:
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