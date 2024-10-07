#include "stdafx.h"

void CResultScene::Enter(CSceneWork* pSceneWork)
{
	m_fKillScore = g_GMng.m_nKillScore - m_fInc;
	m_fGameScore = g_GMng.m_nScore - m_fInc;
	m_fTotalScore = m_fKillScore + m_fGameScore + m_fInc;
	D_MNG->CreateSound();
	for (int i = 0; i < E_SND_MAX; i++)
	{
		D_SOUND->Stop(D_MNG->m_BackSnd[i]);
	}

	float fVolume = D_MNG->GetMusicVolume();

	fVolume = 0.5f;
	D_MNG->SetMusicVolume(fVolume);
	D_SOUND->SetVolume(D_MNG->m_ClickSnd[E_FXSND_END], fVolume);

	

	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/메뉴/결과창/패널.png", GL_REPEAT, GL_NEAREST);
	m_pBg->SetSize(1.0f);
	m_pBg->SetPos(stEMVec3(0, 0, 0));
	m_pBg->SetBlend(false);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetFrstumCullingFlag(false);
	Commit(2, "back", m_pBg);

	m_pWin = new CEMWindow("Result", stEMRect(0, 0, 1280, 720), this, CEMColor(1.0f, 1.0f, 1.0f, 0.0f));
	//결과창 배경
	m_pWin->AddWindow("Result1", "Data/Image/메뉴/윈도우용 투명배경.png", stEMVec3(0.0f, 0.0f, 0.0f), CEMColor(1.0f, 1.0f, 1.0f, 1.0f));
	m_pWin->GetWindow("Result1")->AddTexture(0, "Data/Image/메뉴/결과창/결과 타이틀.png", stEMVec3(650.0f, 100.0f, 0.0f));
	m_pWin->GetWindow("Result1")->AddTexture(1, "Data/Image/메뉴/결과창/적 처치.png", stEMVec3(450.0f, 280.0f, 0.0f));
	m_pWin->GetWindow("Result1")->AddTexture(2, "Data/Image/메뉴/결과창/공격 방어.png", stEMVec3(450.0f, 370.0f, 0.0f));
	m_pWin->GetWindow("Result1")->AddTexture(3, "Data/Image/메뉴/결과창/합계.png", stEMVec3(450.0f, 470.0f, 0.0f));

	m_pWin->GetWindow("Result1")->AddButton(1,	"Data/Image/메뉴/HOME1.png",
												"Data/Image/메뉴/HOME2.png",
												"Data/Image/메뉴/HOME3.png",
												stEMVec3(1150.0f, 50.0f, 0.0f));
	m_pWin->GetWindow("Result1")->SetLock(E_STATIC);
	m_pWin->GetWindow("Result1")->SetVisible(false);

	Commit(m_pWin, E_STATIC);


	//============================================================================================
	//숫자
	m_pNumberOth = new CEMNumber(10);
	m_pNumberOth->SetTexture(this, 10, "Data/Image/메뉴/결과창/점수 0.png",
		"Data/Image/메뉴/결과창/점수 1.png",
		"Data/Image/메뉴/결과창/점수 2.png",
		"Data/Image/메뉴/결과창/점수 3.png",
		"Data/Image/메뉴/결과창/점수 4.png",
		"Data/Image/메뉴/결과창/점수 5.png",
		"Data/Image/메뉴/결과창/점수 6.png",
		"Data/Image/메뉴/결과창/점수 7.png",
		"Data/Image/메뉴/결과창/점수 8.png",
		"Data/Image/메뉴/결과창/점수 9.png", GL_REPEAT, GL_NEAREST);

	m_pNumberOth->SetPos(stEMVec3(600, 270, 0));
	m_pNumberOth->SetOrtho2D(true);//직교 투영으로 설정
	m_pNumberOth->SetBlend(true);
	m_pNumberOth->SetBackFaceCulling(true);
	m_pNumberOth->SetBoundingBoxCalc(false);
	m_pNumberOth->SetFrstumCullingFlag(false);
	m_pNumberOth->SetShow(false);
	m_pNumberOth->SetNumber(0);

	Commit(1, "NumberOth", m_pNumberOth);

	m_pNumberOth2 = new CEMNumber(10);
	m_pNumberOth2->SetTexture(this, 10, "Data/Image/메뉴/결과창/점수 0.png",
		"Data/Image/메뉴/결과창/점수 1.png",
		"Data/Image/메뉴/결과창/점수 2.png",
		"Data/Image/메뉴/결과창/점수 3.png",
		"Data/Image/메뉴/결과창/점수 4.png",
		"Data/Image/메뉴/결과창/점수 5.png",
		"Data/Image/메뉴/결과창/점수 6.png",
		"Data/Image/메뉴/결과창/점수 7.png",
		"Data/Image/메뉴/결과창/점수 8.png",
		"Data/Image/메뉴/결과창/점수 9.png", GL_REPEAT, GL_NEAREST);

	m_pNumberOth2->SetPos(stEMVec3(600, 370, 0));
	m_pNumberOth2->SetOrtho2D(true);//직교 투영으로 설정
	m_pNumberOth2->SetBlend(true);
	m_pNumberOth2->SetBackFaceCulling(true);
	m_pNumberOth2->SetBoundingBoxCalc(false);
	m_pNumberOth2->SetFrstumCullingFlag(false);
	m_pNumberOth2->SetShow(false);
	m_pNumberOth2->SetNumber(0);

	Commit(1, "NumberOth2", m_pNumberOth2);

	m_pNumberOth3 = new CEMNumber(10);
	m_pNumberOth3->SetTexture(this, 10, "Data/Image/메뉴/결과창/최종 점수 0.png",
		"Data/Image/메뉴/결과창/최종 점수 1.png",
		"Data/Image/메뉴/결과창/최종 점수 2.png",
		"Data/Image/메뉴/결과창/최종 점수 3.png",
		"Data/Image/메뉴/결과창/최종 점수 4.png",
		"Data/Image/메뉴/결과창/최종 점수 5.png",
		"Data/Image/메뉴/결과창/최종 점수 6.png",
		"Data/Image/메뉴/결과창/최종 점수 7.png",
		"Data/Image/메뉴/결과창/최종 점수 8.png", 
		"Data/Image/메뉴/결과창/최종 점수 9.png", GL_REPEAT, GL_NEAREST);

	m_pNumberOth3->SetPos(stEMVec3(600, 470, 0));
	m_pNumberOth3->SetOrtho2D(true);//직교 투영으로 설정
	m_pNumberOth3->SetBlend(true);
	m_pNumberOth3->SetBackFaceCulling(true);
	m_pNumberOth3->SetBoundingBoxCalc(false);
	m_pNumberOth3->SetFrstumCullingFlag(false);
	m_pNumberOth3->SetShow(false);
	m_pNumberOth3->SetNumber(0);

	Commit(1, "NumberOth3", m_pNumberOth3);
	//===========================================================================================

	//결과 처음에 왼쪽 오른쪽 왔다갔다 하는거
	//============================================================================================
	m_pBg11 = new CEMPlane();
	m_pBg11->SetTexture("Data/Image/메뉴/결과창/배경 좌.png", GL_REPEAT, GL_NEAREST);
	m_pBg11->SetSize(1.0f);
	m_pBg11->SetPos(stEMVec3(m_nLeftX, 0, 0));
	m_pBg11->SetBlend(true);
	m_pBg11->SetBackFaceCulling(true);
	m_pBg11->SetBoundingBoxCalc(false);
	m_pBg11->SetFrstumCullingFlag(false);
	Commit(0, "Bg11", m_pBg11);

	m_pBg12 = new CEMPlane();
	m_pBg12->SetTexture("Data/Image/메뉴/결과창/배경 우.png", GL_REPEAT, GL_NEAREST);
	m_pBg12->SetSize(1.0f);
	m_pBg12->SetPos(stEMVec3(m_nRightX, 0, 0));
	m_pBg12->SetBlend(true);
	m_pBg12->SetBackFaceCulling(true);
	m_pBg12->SetBoundingBoxCalc(false);
	m_pBg12->SetFrstumCullingFlag(false);
	Commit(0, "Bg12", m_pBg12);

	//=============================================================================================

	//결과 마지막에 위아래 왔다갔다 하는거
	//==================================================================================================
	m_pBg13 = new CEMPlane();
	m_pBg13->SetTexture("Data/Image/메뉴/메인/배경 상.png", GL_REPEAT, GL_NEAREST);
	m_pBg13->SetSize(1.0f);
	m_pBg13->SetPos(stEMVec3(0, m_nUpY, 0));
	m_pBg13->SetBlend(true);
	m_pBg13->SetBackFaceCulling(true);
	m_pBg13->SetBoundingBoxCalc(false);
	m_pBg13->SetFrstumCullingFlag(false);
	Commit(0, "Bg13", m_pBg13);

	m_pBg14 = new CEMPlane();
	m_pBg14->SetTexture("Data/Image/메뉴/메인/배경 하.png", GL_REPEAT, GL_NEAREST);
	m_pBg14->SetSize(1.0f);
	m_pBg14->SetPos(stEMVec3(0, m_nDownY, 0));
	m_pBg14->SetBlend(true);
	m_pBg14->SetBackFaceCulling(true);
	m_pBg14->SetBoundingBoxCalc(false);
	m_pBg14->SetFrstumCullingFlag(false);
	Commit(0, "Bg14", m_pBg14);

	m_pBg15 = new CEMPlane();
	m_pBg15->SetTexture("Data/Image/메뉴/메인/톱니1.png", GL_REPEAT, GL_NEAREST);
	m_pBg15->SetSize(1.0f);
	m_pBg15->SetPos(stEMVec3(-630, 350, 0));
	m_pBg15->SetBlend(true);
	m_pBg15->SetBackFaceCulling(true);
	m_pBg15->SetBoundingBoxCalc(false);
	m_pBg15->SetFrstumCullingFlag(false);
	m_pBg15->SetShow(false);
	Commit(1, "Bg15", m_pBg15);

	m_pBg16 = new CEMPlane();
	m_pBg16->SetTexture("Data/Image/메뉴/메인/톱니2.png", GL_REPEAT, GL_NEAREST);
	m_pBg16->SetSize(0.8f);
	m_pBg16->SetPos(stEMVec3(650, -300, 0));
	m_pBg16->SetBlend(true);
	m_pBg16->SetBackFaceCulling(true);
	m_pBg16->SetBoundingBoxCalc(false);
	m_pBg16->SetFrstumCullingFlag(false);
	m_pBg16->SetShow(false);
	Commit(1, "Bg16", m_pBg16);

	m_pBg17 = new CEMPlane();
	m_pBg17->SetTexture("Data/Image/메뉴/메인/톱니3.png", GL_REPEAT, GL_NEAREST);
	m_pBg17->SetSize(0.8f);
	m_pBg17->SetPos(stEMVec3(650, 80, 0));
	m_pBg17->SetBlend(true);
	m_pBg17->SetBackFaceCulling(true);
	m_pBg17->SetBoundingBoxCalc(false);
	m_pBg17->SetFrstumCullingFlag(false);
	m_pBg17->SetShow(false);
	Commit(1, "Bg17", m_pBg17);

	m_pBg18 = new CEMPlane();
	m_pBg18->SetTexture("Data/Image/메뉴/메인/톱니4.png", GL_REPEAT, GL_NEAREST);
	m_pBg18->SetSize(1.0f);
	m_pBg18->SetPos(stEMVec3(-620, -300, 0));
	m_pBg18->SetBlend(true);
	m_pBg18->SetBackFaceCulling(true);
	m_pBg18->SetBoundingBoxCalc(false);
	m_pBg18->SetFrstumCullingFlag(false);
	m_pBg18->SetShow(false);
	Commit(1, "Bg18", m_pBg18);
	//=============================================================================================

	//임무 성공 글씨
	//=================================================================================================

	m_pMC1 = new CEMPlane();
	m_pMC1->SetTexture("Data/Image/메뉴/결과창/임무 성공1.png", GL_REPEAT, GL_NEAREST);
	m_pMC1->SetSize(m_fMES[0]);
	m_pMC1->SetPos(stEMVec3(m_nMEX[0], 15, 0));
	m_pMC1->SetBlend(true);
	m_pMC1->SetBackFaceCulling(true);
	m_pMC1->SetBoundingBoxCalc(false);
	m_pMC1->SetFrstumCullingFlag(false);
	m_pMC1->SetShow(false);
	Commit(-2, "MC1", m_pMC1);

	m_pMC2 = new CEMPlane();
	m_pMC2->SetTexture("Data/Image/메뉴/결과창/임무 성공2.png", GL_REPEAT, GL_NEAREST);
	m_pMC2->SetSize(m_fMES[1]);
	m_pMC2->SetPos(stEMVec3(m_nMEX[1], 15, 0));
	m_pMC2->SetBlend(true);
	m_pMC2->SetBackFaceCulling(true);
	m_pMC2->SetBoundingBoxCalc(false);
	m_pMC2->SetFrstumCullingFlag(false);
	m_pMC2->SetShow(false);
	Commit(-2, "MC2", m_pMC2);

	m_pMC3 = new CEMPlane();
	m_pMC3->SetTexture("Data/Image/메뉴/결과창/임무 성공3.png", GL_REPEAT, GL_NEAREST);
	m_pMC3->SetSize(m_fMES[2]);
	m_pMC3->SetPos(stEMVec3(m_nMEX[2], 15, 0));
	m_pMC3->SetBlend(true);
	m_pMC3->SetBackFaceCulling(true);
	m_pMC3->SetBoundingBoxCalc(false);
	m_pMC3->SetFrstumCullingFlag(false);
	m_pMC3->SetShow(false);
	Commit(-2, "MC3", m_pMC3);

	m_pMC4 = new CEMPlane();
	m_pMC4->SetTexture("Data/Image/메뉴/결과창/임무 성공4.png", GL_REPEAT, GL_NEAREST);
	m_pMC4->SetSize(m_fMES[3]);
	m_pMC4->SetPos(stEMVec3(m_nMEX[3], 15, 0));
	m_pMC4->SetBlend(true);
	m_pMC4->SetBackFaceCulling(true);
	m_pMC4->SetBoundingBoxCalc(false);
	m_pMC4->SetFrstumCullingFlag(false);
	m_pMC4->SetShow(false);
	Commit(-2, "MC4", m_pMC4);

	//==================================================================================================

	//임무 실패 글씨
	//========================================================================================================

	m_pMF1 = new CEMPlane();
	m_pMF1->SetTexture("Data/Image/메뉴/결과창/임무 실패1.png", GL_REPEAT, GL_NEAREST);
	m_pMF1->SetSize(m_fMES[0]);
	m_pMF1->SetPos(stEMVec3(m_nMEX[0], 15, 0));
	m_pMF1->SetBlend(true);
	m_pMF1->SetBackFaceCulling(true);
	m_pMF1->SetBoundingBoxCalc(false);
	m_pMF1->SetFrstumCullingFlag(false);
	m_pMF1->SetShow(false);
	Commit(-2, "MF1", m_pMF1);

	m_pMF2 = new CEMPlane();
	m_pMF2->SetTexture("Data/Image/메뉴/결과창/임무 실패2.png", GL_REPEAT, GL_NEAREST);
	m_pMF2->SetSize(m_fMES[1]);
	m_pMF2->SetPos(stEMVec3(m_nMEX[1], 15, 0));
	m_pMF2->SetBlend(true);
	m_pMF2->SetBackFaceCulling(true);
	m_pMF2->SetBoundingBoxCalc(false);
	m_pMF2->SetFrstumCullingFlag(false);
	m_pMF2->SetShow(false);
	Commit(-2, "MF2", m_pMF2);

	m_pMF3 = new CEMPlane();
	m_pMF3->SetTexture("Data/Image/메뉴/결과창/임무 실패3.png", GL_REPEAT, GL_NEAREST);
	m_pMF3->SetSize(m_fMES[2]);
	m_pMF3->SetPos(stEMVec3(m_nMEX[2], 15, 0));
	m_pMF3->SetBlend(true);
	m_pMF3->SetBackFaceCulling(true);
	m_pMF3->SetBoundingBoxCalc(false);
	m_pMF3->SetFrstumCullingFlag(false);
	m_pMF3->SetShow(false);
	Commit(-2, "MF3", m_pMF3);

	m_pMF4 = new CEMPlane();
	m_pMF4->SetTexture("Data/Image/메뉴/결과창/임무 실패4.png", GL_REPEAT, GL_NEAREST);
	m_pMF4->SetSize(m_fMES[3]);
	m_pMF4->SetPos(stEMVec3(m_nMEX[3], 15, 0));
	m_pMF4->SetBlend(true);
	m_pMF4->SetBackFaceCulling(true);
	m_pMF4->SetBoundingBoxCalc(false);
	m_pMF4->SetFrstumCullingFlag(false);
	m_pMF4->SetShow(false);
	Commit(-2, "MF4", m_pMF4);
	m_bMW = false;
	//===========================================================================================================
	D_CAMERA->SetPos(m_stCamPos);
}

