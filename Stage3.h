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
//	stEMVec3	m_stDestPos;			// ���콺 �̵� ��������ǥ(ȸ���û��)
//	stEMVec3	m_stClickDestPos;		// ���콺���� ��ǥ Ŭ�� ������
//	CEMPlane* m_pBackground;
//	CEMPlane* m_pHero;
//	CEMPlane* m_pBullet;
//
//	float m_fDot;						// ������
//	float m_fRadian;					// �������Ǿ��� ����(���κ����Ͽ��־����)
//
//	stEMVec3 m_stHeroDirVec3;			// ���ΰ� Up����
//	stEMVec3 m_stHeroPosToDestPosDir;	// ���ΰ��� �������� �ٶ󺸴� ���� ���ϱ�
//	stEMVec3 m_stHeroRightVec3;			// ���ΰ� �캤�� 
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
//	virtual void Enter(CSceneWork* pSceneWork);							//!< ����(�ε�)
//	virtual void Update(CHero*,CSceneWork*, float dt);							//!< Update
//	virtual void Render(CSceneWork*);										//!< Render
//	virtual void Exit(CSceneWork* pSceneWork);							//!< Ż��(�޸� ������)
//	virtual void MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< ���콺 �ٿ� �̺�Ʈ
//	virtual void MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< ���콺 �� �̺�Ʈ
//	virtual void MouseMoveEvent(stMouseInfo stPos);								//!< ���콺 �̵� �̺�Ʈ
//	virtual HRESULT WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//!< ������ �̺�Ʈ
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