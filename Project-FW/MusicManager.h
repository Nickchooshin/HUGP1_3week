#pragma once
#include "Singleton.h"
#include <fmod.hpp>
#include <fmod_errors.h>
//#include <vector>
#include <map>
#include <string>

class MusicManager : public Singleton<MusicManager>
{
protected:
	FMOD::System * System;
	//std::vector<FMOD::Sound *> Sounds;
	std::map<std::string, FMOD::Sound *> Sounds ;
	FMOD::Channel * Channels[32];

public:
	MusicManager(void);
	virtual ~MusicManager(void);

public:
	bool Initialize();
	void Terminate();

	FMOD::Sound* LoadMusic(char *Filename, bool isStream, bool isLoop = true);
	void PlayMusic(FMOD::Sound* Sound, int Channel = 0);
	void StopMusic(int Channel = 0);
	void Loop();

	void Reset();
};

#define g_MusicManager MusicManager::GetInstance()