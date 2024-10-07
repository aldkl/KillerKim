#include "stdafx.h"


CMng* CMng::Instance()
{
	static CMng instance;
	return &instance;
}


void CMng::CreateSound()
{
	if (!m_bSndLoading)
	{
		//====================================================
		// ���� 
		m_BackSnd[E_SND_MAIN] = D_SOUND->FileOpen("Data/sound/BGM/���� ȭ��/1.mp3");
		m_BackSnd[E_SND_STAGE1] = D_SOUND->FileOpen("Data/sound/BGM/1��������/1.mp3");
		m_BackSnd[E_SND_STAGE2] = D_SOUND->FileOpen("Data/sound/BGM/2��������/1.mp3");
		m_BackSnd[E_SND_STAGE3] = D_SOUND->FileOpen("Data/sound/BGM/3��������/1.mp3");
		m_BackSnd[E_SND_BOSS] = D_SOUND->FileOpen("Data/sound/BGM/����/1.mp3");
		m_BackSnd[E_SND_GAMEOVER] = D_SOUND->FileOpen("Data/sound/BGM/���� ����/1.mp3");
		//m_BackSnd[E_SND_END] = D_SOUND->FileOpen("Data/sound/FX/.mp3");



		m_ClickSnd[E_FXSND_CLICK] = D_SOUND->FileOpen("Data/sound/FX/click.ogg");
		m_ClickSnd[E_FXSND_END] = D_SOUND->FileOpen("Data/sound/FX/�ӹ�.mp3");
		m_ClickSnd[E_FXSND_HEROFIRE] = D_SOUND->FileOpen("Data/sound/FX/HeroBullet.wav");
		m_ClickSnd[E_FXSND_BOOSDIE] = D_SOUND->FileOpen("Data/sound/FX/boss_death.mp3");
		m_ClickSnd[E_FXSND_BARRIER] = D_SOUND->FileOpen("Data/sound/FX/barrier.mp3");


		m_ClickSnd[E_FXSND_DOOR1] = D_SOUND->FileOpen("Data/sound/FX/1st_door.mp3");
		m_ClickSnd[E_FXSND_DOOR2] = D_SOUND->FileOpen("Data/sound/FX/2st_door.mp3");
		m_ClickSnd[E_FXSND_DOORUP] = D_SOUND->FileOpen("Data/sound/FX/UI_SlidingDoor_Open.wav");
		m_ClickSnd[E_FXSND_DOORDOWN] = D_SOUND->FileOpen("Data/sound/FX/UI_SlidingDoor_Close.wav");
		for (int i = 0; i < D_PE_MAX; i++)
		{
			m_PEkSnd[i][0] = D_SOUND->FileOpen("Data/sound/FX/PEFIRE.wav");
			m_PEkSnd[i][1] = D_SOUND->FileOpen("Data/sound/FX/Boom.mp3");
		}
		for (int i = 0; i < D_SE_MAX; i++)
		{
			m_SEkSnd[i][0] = D_SOUND->FileOpen("Data/sound/FX/SEFIRE.mp3");
			m_SEkSnd[i][1] = D_SOUND->FileOpen("Data/sound/FX/Boom.mp3");
		}	
		for (int i = 0; i < D_ME_MAX; i++)
		{
			m_MEkSnd[i][0] = D_SOUND->FileOpen("Data/sound/FX/PEFIRE.wav");
			m_MEkSnd[i][1] = D_SOUND->FileOpen("Data/sound/FX/Boom.mp3");
		}
		//if (m_BackSnd[E_SND_MAIN] && m_BackSnd[E_SND_STAGE1] && m_BackSnd[E_SND_STAGE2] && m_BackSnd[E_SND_STAGE3] && m_BackSnd[E_SND_BOSS] && m_BackSnd[E_SND_GAMEOVER])
		//	D_SOUND->Play(m_BackSnd[E_SND_MAIN], D_MNG->GetMusicVolume(), true);

		m_bSndLoading = true;
	} 
}

void CMng::SetMusicVolume(float fVolume)
{
	m_fMusicVolume = fVolume;
}

void CMng::SetSoundVolume(float fVolume)
{
	m_fSoundVolume = fVolume;
}