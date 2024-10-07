#include "stdafx.h"

void CMenuScene_Ext::Enter(CSceneWork* pSceneWork)
{
	D_MNG->CreateSound();
	for (int i = 0; i < E_SND_MAX; i++)
	{
		D_SOUND->Stop(D_MNG->m_BackSnd[i]);
	}
	D_SOUND->Play(D_MNG->m_BackSnd[E_SND_MAIN], D_MNG->GetMusicVolume(), true);

	//메뉴 배경
	//=================================================================================
	m_pBg1 = new CEMPlane();
	m_pBg1->SetTexture("Data/Image/메뉴/메인/배경 상.png", GL_REPEAT, GL_NEAREST);
	m_pBg1->SetSize(1.0f);
	m_pBg1->SetPos(stEMVec3(0, 155, 0));
	m_pBg1->SetBlend(true);
	m_pBg1->SetBackFaceCulling(true);
	m_pBg1->SetBoundingBoxCalc(false);
	m_pBg1->SetFrstumCullingFlag(false);
	Commit(0, "Bg1", m_pBg1);

	m_pBg2 = new CEMPlane();
	m_pBg2->SetTexture("Data/Image/메뉴/메인/배경 하.png", GL_REPEAT, GL_NEAREST);
	m_pBg2->SetSize(1.0f);
	m_pBg2->SetPos(stEMVec3(0, 0, 0));
	m_pBg2->SetBlend(true);
	m_pBg2->SetBackFaceCulling(true);
	m_pBg2->SetBoundingBoxCalc(false);
	m_pBg2->SetFrstumCullingFlag(false);
	Commit(0, "Bg2", m_pBg2);

	m_pBg3 = new CEMPlane();
	m_pBg3->SetTexture("Data/Image/메뉴/배경 그림자.png", GL_REPEAT, GL_NEAREST);
	m_pBg3->SetSize(1.0f);
	m_pBg3->SetPos(stEMVec3(0, 0, 0));
	m_pBg3->SetBlend(true);
	m_pBg3->SetBackFaceCulling(true);
	m_pBg3->SetBoundingBoxCalc(false);
	m_pBg3->SetFrstumCullingFlag(false);
	Commit(0, "Bg3", m_pBg3);

	m_pBg4 = new CEMPlane();
	m_pBg4->SetTexture("Data/Image/메뉴/메인/메뉴판.png", GL_REPEAT, GL_NEAREST);
	m_pBg4->SetSize(1.0f);
	m_pBg4->SetPos(stEMVec3(0, 0, 0));
	m_pBg4->SetBlend(true);
	m_pBg4->SetBackFaceCulling(true);
	m_pBg4->SetBoundingBoxCalc(false);
	m_pBg4->SetFrstumCullingFlag(false);
	Commit(0, "Bg4", m_pBg4);

	//============================================================================================

	//메뉴 위아래 왔다갔다 하는거
	//============================================================================================
	m_pBg11 = new CEMPlane();
	m_pBg11->SetTexture("Data/Image/메뉴/메인/배경 상.png", GL_REPEAT, GL_NEAREST);
	m_pBg11->SetSize(1.0f);
	m_pBg11->SetPos(stEMVec3(0, m_nUpY, 0));
	m_pBg11->SetBlend(true);
	m_pBg11->SetBackFaceCulling(true);
	m_pBg11->SetBoundingBoxCalc(false);
	m_pBg11->SetFrstumCullingFlag(false);
	Commit(-2, "Bg11", m_pBg11);

	m_pBg12 = new CEMPlane();
	m_pBg12->SetTexture("Data/Image/메뉴/메인/배경 하.png", GL_REPEAT, GL_NEAREST);
	m_pBg12->SetSize(1.0f);
	m_pBg12->SetPos(stEMVec3(0, m_nDownY, 0));
	m_pBg12->SetBlend(true);
	m_pBg12->SetBackFaceCulling(true);
	m_pBg12->SetBoundingBoxCalc(false);
	m_pBg12->SetFrstumCullingFlag(false);
	Commit(-2, "Bg12", m_pBg12);

	m_pBg13 = new CEMPlane();
	m_pBg13->SetTexture("Data/Image/메뉴/메인/톱니1.png", GL_REPEAT, GL_NEAREST);
	m_pBg13->SetSize(1.0f);
	m_pBg13->SetPos(stEMVec3(-630, 350, 0));
	m_pBg13->SetBlend(true);
	m_pBg13->SetBackFaceCulling(true);
	m_pBg13->SetBoundingBoxCalc(false);
	m_pBg13->SetFrstumCullingFlag(false);
	Commit(-1, "Bg13", m_pBg13);

	m_pBg14 = new CEMPlane();
	m_pBg14->SetTexture("Data/Image/메뉴/메인/톱니2.png", GL_REPEAT, GL_NEAREST);
	m_pBg14->SetSize(0.8f);
	m_pBg14->SetPos(stEMVec3(650, -300, 0));
	m_pBg14->SetBlend(true);
	m_pBg14->SetBackFaceCulling(true);
	m_pBg14->SetBoundingBoxCalc(false);
	m_pBg14->SetFrstumCullingFlag(false);
	Commit(-1, "Bg14", m_pBg14);

	m_pBg15 = new CEMPlane();
	m_pBg15->SetTexture("Data/Image/메뉴/메인/톱니3.png", GL_REPEAT, GL_NEAREST);
	m_pBg15->SetSize(0.8f);
	m_pBg15->SetPos(stEMVec3(650, 80, 0));
	m_pBg15->SetBlend(true);
	m_pBg15->SetBackFaceCulling(true);
	m_pBg15->SetBoundingBoxCalc(false);
	m_pBg13->SetFrstumCullingFlag(false);
	Commit(-1, "Bg15", m_pBg15);

	m_pBg16 = new CEMPlane();
	m_pBg16->SetTexture("Data/Image/메뉴/메인/톱니4.png", GL_REPEAT, GL_NEAREST);
	m_pBg16->SetSize(1.0f);
	m_pBg16->SetPos(stEMVec3(-620, -330, 0));
	m_pBg16->SetBlend(true);
	m_pBg16->SetBackFaceCulling(true);
	m_pBg16->SetBoundingBoxCalc(false);
	m_pBg16->SetFrstumCullingFlag(false);
	Commit(-1, "Bg16", m_pBg16);
	//=============================================================================================

	m_pWin = new CEMWindow("Menu", stEMRect(0, 0, 1280, 720), this, CEMColor(1.0f, 1.0f, 1.0f, 0.0f));
	//메뉴-게임 시작
	m_pWin->AddWindow("Menu1", "Data/Image/메뉴/윈도우용 투명배경.png", stEMVec3(0.0f, 0.0f, 0.0f), CEMColor(1.0f, 1.0f, 1.0f, 1.0f));
	m_pWin->GetWindow("Menu1")->AddButton(1,	"Data/Image/메뉴/메인/게임 시작1.png",
												"Data/Image/메뉴/메인/게임 시작2.png",
												"Data/Image/메뉴/메인/게임 시작3.png",      
												stEMVec3(500.0f, 150.0f, 0.0f));
	//메뉴-설정
	m_pWin->GetWindow("Menu1")->AddButton(2,	"Data/Image/메뉴/메인/설정1.png",
												"Data/Image/메뉴/메인/설정2.png",
												"Data/Image/메뉴/메인/설정3.png",
												stEMVec3(570.0f, 300.0f, 0.0f));
	//메뉴-게임 끝
	m_pWin->GetWindow("Menu1")->AddButton(3,	"Data/Image/메뉴/메인/게임 종료1.png",
												"Data/Image/메뉴/메인/게임 종료2.png",
												"Data/Image/메뉴/메인/게임 종료3.png",
												stEMVec3(500.0f, 450.0f, 0.0f));

	m_pWin->GetWindow("Menu1")->SetVisible(false);

	m_pWin->GetWindow("Menu1")->SetLock(E_STATIC);

	//메뉴옵션-배경
	m_pWin->AddWindow("Menu2", "Data/Image/메뉴/윈도우용 투명배경.png", stEMVec3(0.0f, 0.0f, 0.0f), CEMColor(1.0f, 1.0f, 1.0f, 1.0f));
						  
	m_pWin->GetWindow("Menu2")->AddTexture(108, "Data/Image/메뉴/설정/설정 타이틀.png", stEMVec3(620.0f, 150.0f, 0.0f));
	m_pWin->GetWindow("Menu2")->SetLock(E_STATIC);

	m_pWin->GetWindow("Menu2")->SetVisible(false);

	m_pWin->AddWindow("MusicOn", "Data/Image/메뉴/설정/배경음.png", stEMVec3(440.0f, 330.0f, 0.0f));
	m_pWin->AddWindow("SoundOn", "Data/Image/메뉴/설정/효과음.png", stEMVec3(440.0f, 500.0f, 0.0f));
	m_pWin->AddWindow("MusicOff", "Data/Image/메뉴/설정/배경 음소거.png", stEMVec3(427.0f, 323.0f, 0.0f));
	m_pWin->AddWindow("SoundOff", "Data/Image/메뉴/설정/효과 음소거.png", stEMVec3(429.0f, 476.0f, 0.0f));

	m_pMusicOnWin = m_pWin->GetWindow("MusicOn");
	m_pSoundOnWin = m_pWin->GetWindow("SoundOn");
	m_pMusicOffWin = m_pWin->GetWindow("MusicOff");
	m_pSoundOffWin = m_pWin->GetWindow("SoundOff");

	m_pMusicOnWin->SetLock(E_STATIC);
	m_pSoundOnWin->SetLock(E_STATIC);
	m_pMusicOffWin->SetLock(E_STATIC);
	m_pSoundOffWin->SetLock(E_STATIC);

	m_pMusicOnWin->SetVisible(false);
	m_pSoundOnWin->SetVisible(false);
	m_pMusicOffWin->SetVisible(false);
	m_pSoundOffWin->SetVisible(false);

	//메뉴옵션-버튼
	m_pWin->AddWindow("Menu3", "Data/Image/메뉴/윈도우용 투명배경.png", stEMVec3(0.0f, 0.0f, 0.0f), CEMColor(1.0f, 1.0f, 1.0f, 1.0f));

	//메뉴옵션-배경소리 줄이기
	m_pWin->GetWindow("Menu3")->AddButton(1,	"Data/Image/메뉴/설정/-1.png", 
												"Data/Image/메뉴/설정/-2.png",
												"Data/Image/메뉴/설정/-3.png",
												stEMVec3(550.0f, 320.0f, 0.0f));
	//메뉴옵션-배경소리 키우기
	m_pWin->GetWindow("Menu3")->AddButton(2,	"Data/Image/메뉴/설정/+1.png",
												"Data/Image/메뉴/설정/+2.png",
												"Data/Image/메뉴/설정/+3.png",
												stEMVec3(700.0f, 310.0f, 0.0f));
	//메뉴옵션-배경소리 켜기
	m_pWin->GetWindow("Menu3")->AddButton(3,	"Data/Image/메뉴/설정/ON1.png",
												"Data/Image/메뉴/설정/ON2.png",
												"Data/Image/메뉴/설정/ON3.png",
												stEMVec3(570.0f, 400.0f, 0.0f));
	//메뉴옵션-배경소리 끄기
	m_pWin->GetWindow("Menu3")->AddButton(4,	"Data/Image/메뉴/설정/OFF1.png",
												"Data/Image/메뉴/설정/OFF2.png",
												"Data/Image/메뉴/설정/OFF3.png",
												stEMVec3(670.0f, 390.0f, 0.0f));
	//메뉴옵션-효과소리 줄이기
	m_pWin->GetWindow("Menu3")->AddButton(5,	"Data/Image/메뉴/설정/-1.png",
												"Data/Image/메뉴/설정/-2.png",
												"Data/Image/메뉴/설정/-3.png",
												stEMVec3(550.0f, 495.0f, 0.0f));
	//메뉴옵션-효과소리 키우기
	m_pWin->GetWindow("Menu3")->AddButton(6,	"Data/Image/메뉴/설정/+1.png",
												"Data/Image/메뉴/설정/+2.png",
												"Data/Image/메뉴/설정/+3.png",
												stEMVec3(700.0f, 480.0f, 0.0f));
	//메뉴옵션-효과소리 켜기
	m_pWin->GetWindow("Menu3")->AddButton(7,	"Data/Image/메뉴/설정/ON1.png",
												"Data/Image/메뉴/설정/ON2.png",
												"Data/Image/메뉴/설정/ON3.png",
												stEMVec3(570.0f, 560.0f, 0.0f));
	//메뉴옵션-효과소리 끄기
	m_pWin->GetWindow("Menu3")->AddButton(8,	"Data/Image/메뉴/설정/OFF1.png",
												"Data/Image/메뉴/설정/OFF2.png",
												"Data/Image/메뉴/설정/OFF3.png",
												stEMVec3(670.0f, 550.0f, 0.0f));
	//메뉴옵션-효과소리 나가기
	m_pWin->GetWindow("Menu3")->AddButton(9,	"Data/Image/메뉴/HOME1.png",
												"Data/Image/메뉴/HOME2.png",
												"Data/Image/메뉴/HOME3.png",
												stEMVec3(800.0f, 70.0f, 0.0f));
	m_pWin->GetWindow("Menu3")->SetLock(E_STATIC);

	m_pWin->GetWindow("Menu3")->SetVisible(false);

	m_pWin->AddWindow("Music0", "Data/Image/메뉴/설정/점수 0.png", stEMVec3(620.0f, 300.0f, 0.0f));
	m_pWin->AddWindow("Music1", "Data/Image/메뉴/설정/점수 1.png", stEMVec3(620.0f, 300.0f, 0.0f));
	m_pWin->AddWindow("Music2", "Data/Image/메뉴/설정/점수 2.png", stEMVec3(620.0f, 300.0f, 0.0f));
	m_pWin->AddWindow("Music3", "Data/Image/메뉴/설정/점수 3.png", stEMVec3(620.0f, 300.0f, 0.0f));
	m_pWin->AddWindow("Music4", "Data/Image/메뉴/설정/점수 4.png", stEMVec3(620.0f, 300.0f, 0.0f));
	m_pWin->AddWindow("Music5", "Data/Image/메뉴/설정/점수 5.png", stEMVec3(620.0f, 300.0f, 0.0f));

	m_pMusicWin[0] = m_pWin->GetWindow("Music0");
	m_pMusicWin[1] = m_pWin->GetWindow("Music1");
	m_pMusicWin[2] = m_pWin->GetWindow("Music2");
	m_pMusicWin[3] = m_pWin->GetWindow("Music3");
	m_pMusicWin[4] = m_pWin->GetWindow("Music4");
	m_pMusicWin[5] = m_pWin->GetWindow("Music5");
	   
	m_pMusicWin[0]->SetLock(E_STATIC);
	m_pMusicWin[1]->SetLock(E_STATIC);
	m_pMusicWin[2]->SetLock(E_STATIC);
	m_pMusicWin[3]->SetLock(E_STATIC);
	m_pMusicWin[4]->SetLock(E_STATIC);
	m_pMusicWin[5]->SetLock(E_STATIC);
	   
	m_pMusicWin[0]->SetVisible(false);
	m_pMusicWin[1]->SetVisible(false);
	m_pMusicWin[2]->SetVisible(false);
	m_pMusicWin[3]->SetVisible(false);
	m_pMusicWin[4]->SetVisible(false);
	m_pMusicWin[5]->SetVisible(false);

	m_pWin->AddWindow("Sound0", "Data/Image/메뉴/설정/점수 0.png", stEMVec3(620.0f, 470.0f, 0.0f));
	m_pWin->AddWindow("Sound1", "Data/Image/메뉴/설정/점수 1.png", stEMVec3(620.0f, 470.0f, 0.0f));
	m_pWin->AddWindow("Sound2", "Data/Image/메뉴/설정/점수 2.png", stEMVec3(620.0f, 470.0f, 0.0f));
	m_pWin->AddWindow("Sound3", "Data/Image/메뉴/설정/점수 3.png", stEMVec3(620.0f, 470.0f, 0.0f));
	m_pWin->AddWindow("Sound4", "Data/Image/메뉴/설정/점수 4.png", stEMVec3(620.0f, 470.0f, 0.0f));
	m_pWin->AddWindow("Sound5", "Data/Image/메뉴/설정/점수 5.png", stEMVec3(620.0f, 470.0f, 0.0f));

	m_pSoundWin[0] = m_pWin->GetWindow("Sound0");
	m_pSoundWin[1] = m_pWin->GetWindow("Sound1");
	m_pSoundWin[2] = m_pWin->GetWindow("Sound2");
	m_pSoundWin[3] = m_pWin->GetWindow("Sound3");
	m_pSoundWin[4] = m_pWin->GetWindow("Sound4");
	m_pSoundWin[5] = m_pWin->GetWindow("Sound5");
	   
	m_pSoundWin[0]->SetLock(E_STATIC);
	m_pSoundWin[1]->SetLock(E_STATIC);
	m_pSoundWin[2]->SetLock(E_STATIC);
	m_pSoundWin[3]->SetLock(E_STATIC);
	m_pSoundWin[4]->SetLock(E_STATIC);
	m_pSoundWin[5]->SetLock(E_STATIC);
	   
	m_pSoundWin[0]->SetVisible(false);
	m_pSoundWin[1]->SetVisible(false);
	m_pSoundWin[2]->SetVisible(false);
	m_pSoundWin[3]->SetVisible(false);
	m_pSoundWin[4]->SetVisible(false);
	m_pSoundWin[5]->SetVisible(false);


	Commit(m_pWin, E_STATIC);

	MusicChange();
}

