#pragma once

#include "stdafx.h"

class CSettingPopupWin : public CPopupWinRoot
{



public:
	CSettingPopupWin()
	{
	}

	virtual ~CSettingPopupWin()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
};