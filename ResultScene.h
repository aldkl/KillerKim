#pragma once

#include "stdafx.h"


class CResultScene : public CRootScene, public UIEvent
{
private:
	stEMVec3	m_stCamPos;				// 카메라 위치

private:
	TwBar* m_pBar;

public:
	CEMPlane*	m_pBg;	//패널
	CEMPlane * m_pBg11;
	CEMPlane * m_pBg12;
	CEMPlane * m_pBg13;
	CEMPlane * m_pBg14;
	CEMPlane * m_pBg15;
	CEMPlane * m_pBg16;
	CEMPlane * m_pBg17;
	CEMPlane * m_pBg18;
	CEMPlane * m_pMC1;			//임
	CEMPlane * m_pMC2;			//무
	CEMPlane * m_pMC3;			//성
	CEMPlane * m_pMC4;			//공
	CEMPlane * m_pMF1;			//임
	CEMPlane * m_pMF2;			//무
	CEMPlane * m_pMF3;			//실
	CEMPlane * m_pMF4;			//패
	CEMWindow*	m_pWin;	
	CEMNumber*  m_pNumberOth;//직교
	CEMNumber*  m_pNumberOth2;//직교
	CEMNumber*  m_pNumberOth3;//직교
	float		m_fZRot;
	float		m_fCount;
	float		m_fCount2;
	float		m_fCount3;
	float		m_fSceneCntTime;
	float		m_fSceneCntTime2;
	float		m_fMCntTime;
	float		m_fCntTime;
	float		m_fCntTime2;
	float		m_fCntTime3;
	float		m_fIndex;		//톱니바퀴 회전
	float		m_fInc;			//증가 값
	float		m_fKillScore;	//적 처치 점수
	float		m_fGameScore;	//아이템 점수
	float		m_fTotalScore;	//맞은 횟수
	float		m_fMES[4];			//임무 성공/실패 사이즈값
	int			m_nMEX[4];			//임무 성공/실패 X값
	int			m_nLeftX;
	int			m_nRightX;
	int			m_nUpY;
	int			m_nDownY;
	int			m_nMsnZ;
	bool		m_bSceneChange;
	bool		m_bMW;
	bool		m_bResultWin;

public:
	CResultScene(void)
	{	
		m_stCamPos.m_fX 	= 0.0f;
		m_stCamPos.m_fY 	= 0.0f;
		m_stCamPos.m_fZ 	= 620.0f;

		m_fInc = 100.0f;
		m_fZRot = 0.0f;
		m_fCount = 0.0f;
		m_fCount2 = 0.0f;
		m_fCount3 = 0.0f;
		m_fSceneCntTime = 0.0f;
		m_fSceneCntTime2 = 0.0f;
		m_fMCntTime = 0.0f;
		m_fCntTime = 0.0f;
		m_fCntTime2 = 0.0f;
		m_fCntTime3 = 0.0f;
		m_fKillScore = 9000.0f - m_fInc;		
		m_fGameScore = 10000.0f - m_fInc;
		m_fTotalScore = m_fKillScore + m_fGameScore + m_fInc;
		m_fMES[0] = 5.0f;
		m_fMES[1] = 5.0f;
		m_fMES[2] = 5.0f;
		m_fMES[3] = 5.0f;
		m_nMEX[0] = -500;
		m_nMEX[1] = -200;
		m_nMEX[2] = 200;
		m_nMEX[3] = 500;
		m_nLeftX = -295;
		m_nRightX = 300;
		m_nUpY = 800;
		m_nDownY = -625;                          
		m_fIndex = 0.0f;
		m_nMsnZ = 0;
		m_bSceneChange = false;
		m_bResultWin = false;
		m_bMW = false;
	
		m_pBg = NULL;
	};

	virtual ~CResultScene(void)
	{
		
	};

public:
	virtual void Enter				(CSceneWork* pSceneWork);								//!< 진입(로딩)
	virtual void Update				(CSceneWork*, float dt);								//!< Update
	virtual void Render				(CSceneWork*);											//!< Render
	virtual void Exit				(CSceneWork* pSceneWork);								//!< 탈출(메모리 해제등)
	virtual void MouseDownEvent 	(stMouseInfo stPos, enumMouseButton eButton);			//!< 마우스 다운 이벤트
	virtual void MouseUpEvent		(stMouseInfo stPos, enumMouseButton eButton);			//!< 마우스 업 이벤트
	virtual void MouseMoveEvent 	(stMouseInfo stPos);									//!< 마우스 이동 이벤트
	virtual HRESULT WindowMessage	(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	//!< 윈도우 이벤트//!< 마우스 이동 이벤트

	virtual void CALLBACK OnEvent	(stdEMString sWindowName, enumDialogType eType, UINT id);
};