void CMenuScene_Ext::Update(CSceneWork* pSceneWork, float dt)
{
	m_fSceneCntTime += dt;
	if (m_fSceneCntTime > 0.5f)
	{
		if (m_bSceneChange == false)
		{
			if (m_bMenuWin == false)
			{
				if (m_pBg11->GetPosVec2().m_fY < 800)
				{
					if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORUP]) && D_MNG->m_bSound)
					{
						D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORUP], D_MNG->GetSoundVolume());
					}
					m_pBg11->SetPos(stEMVec3(0, m_nUpY, 0));
					m_pBg12->SetPos(stEMVec3(0, m_nDownY, 0));
					m_pBg13->SetZRot(-m_fIndex);
					m_pBg14->SetZRot(-m_fIndex);
					m_pBg15->SetZRot(m_fIndex);
					m_pBg16->SetZRot(m_fIndex);
					m_nUpY += 17;
					m_nDownY -= 17;
					m_fIndex += 1;

				}
				else
				{
					m_bMenuWin = true;
					if (m_bMenuWin == true)
					{
						m_pWin->GetWindow("Menu1")->SetVisible(true);
					}
				}
			}
		}

		m_fSceneCntTime += dt;

		if (m_bSceneChange == true)
		{
			m_pWin->GetWindow("Menu1")->SetVisible(false);
			if (m_pBg11->GetPosVec2().m_fY > 163)
			{
				if (!D_SOUND->IsPlaying(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN]) && D_MNG->m_bSound)
					D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_DOORDOWN], D_MNG->GetSoundVolume());
				m_pBg11->SetPos(stEMVec3(0, m_nUpY, 0));
				m_pBg12->SetPos(stEMVec3(0, m_nDownY, 0));
				m_pBg13->SetZRot(m_fIndex);
				m_pBg14->SetZRot(m_fIndex);
				m_pBg15->SetZRot(-m_fIndex);
				m_pBg16->SetZRot(-m_fIndex);
				m_nUpY -= 17;
				m_nDownY += 17;
				m_fIndex += 1;
			}
			else
			{
				D_SCENE->ChangeScene("game");
				m_fSceneCntTime = 0.0f;
				m_bSceneChange = false;
				m_bMenuWin = false;
			}
		}
	}

		D_MNG->SetSoundVolume(0.2f * m_nSoundIndex);

		D_CAMERA->SetPos(m_stCamPos);
		CRootScene::Update(pSceneWork, dt);
	
}

