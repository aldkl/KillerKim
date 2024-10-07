#pragma once

#include "stdafx.h"

class CGotoMenuPopupWin : public CPopupWinRoot
{



public:
	CGotoMenuPopupWin()
	{
	}

	virtual ~CGotoMenuPopupWin()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
};