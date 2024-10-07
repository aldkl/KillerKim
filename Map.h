#pragma once
#include "stdafx.h"
class CMap
{
public:
	CEMAnimation* m_Door[D_DOOR_MAX];
	CEMAnimation* m_ClippingHero[D_ROOM_MAX];
public:
	CMap();
	~CMap();
public:
	void Update(float dt);
	void Disable();
	void CreateObj(CRootScene* pScene);
};