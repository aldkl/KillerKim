#pragma once

#include "stdafx.h"

class CBaseResultWin : public CPopupWinRoot
{
public:




public:
	CBaseResultWin()
	{

	}

	virtual ~CBaseResultWin()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
};