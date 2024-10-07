#pragma once

#include "stdafx.h"

/**
	@file    : Mng.h
	@author  : hwang
	@version : 1.0f
	@brief   : 메니져 클래스
 */

class CMng
{
private:
	float	m_fMusicVolume;		// 배경음
	float	m_fSoundVolume;		// 효과음
	bool	m_bSndLoading;		// 로딩

public:
	SAMPLE_HANDLE m_BackSnd[E_SND_MAX];		// 배경음
	SAMPLE_HANDLE m_ClickSnd[E_FXSND_MAX];		// 클릭음
	SAMPLE_HANDLE m_PEkSnd[D_PE_MAX][2];		// 클릭음
	SAMPLE_HANDLE m_SEkSnd[D_SE_MAX][2];		// 클릭음
	SAMPLE_HANDLE m_MEkSnd[D_ME_MAX][2];		// 클릭음
	//SAMPLE_HANDLE m_FXSnd;		// 클릭음
	bool m_bMusic;
	bool m_bSound;
public:
	

private:
	CMng()
	{
		m_bSndLoading = false;
		for (int i = 0; i < E_SND_MAX; i++)
		{
			m_BackSnd[i] = NULL;

		}
		m_bMusic = TRUE;
		m_bSound = TRUE;
		for (int i = 0; i < E_FXSND_MAX; i++)
		{
			m_ClickSnd[i] = NULL;

		}
		m_fSoundVolume = 1.0f;
		m_fMusicVolume = 0.8f;
	}

public:
	static CMng* Instance();

	~CMng()
	{

	}

public:
	void CreateSound();

public:
	float GetMusicVolume() { return m_fMusicVolume; }
	void SetMusicVolume(float fVolume);

	float GetSoundVolume() { return m_fSoundVolume; }
	void SetSoundVolume(float fVolume);
};
