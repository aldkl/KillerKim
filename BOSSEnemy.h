#pragma once
enum
{
	E_BOSS_MOVE_UP,
	E_BOSS_MOVE_DOWN,
	E_BOSS_MOVE_RIGHT,
	E_BOSS_MOVE_LEFT,
	E_BOSS_DIE,
	E_BOSS_JUMP,
	E_BOSS_MAX
};
class CBossEnemy
{
public:
	CEMAnimation* m_Enemy[E_BOSS_MAX];
	CEMPlane* m_crack;
	CBullet m_CEnyBullet;
	stEMVec2 m_stVec2;
	stEMVec2 stEMNowVec2;
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

	bool UP;
	int nMove;
	int pattern;
	int NowI;
	bool m_bType;
public:
	CBossEnemy();
	~CBossEnemy();
public:
	void Update(CEMPlane* m_CMap, CHero* Hero);
	void Disable(int);
	void Enable(stEMVec2);
	void CreateObj(CRootScene* pScene);
	void Move();
	void Clipping(int i, CEMPlane* m_CMap);
	void CreateBullet1(CHero* CHero);
	void CreateBullet2(CHero* CHero);
	void CreatEn();
};