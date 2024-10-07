#pragma once
class CGameMng
{
public:

	stEMVec3 m_stClickDestPos[D_BULLET_MAX];
	int m_nPlayAni[D_BULLET_MAX];

	float m_fNextStageTime;
	float m_fBulletCtrlTime;
	float m_fMonsterCtrlTime;
	float m_fScoreCtrlTime;
	float m_fHeroGaugeTime;
	float m_fHeroGaugeUpTime;
	float m_fBlackTime;
	float m_fBlackTime2;
	float m_fBlackTime3;
	float m_fBlackTime4;
	float m_fMoveCamaraTime;
	float m_fShakeCtrl;
	float m_fShakeCtrl2;
	float m_fHeroToggleTime;
	float m_fMINIBOSSMoveTime;
	float m_fMINIBOSSFireTime;
	float m_fPEHitTime[D_PE_MAX];
	float m_fSEHitTime[D_SE_MAX];
	float m_fMEHitTime[D_ME_MAX];

	float m_fPEMoveTime[D_PE_MAX];
	float m_fPEFireTime[D_PE_MAX];
	float m_fMEMoveTime[D_ME_MAX];
	float m_fMEFireTime[D_ME_MAX];
	float m_fSEMoveTime[D_SE_MAX];
	float m_fSEFireTime[D_SE_MAX];
	float m_fBossFireTime1;
	float m_fMINIBOSSFireTime1;
	float m_bPEDOWNTime[D_PE_MAX];
	float m_bMEDOWNTime[D_ME_MAX];
	float m_bSEDOWNTime[D_SE_MAX];

	int m_PEHP[D_PE_MAX];
	int m_MEHP[D_ME_MAX];
	int m_SEHP[D_SE_MAX];
	int m_BOSSHP;

	bool m_bPEMove[D_PE_MAX];
	bool m_bMEMove[D_ME_MAX];
	bool m_bSEMove[D_SE_MAX];
	bool m_bPEMoveFrame[D_PE_MAX];
	bool m_bMEMoveFrame[D_ME_MAX];
	bool m_bSEMoveFrame[D_SE_MAX];
	bool m_bMINIBOSSMove;
	bool m_bMINIBOSSMoveFrame;

	bool		m_bUP;
	bool		m_bUP2;
	bool		m_bDOWN;
	bool		m_bDOWN2;
	bool		m_bStart;
	bool m_bNextStageTime;
	bool m_bHeroFrame;
	bool m_bF5;
	bool m_bF8;
	bool m_bF9;
	bool m_bF10;
	bool m_bScroll;
	bool m_bSkillOn;
	bool m_bSkillToggle;
	bool m_bNextStage;
	bool m_bBlack;
	bool m_bBlack2;
	bool m_bStartStage;
	bool m_bHit;
	bool m_bHitHero;
	bool m_bAlphaCheck;
	bool m_bShakeFlag;
	bool m_bHeroMove;
	bool m_bHeroSide;
	bool m_bPause;
	bool m_BOSSUse;
	int m_nHeroHP;
	int m_nGauge;
	int m_nLiveEny;
	int m_nCheckHeroAlpha;
	int m_nBullet;
	int m_nStage;
	int m_nMap;
	int m_nScore;
	int m_nScroll;
	float m_fedX;
	float m_fHitHero;
	bool m_bmission;
	CRootScene* NowScene;

	int m_nKillScore;
public:
	CGameMng(void)
	{
		//m_pText = NULL;
		m_fNextStageTime = 0;
		m_bNextStageTime = FALSE;
		m_BOSSUse = FALSE;
		m_bPause = FALSE;
		m_bF5 = FALSE;
		m_bF8 = FALSE;
		m_bF9 = FALSE;
		m_bF10 = FALSE;
		m_bHeroFrame = FALSE;
		m_bHeroSide = FALSE;
		m_bHeroMove = FALSE;
		m_bShakeFlag = FALSE;
		m_nGauge = 100;
		m_nMap = 1;
		m_fBulletCtrlTime = 0;
		m_fMonsterCtrlTime = 0;
		m_fHeroGaugeTime = 0;
		m_fScoreCtrlTime = 0;
		m_fHeroGaugeUpTime = 0;
		m_bSkillOn = FALSE;
		m_bSkillToggle = FALSE;
		m_nStage = 0;
		m_nScroll = 0;
		m_nHeroHP = 5;
		m_fBlackTime = 0;
		m_bNextStage = FALSE;
		m_bBlack = TRUE;
		m_bBlack2 = TRUE;
		m_bHit = TRUE;
		m_nLiveEny = 0;
		m_bStartStage = TRUE;
		m_bHitHero = FALSE;
		m_nCheckHeroAlpha = 0;
		m_nBullet = 40;
		m_fShakeCtrl = 0;
		m_fShakeCtrl2 = 0;
		m_fHeroToggleTime = 0;
		m_nKillScore = 0;
		for (int i = 0; i < D_BULLET_MAX; i++)
		{
			m_nPlayAni[i] = 0;
		}
	};

	virtual ~CGameMng(void)
	{

	};
public:

};