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
	float m_fDot;						// ������
	float m_fRadian;					// �������Ǿ��� ����(���κ����Ͽ��־����)

	stEMVec3	m_stDestPos;			// ���콺 �̵� ��������ǥ(ȸ���û��)
	stEMVec3	m_stClickDestPos;		// ���콺���� ��ǥ Ŭ�� ������
	stEMVec3 m_stHeroDirVec3;			// ���ΰ� Up����
	stEMVec3 m_stHeroPosToDestPosDir;	// ���ΰ��� �������� �ٶ󺸴� ���� ���ϱ�
	stEMVec3 m_stHeroRightVec3;			// ���ΰ� �캤�� 
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
	virtual void Enter(CSceneWork* pSceneWork);							//!< ����(�ε�)
	virtual void Update(CSceneWork*, float dt);							//!< Update
	virtual void Render(CSceneWork*);										//!< Render
	virtual void Exit(CSceneWork* pSceneWork);							//!< Ż��(�޸� ������)
	virtual void MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< ���콺 �ٿ� �̺�Ʈ
	virtual void MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< ���콺 �� �̺�Ʈ
	virtual void MouseMoveEvent(stMouseInfo stPos);								//!< ���콺 �̵� �̺�Ʈ
	virtual HRESULT WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//!< ������ �̺�Ʈ

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