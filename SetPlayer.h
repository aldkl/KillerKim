#pragma once

#include "stdafx.h"

class CSetPlayer : public CPopupWinRoot
{



public:
	CSetPlayer()
	{
	}

	virtual ~CSetPlayer()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
};