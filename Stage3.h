#pragma once
//
//#include "EM2DEngine.h"
//
//class CStage3 : public CRootScene
//{
//public:
//	//CEMText* m_pText;
//
//	CMap m_CMap;
//
//	//CMonster m_Monster;
//	SAMPLE_HANDLE m_BackGroundSnd;
//	CNum m_CScore;
//	CPistolEnemy m_PE;
//	CMachinegunEnemy m_ME;
//	CShotgunEnemy m_SE;
//	stEMVec3	m_stDestPos;			// 마우스 이동 목적지좌표(회전시사용)
//	stEMVec3	m_stClickDestPos;		// 마우스왼쪽 좌표 클릭 목적지
//	CEMPlane* m_pBackground;
//	CEMPlane* m_pHero;
//	CEMPlane* m_pBullet;
//
//	float m_fDot;						// 내적값
//	float m_fRadian;					// 최종계산되어진 각도(도로변경하여넣어야함)
//
//	stEMVec3 m_stHeroDirVec3;			// 주인공 Up벡터
//	stEMVec3 m_stHeroPosToDestPosDir;	// 주인공이 목적지를 바라보는 벡터 구하기
//	stEMVec3 m_stHeroRightVec3;			// 주인공 우벡터 
//
//public:
//	CStage3(void)
//	{
//		//m_pText = NULL;
//		m_stHeroDirVec3 = stEMVec3(0.0f, 1.0f, 0.0f);
//	};
//	virtual ~CStage3(void)
//	{
//
//	};
//
//public:
//	virtual void Enter(CSceneWork* pSceneWork);							//!< 진입(로딩)
//	virtual void Update(CHero*,CSceneWork*, float dt);							//!< Update
//	virtual void Render(CSceneWork*);										//!< Render
//	virtual void Exit(CSceneWork* pSceneWork);							//!< 탈출(메모리 해제등)
//	virtual void MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 다운 이벤트
//	virtual void MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 업 이벤트
//	virtual void MouseMoveEvent(stMouseInfo stPos);								//!< 마우스 이동 이벤트
//	virtual HRESULT WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//!< 윈도우 이벤트
//
//public:
//	void CreateBullet(float dt);
//	void CreateMonster(int nStage);
//	void Score(float dt);
//	void Clipping(int nStage);
//	void ClippingEnemy(int nStage);
//	void MoveStage(int nStage);
//	void GameInfo();
//	void Scroll();
//	void DestDirAngleCalc(stMouseInfo stPos);
//};