#pragma once
class CBullet
{
public:
	stEMVec3	m_stCamPos;				// 카메라 위치
	stEMVec3	m_stDestPos;			// 마우스 이동 목적지좌표(히어로회전시사용)
	stEMBoundingBox m_ClippingBullet;
	SAMPLE_HANDLE m_BulletSnd;
	SAMPLE_HANDLE m_DieMonster[D_ENEMY_MAX];
	int m_nHp;
	float m_fSpeed;
	CEMAnimation*  m_pAnimation[D_BULLET_MAX];
	CEMPlane*  m_pClippingBox;
	CRootScene* m_pScene;
	stEMVec3 m_stClickDestPos[D_BULLET_MAX];
	stEMVec3 m_Vec2[D_BULLET_MAX];
	stEMVec3 m_stHeroVec3;
	float m_fDot;						// 내적값
	float m_fRadian;					// 최종계산되어진 각도(도로변경하여넣어야함)
	int m_nWho;
	stEMVec3 m_stHeroDirVec3;			// 주인공 Up벡터
	stEMVec3 m_stHeroPosToDestPosDir;	// 주인공이 목적지를 바라보는 벡터 구하기
	stEMVec3 m_stHeroRightVec3;			// 주인공 우벡터
	int m_nStage;
	int m_nMinusBullet;

	int m_nPlayAni[D_BULLET_MAX];
	CEMAnimation* m_pSheldH[D_BULLET_MAX];
public:
	CBullet();
	~CBullet();
public:
	void DestDirAngleCalc(stMouseInfo stPos);
	void MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton, CHero Hero);
	void MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton, CHero Hero);
	void MouseMoveEvent(stMouseInfo stPos,CHero* Hero);
	void Update(float dt, int nType);
	void Disable(int nIndex);
	void Enable(int nIndex, stEMVec3 Vec, stMouseInfo EdVec, int nStage);
	void Enable(int nIndex, stEMVec3 Vec, stEMVec3 EdVec, int nStage);
	void CreateObj(CRootScene* pScene, stdEMString stTemp, int nIndex, int nIndx2,int k);
	void Move(float dt, int nType);
	void Clipping(int i);
	void Effect(int i);
};