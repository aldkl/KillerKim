#pragma once
class CUnit
{
public:
	CEMPlane* m_pPlane;
	CEMAnimation* m_pAnimation;
	float m_fSpeed;//움직임 속도
public:
	CUnit();
	~CUnit();
public:
	void Update(float dt);
	void Disable();
	void Enable(stEMVec3 Vec);
	void CreateObj(CRootScene* pScene);

};