#pragma once
class CShotgunEnemy
{
public:
	CEMAnimation* m_Enemy[D_SE_MAX];
	CEMAnimation* m_DownEnemy[D_SE_MAX];
	CEMAnimation* m_DownEnemyEFT[D_SE_MAX];
	CEMPlane* m_pArm[D_SE_MAX];
	CEMPlane* m_Fire[D_SE_MAX];
	CBullet m_CEnyBullet[D_SE_MAX];
	stEMVec2 m_stVec2[D_SE_MAX];
	stEMVec2 stEMNowVec2[D_SE_MAX];
	CRootScene* m_pScene;

	stEMVec3 m_stHeroDirVec3[D_SE_MAX];
	stEMVec3 m_stDestPos[D_SE_MAX];
	stEMVec3 m_stEnemyPosToDestPosDir[D_SE_MAX];
	stEMVec3 m_stHeroRightVec3[D_SE_MAX];
	float m_fRadian[D_SE_MAX];
	float m_fDot[D_SE_MAX];

	bool m_bSide[D_SE_MAX];
	bool m_bFall[D_SE_MAX];
	bool m_bHit[D_SE_MAX];
	int NowI;
public:
	CShotgunEnemy();
	~CShotgunEnemy();
public:
	void Update(CEMPlane* m_CMap, CHero* Hero);
	void Disable(int);
	void Enable(int nIndex, stEMVec2,bool);
	void CreateObj(CRootScene* pScene);
	void Move(int i);
	void Clipping(int i, CEMPlane* m_CMap);
	void CreateBullet(int i, CHero* CHero);
	void BulletFire(int i,float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4);
};