void CMenuScene_Ext::Render(CSceneWork* pSceneWork)
{

	CRootScene::Render(pSceneWork);
}

void CMenuScene_Ext::Exit(CSceneWork* pSceneWork)
{
	Destroy();
}



void CMenuScene_Ext::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	stEMVec2 stDesPos(0.0f, 0.0f);

	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{


	}break;
	}
}

void CMenuScene_Ext::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{

	switch (eButton)
	{
		case E_MOUSE_LEFT:
		{
			stEMVec2 stPosVec2 = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
	}
}

void CMenuScene_Ext::MouseMoveEvent(stMouseInfo stPos)
{
		
}

void CMenuScene_Ext::MusicChange()
{
	if (m_pWin->GetWindow("Menu3")->GetVisible() == true)
	{
		
		if (m_nMusicIndex <= 0)
		{
			D_MNG->m_bMusic = false;
		}
		if (m_nSoundIndex > 0)
		{
			D_MNG->m_bSound = true;
		}
		if (m_nSoundIndex <= 0)
		{
			D_MNG->m_bSound = false;
		}
		if (D_MNG->m_bMusic == true)
		{
			m_pMusicOnWin->SetVisible(true);
			m_pMusicOffWin->SetVisible(false);
		}
		if (D_MNG->m_bMusic == false)
		{
			m_pMusicOnWin->SetVisible(false);
			m_pMusicOffWin->SetVisible(true);
		}
		if (D_MNG->m_bSound == false)
		{
			m_pSoundOnWin->SetVisible(false);
			m_pSoundOffWin->SetVisible(true);
		}
		if (D_MNG->m_bSound == true)
		{
			m_pSoundOnWin->SetVisible(true);
			m_pSoundOffWin->SetVisible(false);
		}
		for (int i = 0; i < 6; i++)
		{
			if (m_nMusicIndex == i)
				m_pMusicWin[i]->SetVisible(true);
			else   
				m_pMusicWin[i]->SetVisible(false);
		}

		for (int i = 0; i < 6; i++)
		{
			if (m_nSoundIndex == i)
				m_pSoundWin[i]->SetVisible(true);
			else   
				m_pSoundWin[i]->SetVisible(false);
		}
	}
	else
	{
		m_pMusicWin[0]->SetVisible(false);
		m_pMusicWin[1]->SetVisible(false);
		m_pMusicWin[2]->SetVisible(false);
		m_pMusicWin[3]->SetVisible(false);
		m_pMusicWin[4]->SetVisible(false);
		m_pMusicWin[5]->SetVisible(false);

		m_pSoundWin[0]->SetVisible(false);
		m_pSoundWin[1]->SetVisible(false);
		m_pSoundWin[2]->SetVisible(false);
		m_pSoundWin[3]->SetVisible(false);
		m_pSoundWin[4]->SetVisible(false);
		m_pSoundWin[5]->SetVisible(false);

		m_pMusicOnWin->SetVisible(false);
		m_pMusicOffWin->SetVisible(false);
		m_pSoundOnWin->SetVisible(false);
		m_pSoundOffWin->SetVisible(false);
	}
}

void CMenuScene_Ext::MapChange()
{

}

void CMenuScene_Ext::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{
	int nX = 0;

	CEMWindow* pWin = NULL;
	pWin = GetUI("Menu");

	if (sWindowName == "Menu1")
	{
		switch (eType)
		{
		case E_BUTTON:
		{
			switch (id)
			{
			case 1:
			{
				Dprintf("메뉴-게임으로 \n");
				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());

				m_bSceneChange = true;
				m_bMenuWin = false;
			}break;

			case 2:
			{
				Dprintf("메뉴-옵션 \n");
				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());

				m_pWin->GetWindow("Menu1")->SetVisible(false);
				//m_bMenuWin = false;
				m_pWin->GetWindow("Menu2")->SetVisible(true);
				m_pWin->GetWindow("Menu3")->SetVisible(true);

				MusicChange();

			}break;
			case 3:
			{
				Dprintf("메뉴게임끝 \n");
				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());

				D_WORLD->WindowsDestroy();

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

	if (sWindowName == "Menu3")
	{
		switch (eType)
		{
		case E_BUTTON:
		{
			switch (id)
			{
			case 1:
			{
				m_nMusicIndex -= 1;
				Dprintf("메뉴옵션-배경소리 줄이기 \n");

				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());
				D_MNG->SetMusicVolume(0.0f);
				Dprintf("%d \n", m_nMusicIndex);

				float fVolume = D_MNG->GetMusicVolume();

				fVolume = 0.2f * m_nMusicIndex;

				if (m_nMusicIndex <= 0)
				{
					m_nMusicIndex = 0;
				}
				if (m_nMusicIndex <= 0)
				{
					D_MNG->m_bMusic = false;
				}
				MusicChange();

				D_MNG->SetMusicVolume(fVolume);
				D_SOUND->SetVolume(D_MNG->m_BackSnd[E_SND_MAIN], fVolume);

			}break;
			case 2:
			{
				m_nMusicIndex += 1;
				Dprintf("메뉴옵션-배경소리 늘리기 \n");

				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());
				Dprintf("%d \n", m_nMusicIndex);
				float fVolume = D_MNG->GetMusicVolume();

				fVolume = 0.2f * m_nMusicIndex;

				if (m_nMusicIndex >= 5)
				{
					m_nMusicIndex = 5;
				}
				if (m_nMusicIndex > 0)
				{
					D_MNG->m_bMusic = true;
				}
				MusicChange();

				D_MNG->SetMusicVolume(fVolume);
				D_SOUND->SetVolume(D_MNG->m_BackSnd[E_SND_MAIN], fVolume);

			}break;

			case 3:
			{
				Dprintf("메뉴옵션-배경소리 켜기 \n");
				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());
				bool IsPlaying = D_SOUND->IsPlaying(D_MNG->m_BackSnd[E_SND_MAIN]);
				if (IsPlaying == false)
				{
					D_SOUND->Play(D_MNG->m_BackSnd[E_SND_MAIN], D_MNG->GetMusicVolume(), true);
					D_MNG->m_bMusic = true;
				}
				if (m_nMusicIndex <= 0)
				{
					m_nMusicIndex = 1;
				}
				
				MusicChange();


			}break;
			case 4:
			{
				Dprintf("메뉴옵션-배경소리 끄기 \n");
				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());
				bool IsPlaying = D_SOUND->IsPlaying(D_MNG->m_BackSnd[E_SND_MAIN]);
				if (IsPlaying == true)
				{
					D_SOUND->Stop(D_MNG->m_BackSnd[E_SND_MAIN]);
					D_MNG->m_bMusic = false;
				}

				MusicChange();


			}break;
			case 5:
			{

				m_nSoundIndex -= 1;
				Dprintf("메뉴옵션-효과소리 줄이기 \n");

				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());
				Dprintf("%d \n", m_nSoundIndex);
				if (m_nSoundIndex <= 0)
				{
					m_nSoundIndex = 0;
				}
				if (m_nSoundIndex <= 0)
				{
					D_MNG->m_bSound = false;
				}
				MusicChange();

			}break;
			case 6:
			{
				m_nSoundIndex += 1;
				Dprintf("메뉴옵션-효과소리 늘리기 \n");

				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());
				Dprintf("%d \n", m_nSoundIndex);
				if (m_nSoundIndex >= 5)
				{
					m_nSoundIndex = 5;
				}
				if (m_nSoundIndex > 0)
				{
					D_MNG->m_bSound = true;
				}
				MusicChange();

			}break;
			case 7:
			{

				Dprintf("메뉴옵션-효과소리 켜기 \n");
				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());
				if (m_nSoundIndex <= 0)
				{
					m_nSoundIndex = 1;
				}
				MusicChange();
			}break;
			case 8:
			{

				Dprintf("메뉴옵션-효과소리 끄기 \n");
				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());
				m_nSoundIndex = 0;
				MusicChange();
			}break;
			case 9:
			{

				Dprintf("메뉴옵션-끝내기 \n");
				D_SOUND->Play(D_MNG->m_ClickSnd[E_FXSND_CLICK], D_MNG->GetSoundVolume());
				m_pWin->GetWindow("Menu2")->SetVisible(false);
				m_pWin->GetWindow("Menu3")->SetVisible(false);
				m_pWin->GetWindow("Menu1")->SetVisible(true);
				//m_bMenuWin = true;
				MusicChange();

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
	

HRESULT CMenuScene_Ext::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
