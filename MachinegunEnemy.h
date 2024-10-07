#pragma once
class CMachinegunEnemy
{
public:
	CEMAnimation* m_Enemy[D_ME_MAX];
	CEMAnimation* m_DownEnemy[D_ME_MAX];
	CEMAnimation* m_DownEnemyEFT[D_ME_MAX];
	CEMPlane* m_pArm[D_ME_MAX];
	CEMPlane* m_Fire[D_ME_MAX];
	CBullet m_CEnyBullet[D_ME_MAX];
	stEMVec2 m_stVec2[D_ME_MAX];
	stEMVec2 stEMNowVec2[D_ME_MAX];
	CRootScene* m_pScene;

	stEMVec3 m_stHeroDirVec3[D_ME_MAX];
	stEMVec3 m_stDestPos[D_ME_MAX];
	stEMVec3 m_stEnemyPosToDestPosDir[D_ME_MAX];
	stEMVec3 m_stHeroRightVec3[D_ME_MAX];
	float m_fRadian[D_ME_MAX];
	float m_fDot[D_ME_MAX];

	bool m_bSide[D_ME_MAX];
	bool m_bFall[D_ME_MAX];
	bool m_bHit[D_ME_MAX];
	int NowI;
public:
	CMachinegunEnemy();
	~CMachinegunEnemy();
public:
	void Update(CEMPlane* m_CMap, CHero* Hero);
	void Disable(int);
	void Enable(int nIndex, stEMVec2,bool);
	void CreateObj(CRootScene* pScene);
	void Move(int i);
	void Clipping(int i, CEMPlane* m_CMap);
	void CreateBullet(int i, CHero* CHero);
};