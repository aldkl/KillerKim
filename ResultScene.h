#pragma once

#include "stdafx.h"


class CResultScene : public CRootScene, public UIEvent
{
private:
	stEMVec3	m_stCamPos;				// ī�޶� ��ġ

private:
	TwBar* m_pBar;

public:
	CEMPlane*	m_pBg;	//�г�
	CEMPlane * m_pBg11;
	CEMPlane * m_pBg12;
	CEMPlane * m_pBg13;
	CEMPlane * m_pBg14;
	CEMPlane * m_pBg15;
	CEMPlane * m_pBg16;
	CEMPlane * m_pBg17;
	CEMPlane * m_pBg18;
	CEMPlane * m_pMC1;			//��
	CEMPlane * m_pMC2;			//��
	CEMPlane * m_pMC3;			//��
	CEMPlane * m_pMC4;			//��
	CEMPlane * m_pMF1;			//��
	CEMPlane * m_pMF2;			//��
	CEMPlane * m_pMF3;			//��
	CEMPlane * m_pMF4;			//��
	CEMWindow*	m_pWin;	
	CEMNumber*  m_pNumberOth;//����
	CEMNumber*  m_pNumberOth2;//����
	CEMNumber*  m_pNumberOth3;//����
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
	float		m_fIndex;		//��Ϲ��� ȸ��
	float		m_fInc;			//���� ��
	float		m_fKillScore;	//�� óġ ����
	float		m_fGameScore;	//������ ����
	float		m_fTotalScore;	//���� Ƚ��
	float		m_fMES[4];			//�ӹ� ����/���� �����
	int			m_nMEX[4];			//�ӹ� ����/���� X��
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