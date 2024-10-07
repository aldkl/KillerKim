#pragma once
//enum
//{
//	E_BOSS_MOVE_UP,
//	E_BOSS_MOVE_RIGHT,
//	E_BOSS_MAX
//};
class CMiniBoss
{
public:
	CEMAnimation* m_Enemy;
	CEMPlane* m_Fire;
	CBullet m_CEnyBullet;
	stEMVec2 m_stVec2;
	stEMVec2 stEMNowVec2;
	CEMPlane* m_pArm;
	CRootScene* m_pScene;

	stEMVec3 m_stHeroDirVec3;
	stEMVec3 m_stDestPos;
	stEMVec3 m_stEnemyPosToDestPosDir;
	stEMVec3 m_stHeroRightVec3;
	float m_fRadian;
	float m_fDot;
	float m_fUpTime;
	float m_fCreatEnemyTime;
	float m_fPatternChangeTime;
	float m_fPatternTime;

	bool m_bSide;
	bool UP;
	int nMove;
	int pattern;
	int NowI;
	bool m_bType;
public:
	CMiniBoss();
	~CMiniBoss();
public:
	void Update(CEMPlane* m_CMap, CHero* Hero);
	void Disable(int);
	void Enable(stEMVec2);
	void CreateObj(CRootScene* pScene);
	void Move();
	void Clipping(CEMPlane* m_CMap);
	void CreateBullet1(CHero* CHero);
	void CreatEn();

	void BulletFire(float x1, float x2, float x3, float x4, float x5, float y1, float y2, float y3, float y4, float y5);
};