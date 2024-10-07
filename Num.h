#pragma once
class CNum
{
public:
	CEMNumber* m_pNum;//BULLET
	CEMNumber* m_pSNum;//STAGE
	CEMNumber* m_pRNum;//STAGE
	CEMNumber* m_pENum;//Enemy
	CEMNumber* m_pCNum;//SCORE
public:
	CNum();
	~CNum();
public:
	void Update(float dt, int i,int j, int k, int l, int q);
	void Disable();
	void Enable(stEMVec3 Vec);
	void CreateObj(CRootScene* pScene);
};