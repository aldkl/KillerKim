#pragma once

#include "EM2DEngine.h"

class CGameScene : public CRootScene, public UIEvent
{
public:
	CEMPlane* m_pText[2];

	//CGotoMenuPopupWin m_GotoMenuPopup;
	//CGameScene_BaseUI m_BaseUI;
	stEMBoundingBox m_ClippingMonster;
	CHero m_Hero;
	CBullet m_Bullet;
	CMap m_CMap;

	//CMonster m_Monster;
	SAMPLE_HANDLE m_BackGroundSnd;
	CPistolEnemy m_PE;
	CMachinegunEnemy m_ME;
	CShotgunEnemy m_SE;
	CBossEnemy m_BOSS;
	CMiniBoss m_MiniBoss;
	CEMPlane* m_pBlackground;
	CEMPlane* m_pPauseBGB;
	CEMPlane* m_pTutorial[2];
	CEMPlane * m_pBg11;
	CEMPlane * m_pBg12;
	CEMPlane * m_pBg13;
	CEMPlane * m_pBg14;
	CUI m_CUI;
	float m_fDot;						// 내적값
	float m_fRadian;					// 최종계산되어진 각도(도로변경하여넣어야함)

	stEMVec3	m_stDestPos;			// 마우스 이동 목적지좌표(회전시사용)
	stEMVec3	m_stClickDestPos;		// 마우스왼쪽 좌표 클릭 목적지
	stEMVec3 m_stHeroDirVec3;			// 주인공 Up벡터
	stEMVec3 m_stHeroPosToDestPosDir;	// 주인공이 목적지를 바라보는 벡터 구하기
	stEMVec3 m_stHeroRightVec3;			// 주인공 우벡터 
	stEMVec3 m_BackUpCamera;
	bool m_bCheckEnySpn[4];
	int			m_nLeftX;
	int			m_nRightX;
	int			m_nUpY;
	int			m_nDownY;
	bool		m_bChangeStage;
	float		m_fSceneCntTime;
public:
	CEMWindow*	m_pWin;
public:
	CGameScene(void)
	{
		//m_pText = NULL;
		m_stHeroDirVec3 = stEMVec3(0.0f, 1.0f, 0.0f);

	};
	virtual ~CGameScene(void)
	{

	};

public:
	virtual void Enter(CSceneWork* pSceneWork);							//!< 진입(로딩)
	virtual void Update(CSceneWork*, float dt);							//!< Update
	virtual void Render(CSceneWork*);										//!< Render
	virtual void Exit(CSceneWork* pSceneWork);							//!< 탈출(메모리 해제등)
	virtual void MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 다운 이벤트
	virtual void MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 업 이벤트
	virtual void MouseMoveEvent(stMouseInfo stPos);								//!< 마우스 이동 이벤트
	virtual HRESULT WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//!< 윈도우 이벤트

	virtual void CALLBACK OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id);
public:
	void CreateBullet(float dt);
	void CreateMonster(int nStage);
	void Clipping(int nStage);
	void CreateFallMonster(int);
	void ClippingEnemy(int nStage);
	void MoveStage(int nStage);
	void GameInfo();
	void Scroll();
	void Start();
	void Die();
	void DestDirAngleCalc(stMouseInfo stPos);
	void ChangeStage();
	void CameraShake();
	void CreateOBJ();
};