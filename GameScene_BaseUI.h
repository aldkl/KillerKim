#pragma once

#include "stdafx.h"

class CGameScene_BaseUI : public CPopupWinRoot
{
public:



public:
	CGameScene_BaseUI()
	{
	}

	virtual ~CGameScene_BaseUI()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
};