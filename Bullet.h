#pragma once
class CBullet
{
public:
	stEMVec3	m_stCamPos;				// ī�޶� ��ġ
	stEMVec3	m_stDestPos;			// ���콺 �̵� ��������ǥ(�����ȸ���û��)
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
	float m_fDot;						// ������
	float m_fRadian;					// �������Ǿ��� ����(���κ����Ͽ��־����)
	int m_nWho;
	stEMVec3 m_stHeroDirVec3;			// ���ΰ� Up����
	stEMVec3 m_stHeroPosToDestPosDir;	// ���ΰ��� �������� �ٶ󺸴� ���� ���ϱ�
	stEMVec3 m_stHeroRightVec3;			// ���ΰ� �캤��
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