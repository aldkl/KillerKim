#pragma once
class CUI
{
public:
	CEMPlane* m_HeroSkillBar;
	CEMPlane* m_HeroSkillSPR;
	CEMPlane* m_HeroSkillBarBG;
	CEMPlane* m_BOSSHPBar;
	CEMPlane* m_BOSSHPBarBG;

	CEMPlane* m_HeroSkillBarbase;
	CEMPlane* m_SCORE;
	CEMPlane* m_STAGE;
	CEMPlane* m_Enemy;
	CEMPlane* m_Bullet;
	CEMPlane* m_STAGEMA;
	CEMPlane* m_RED;
	CEMPlane* m_HP[2][5];
	
	CNum m_CBulletNum;
public:
	CUI();
	~CUI();
public:
	void Update(float dt);
	void CreateObj(CRootScene* pScene);
	void Move();
	void UpdateHP();
};