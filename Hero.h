#pragma once
enum
{
	E_RIGHT_RUN,
	E_LEFT_RUN,
	E_DIE,
	E_HERO_MAX
};
class CHero : public CUnit
{
public:
	CEMAnimation* m_pAnimation;
	CEMAnimation* m_pSkill;
	CEMPlane* m_pArm;
	CEMPlane* m_Fire;

public:
	CHero();
	~CHero();
public:
	void Update(float dt);
	void Disable();
	void Enable(stEMVec3 Vec);
	void CreateObj(CRootScene* pScene);
	void Move(float dt);
	void Clipping();
	void Hit();
};