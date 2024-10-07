#pragma once
class CPistolEnemy
{
public:
	CEMAnimation* m_Enemy[D_PE_MAX];
	CEMAnimation* m_DownEnemy[D_PE_MAX];
	CEMAnimation* m_DownEnemyEFT[D_PE_MAX];
	CEMPlane* m_pArm[D_PE_MAX];
	CEMPlane* m_Fire[D_PE_MAX];
	CBullet m_CEnyBullet[D_PE_MAX];
	stEMVec2 m_stVec2[D_PE_MAX];
	stEMVec2 stEMNowVec2[D_PE_MAX];
	CRootScene* m_pScene;

	stEMVec3 m_stHeroDirVec3[D_PE_MAX];
	stEMVec3 m_stDestPos[D_PE_MAX];
	stEMVec3 m_stEnemyPosToDestPosDir[D_PE_MAX];
	stEMVec3 m_stHeroRightVec3[D_PE_MAX];
	float m_fRadian[D_PE_MAX];
	float m_fDot[D_PE_MAX];

	bool m_bSide[D_PE_MAX];
	bool m_bFall[D_PE_MAX];
	bool m_bHit[D_PE_MAX];
	int NowI;
public:
	CPistolEnemy();
	~CPistolEnemy();
public:
	void Update(CEMPlane* m_CMap, CHero* Hero);
	void Disable(int);
	void Enable(int nIndex, stEMVec2,bool);
	void CreateObj(CRootScene* pScene);
	void Move(int i);
	void Clipping(int i, CEMPlane* m_CMap);
	void CreateBullet(int i, CHero* CHero);
};