#pragma once

#include "stdafx.h"


class CLogoScene : public CRootScene
{
public:
	CEMText * m_pTextYe;
	stEMVec3   m_stCamPos;            // ī�޶� ��ġ

public:
	TwBar * m_pBar;

public:
	CEMAnimation * m_pBackground;
	CEMPlane*   m_pPressAnyKey;
	CEMPlane*   m_pLoadingBg;
	CEMPlane*   m_pLoadingTitleBg;
	CEMPlane*   m_pLoadingTitleText;

	CEMPlane*   m_p76;
	CEMPlane*   m_p77;
	CEMPlane * m_pBg1;
	CEMPlane * m_pBg2;
	CEMPlane * m_pBg3;
	CEMPlane * m_pBg4;
	CEMPlane * m_pBg5;
	CEMPlane * m_pBg6;
	CEMPlane * m_pBg7;
	CEMPlane * m_pBg11;
	CEMPlane * m_pBg12;
	CEMPlane * m_pBg13;
	CEMPlane * m_pBg14;
	CEMPlane * m_pBg15;
	CEMPlane * m_pBg16;

	CEMAnimation* m_pALoading;
	CEMNumber*  m_pLoadingValue;

	float      m_fAlphaTime;
	float      m_fAlpha;
	float		m_fIndex;		//��Ϲ��� ȸ��
	bool      m_bTurn;

	float      m_fLodingCntTime;
	float		m_fSceneCntTime;
	int         m_nLoadingCnt;
	int			m_nUpY;
	int			m_nDownY;


	bool		m_bPressKeyFlag;
	bool		m_bSceneChange;

public:
	CLogoScene(void)
	{
		m_bPressKeyFlag = true;
		m_fLodingCntTime = 0;
		m_nLoadingCnt = 0;
		m_pLoadingValue = NULL;
		m_p76 = NULL;
		m_p77 = NULL;
		m_pLoadingTitleBg = NULL;
		m_pALoading = NULL;
		m_fAlphaTime = 0.0f;
		m_fIndex = 0.0f;
		m_bTurn = false;
		m_fAlpha = 1.0f;
		m_fSceneCntTime = 0.0f;
		m_nUpY = 163;
		m_nDownY = 10;
		m_pPressAnyKey = NULL;
		m_stCamPos.m_fX = 0.0f;
		m_stCamPos.m_fY = 0.0f;
		m_stCamPos.m_fZ = 620.0f;
		m_bSceneChange = false;

		m_pTextYe = NULL;
		m_pBackground = NULL;
	};

	virtual ~CLogoScene(void)
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