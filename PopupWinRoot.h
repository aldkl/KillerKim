#pragma once

#include "stdafx.h"


enum E_BTN_TYPE
{
	E_BTN,
	E_RADIO_BTN,
	E_CHECK_BTN
};

enum E_RADIO_ON_OFF
{
	E_OFF,
	E_ON	
};

// ��ư Ŭ���� �Դϴ� ���� ���� �۾� ������ �迭 2�� ����
class CBtn
{
private:
	E_BTN_TYPE m_eType;
	bool	   m_bRadioOnOff;	//ture -- > ON  flase --> OFF

public:
	CEMPlane* pUI[2];		// ��ư �迭 (���plane, �۾�Plane)

public:
	CBtn()
	{
		Init();
	}

	~CBtn()
	{
		Init();
	}

	void Init()
	{
		m_eType = E_BTN;
		m_bRadioOnOff = true;

		for (int i = 0; i < 2; i++)
			pUI[i] = NULL;
	}

public:
	E_BTN_TYPE GetType() {return m_eType; }
	void SetType(E_BTN_TYPE eType);

	bool GetRadioOnOff() { return m_bRadioOnOff; }
	void SetRadioOnOff( bool bOnOff);

public:	
	void SetPos(stEMVec3 stPos);
	void SetShow(bool bFlag);
	void SetColor(CEMColor color = CEMColor(1, 1, 1, 1));
};

class CPopupWinRoot
{
public:
	CEMPlane*		m_pBg;					// �˾������� ����Դϴ�.
	CEMPlane*		m_pEtcs[D_BTN_MAX];		// �⺻ 10�� �Դϴ�. �˾�������ȿ� ����� �̹��� ���Դϴ�.
	CBtn			m_Btns[D_BTN_MAX];		// �⺻ 10���Դϴ�. �˾�������ȿ� ������� ��ư���Դϴ�.

	CRootScene*		m_pScene;				// 
	int				m_nLayer;				// �߰��� ���̾�

public:
	SAMPLE_HANDLE	m_ClickSnd;				// Ŭ����

public:	
	CEMPlane*		m_pSelectPlane;			// ������ �޴�
	CEMPlane*		m_pPrevSelectPlane;		// �� ���� ������ �޴�

private:
	bool			m_bCollisionFlag;		// �浹ó�� �Ұ��� ������^^

public:
	bool GetCollisionFlag() { return m_bCollisionFlag; }
	void SetCollisionFlag(bool bFlag) { m_bCollisionFlag = bFlag; }

public:
	CPopupWinRoot()
	{
		Init();
	}

	virtual ~CPopupWinRoot()
	{
		Init();
	}

public:
	void Init()
	{
		m_bCollisionFlag = true;

		for (int i = 0; i < D_BTN_MAX; i++)
		{
			m_pEtcs[i] = NULL;
		}

		m_ClickSnd = NULL;
		m_nLayer = -1000;
		m_pSelectPlane = NULL;
		m_pPrevSelectPlane = NULL;

		m_pBg = NULL;
		m_pScene = NULL;
	}

	// �������^^
	virtual void Reset()
	{
		Init();
	}

	virtual void SetPos(stEMVec3 stPos);
	virtual void SetShow(bool bFlag);
	//virtual void SetRadioUpdate(int nRadioIndex, bool bFlag);
	virtual void SetColor(CEMColor color = CEMColor(1, 1, 1, 1));

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow=true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos) = 0;
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton) = 0;
};