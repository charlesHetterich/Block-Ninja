#pragma once
#include "sprites.h"
#include "SDL_setup.h"

class CBackground
{
public:
	CBackground();
	~CBackground();

private:
	int backGroundItemAmount;
	int currentBackground;

	Csprites* lights[10];
};

