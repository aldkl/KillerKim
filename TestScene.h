#pragma once

#include "stdafx.h"


class CTestScene : public CRootScene
{
public:
	CEMPlane* m_pBlackground;
public:



public:
	CTestScene(void)
	{
		
	};

	virtual ~CTestScene(void)
	{

	};

public:
	virtual void Enter(CSceneWork* pSceneWork);                        //!< ����(�ε�)
	virtual void Update(CSceneWork*, float dt);                        //!< Update
	virtual void Render(CSceneWork*);                                 //!< Render
	virtual void Exit(CSceneWork* pSceneWork);                        //!< Ż��(�޸� ������)
	virtual void MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton);         //!< ���콺 �ٿ� �̺�Ʈ
	virtual void MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);         //!< ���콺 �� �̺�Ʈ
	virtual void MouseMoveEvent(stMouseInfo stPos);                           //!< ���콺 �̵� �̺�Ʈ
	virtual HRESULT WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);   //!< ������ �̺�Ʈ//!< ���콺 �̵� �̺�Ʈ

	virtual void CALLBACK OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id);
};