#include "stdafx.h"
#include "Music.h"


CMusic::CMusic()
{
	//Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	Mix_OpenAudio(88200, MIX_DEFAULT_FORMAT, 2, NULL);

	//music
	music[0] = Mix_LoadMUS("music/runaway.wav");
	music[1] = Mix_LoadMUS("music/Jumper_titleScreenMusic_.wav");
	music[2] = Mix_LoadMUS("music/finalstoke.wav");

	//sound
	sound[0] = Mix_LoadWAV("music/sounds/bass1.wav");
	sound[1] = Mix_LoadWAV("music/sounds/missle_launch.wav");
	sound[2] = Mix_LoadWAV("music/sounds/laserShot.wav");
	sound[3] = Mix_LoadWAV("music/sounds/beep.wav");

	if (music[0] == NULL)
	{
		std::cout << "music was not loaded!";
	}
}


CMusic::~CMusic()
{
	Mix_FreeMusic(music[0]);
	Mix_FreeMusic(music[1]);
	Mix_FreeMusic(music[2]);

	Mix_FreeChunk(sound[0]);
	Mix_FreeChunk(sound[1]);
	Mix_FreeChunk(sound[2]);
	Mix_FreeChunk(sound[3]);

	Mix_CloseAudio();
}

void CMusic::playMusic(int song)
{
	Mix_PlayMusic(music[song], -1);
}

void CMusic::playSound(int soundNumber)
{
	Mix_PlayChannel(-1, sound[soundNumber], 0);
}