void CResultScene::Update(CSceneWork* pSceneWork, float dt)
{
	
	m_fSceneCntTime += dt;
	if (m_fSceneCntTime > 1.0f)
	{
		m_fSceneCntTime2 += dt;
		if (m_fSceneCntTime2 > 0.3f)
		{
			if (m_bMW == false)
			{
				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_END], D_MNG->GetMusicVolume(), false);
				m_bMW = true;
			}
		}
		if (m_bSceneChange == false)
		{
			if (m_bResultWin == false)
			{
				m_pBg13->SetPos(stEMVec3(0, m_nUpY, 0));
				m_pBg14->SetPos(stEMVec3(0, m_nDownY, 0));
				m_nUpY = 800;
				m_nDownY = -625;
				if (g_GMng.m_bmission == true)
				{
					m_pMC1->SetShow(true);
					if (m_pMC1->GetSize().m_fY > 1.0f)
					{
						m_pMC1->SetSize(m_fMES[0]);
						m_fMES[0] -= 0.16f;
					}
					if (m_pMC1->GetSize().m_fY <= 1.0f)
					{
						m_pMC2->SetShow(true);
						if (m_pMC2->GetSize().m_fY > 1.0f)
						{
							m_pMC2->SetSize(m_fMES[1]);
							m_fMES[1] -= 0.16f;
						}
					}
					if (m_pMC2->GetSize().m_fY <= 1.0f)
					{
						m_pMC3->SetShow(true);
						if (m_pMC3->GetSize().m_fY > 1.0f)
						{
							m_pMC3->SetSize(m_fMES[2]);
							m_fMES[2] -= 0.16f;
						}
					}
					if (m_pMC3->GetSize().m_fY <= 1.0f)
					{
						m_pMC4->SetShow(true);
						if (m_pMC4->GetSize().m_fY > 1.0f)
						{
							m_pMC4->SetSize(m_fMES[3]);
							m_fMES[3] -= 0.16f;
						}
					}
					if (m_pMC4->GetSize().m_fY <= 1.0f)
					{
						m_fSceneCntTime += dt;
						if (m_fSceneCntTime > 1.0f)
						{
							if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORUP]) && D_MNG->m_bSound)
								D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORUP], D_MNG->GetSoundVolume());
							m_pBg11->SetPos(stEMVec3(m_nLeftX, 0, 0));
							m_pBg12->SetPos(stEMVec3(m_nRightX, 0, 0));
							m_pMC1->SetPos(stEMVec3(m_nMEX[0], 15, 0));
							m_pMC2->SetPos(stEMVec3(m_nMEX[1], 15, 0)); 
							m_pMC3->SetPos(stEMVec3(m_nMEX[2], 15, 0));
							m_pMC4->SetPos(stEMVec3(m_nMEX[3], 15, 0));
							m_pBg15->SetZRot(-m_fIndex);
							m_pBg16->SetZRot(-m_fIndex);
							m_pBg17->SetZRot(m_fIndex);
							m_pBg18->SetZRot(m_fIndex);
							m_nLeftX -= 17;
							m_nRightX += 17;
							m_nMEX[0] -= 17;
							m_nMEX[1] -= 17;
							m_nMEX[2] += 17;
							m_nMEX[3] += 17;
							m_fIndex += 1;
							if (m_pBg11->GetPosVec2().m_fX < -1200)
							{
								m_bResultWin = true;
							}
						}
					}
				}

				if (g_GMng.m_bmission == false)
				{
					m_pMF1->SetShow(true);
					if (m_pMF1->GetSize().m_fY > 1.0f)
					{
						m_pMF1->SetSize(m_fMES[0]);
						m_fMES[0] -= 0.16f;
					}
					if (m_pMF1->GetSize().m_fY <= 1.0f)
					{
						m_pMF2->SetShow(true);
						if (m_pMF2->GetSize().m_fY > 1.0f)
						{
							m_pMF2->SetSize(m_fMES[1]);
							m_fMES[1] -= 0.16f;
						}
					}
					if (m_pMF2->GetSize().m_fY <= 1.0f)
					{
						m_pMF3->SetShow(true);
						if (m_pMF3->GetSize().m_fY > 1.0f)
						{
							m_pMF3->SetSize(m_fMES[2]);
							m_fMES[2] -= 0.16f;
						}
					}
					if (m_pMF3->GetSize().m_fY <= 1.0f)
					{
						m_pMF4->SetShow(true);
						if (m_pMF4->GetSize().m_fY > 1.0f)
						{
							m_pMF4->SetSize(m_fMES[3]);
							m_fMES[3] -= 0.16f;
						}
					}
					if (m_pMF4->GetSize().m_fY <= 1.0f)
					{
						m_fSceneCntTime += dt;
						if (m_fSceneCntTime > 3.0f)
						{
							if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN]) && D_MNG->m_bSound)
								D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN], D_MNG->GetSoundVolume());
							m_pBg11->SetPos(stEMVec3(m_nLeftX, 0, 0));
							m_pBg12->SetPos(stEMVec3(m_nRightX, 0, 0));
							m_pMF1->SetPos(stEMVec3(m_nMEX[0], 15, 0));
							m_pMF2->SetPos(stEMVec3(m_nMEX[1], 15, 0));
							m_pMF3->SetPos(stEMVec3(m_nMEX[2], 15, 0));
							m_pMF4->SetPos(stEMVec3(m_nMEX[3], 15, 0));
							m_pBg15->SetZRot(-m_fIndex);
							m_pBg16->SetZRot(-m_fIndex);
							m_pBg17->SetZRot(m_fIndex);
							m_pBg18->SetZRot(m_fIndex);
							m_nLeftX -= 17;
							m_nRightX += 17;
							m_nMEX[0] -= 17;
							m_nMEX[1] -= 17;
							m_nMEX[2] += 17;
							m_nMEX[3] += 17;
							m_fIndex += 1;
							if (m_pBg11->GetPosVec2().m_fX < -1200)
							{
								m_bResultWin = true;
							}
						}
					}
				}
			}
			else
			{

				m_fCntTime += dt;
				m_fCntTime2 += dt;
				m_fCntTime3 += dt;
				m_pWin->GetWindow("Result1")->SetVisible(true);
				m_pNumberOth->SetShow(true);
				m_pNumberOth2->SetShow(true);
				m_pNumberOth3->SetShow(true);

				//킬 점수
				if (m_fCntTime > 0.01f)
				{
					//0.01초
					m_fCount += 100;
					m_pNumberOth->SetNumber(m_fCount);
					m_fCntTime = 0.0f;
					if (m_fCount >= m_fKillScore)
					{
						m_fCount = m_fKillScore;
					}
				}
				//게임 점수
				if (m_fCntTime2 > 0.01f)
				{
					//0.01초
					m_fCount2 += 100;
					m_pNumberOth2->SetNumber(m_fCount2); 
					m_fCntTime2 = 0.0f;
					if (m_fCount2 >= m_fGameScore)
					{
						m_fCount2 = m_fGameScore;
					}
				}
				//총합 점수
				if (m_fCntTime3 > 0.001f)
				{
					//0.01초
					m_fCount3 += 100;
					m_pNumberOth3->SetNumber(m_fCount3);
					m_fCntTime3 = 0.0f;
					if (m_fCount3 >= m_fTotalScore)
					{
						m_fCount3 = m_fTotalScore;
					}

				}
			}

		}
		if (m_bSceneChange == true)
		{
			m_fSceneCntTime += dt;
			m_pWin->GetWindow("Result1")->SetVisible(false);
			m_pNumberOth->SetShow(false);
			m_pNumberOth2->SetShow(false);
			m_pNumberOth3->SetShow(false);
			if (m_pBg11->GetPosVec2().m_fX < -295)
			{
				if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN]) && D_MNG->m_bSound)
					D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN], D_MNG->GetSoundVolume());
				m_pBg11->SetPos(stEMVec3(m_nLeftX, 0, 0));
				m_pBg12->SetPos(stEMVec3(m_nRightX, 0, 0));
				m_pBg15->SetZRot(m_fIndex);
				m_pBg16->SetZRot(m_fIndex);
				m_pBg17->SetZRot(-m_fIndex);
				m_pBg18->SetZRot(-m_fIndex);
				m_nLeftX += 17;
				m_nRightX -= 17;
				m_fIndex += 1;
			}
			if (m_pBg11->GetPosVec2().m_fX >= -295)
			{
				if (m_pBg13->GetPosVec2().m_fY > 160)
				{
					if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN]) && D_MNG->m_bSound)
						D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN], D_MNG->GetSoundVolume());
					m_pBg13->SetPos(stEMVec3(0, m_nUpY, 0));
					m_pBg14->SetPos(stEMVec3(0, m_nDownY, 0));
					m_pBg15->SetZRot(m_fIndex);
					m_pBg16->SetZRot(m_fIndex);
					m_pBg17->SetZRot(-m_fIndex);
					m_pBg18->SetZRot(-m_fIndex);
					m_nUpY -= 17;
					m_nDownY += 17;
					m_fIndex += 1;
					if (m_pBg13->GetPosVec2().m_fY <= 160)
					{
						if (m_fSceneCntTime > 2.0f)
						{
							m_fCount = 0.0f;
							m_fCount2 = 0.0f;
							m_fCount3 = 0.0f;
							m_fSceneCntTime = 0.0f;
							m_fSceneCntTime2 = 0.0f;
							m_fMES[0] = 5.0f;
							m_fMES[1] = 5.0f;
							m_fMES[2] = 5.0f;
							m_fMES[3] = 5.0f;
							m_nMEX[0] = -500;
							m_nMEX[1] = -200;
							m_nMEX[2] = 200;
							m_nMEX[3] = 500;
							m_nUpY = 800;
							m_nDownY = -625;

							m_bSceneChange = false;
							m_bResultWin = false;
							D_SCENE->ChangeScene("menu_ext");
						}
					}
				}
			}

		}
	}


	if (D_INPUT->IsKeyDown(VK_L))
	{
		D_CAMERA->MoveX(5.0f);
	}
	if (D_INPUT->IsKeyDown(VK_J))
	{
		D_CAMERA->MoveX(-5.0f);
	}
	if (D_INPUT->IsKeyDown(VK_I))
	{
		D_CAMERA->MoveY(5.0f);
	}
	if (D_INPUT->IsKeyDown(VK_K))
	{
		D_CAMERA->MoveY(-5.0f);
	}
	if (D_INPUT->IsKeyDown(VK_U))
	{
		D_CAMERA->MoveZ(5.0f);
	}
	if (D_INPUT->IsKeyDown(VK_O))
	{
		D_CAMERA->MoveZ(-5.0f);
	}


	CRootScene::Update(pSceneWork, dt);
}


void CResultScene::Render(CSceneWork* pSceneWork)
{

	CRootScene::Render(pSceneWork);
}

void CResultScene::Exit(CSceneWork* pSceneWork)
{
	Destroy();
}

void CResultScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	stEMVec2 stDesPos(0.0f, 0.0f);

	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{


	}break;
	}
}

void CResultScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{

	}break;

	case E_MOUSE_RIGHT:
	{

	}break;
	}
}

void CResultScene::MouseMoveEvent(stMouseInfo stPos)
{


}

void CResultScene::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{
	int nX = 0;

	CEMWindow* pWin = NULL;
	pWin = GetUI("Result");
	if (sWindowName == "Result1")
	{
		switch (eType)
		{
		case E_BUTTON:
		{
			switch (id)
			{
			case 1:
			{
				Dprintf("결과-메뉴로 \n");
				m_bSceneChange = true;
			}break;
			}break;

		case E_CHECK_BOX:
		{

		}break;

		case E_RADIO_BUTTON:
		{

		}break;
		}
		}
	}
}

HRESULT CResultScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		int x = 0;
	}break;
	}

	return msg;
}