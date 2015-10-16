#pragma once
class CMusic
{
public:
	CMusic();
	~CMusic();
	void playMusic(int song);
	void playSound(int soundNumber);

private:
	Mix_Music *music[3];
	Mix_Chunk *sound[4];
};

