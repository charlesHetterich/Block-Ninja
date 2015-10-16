#include "stdafx.h"
#include "SDL_setup.h"
#include "sprites.h"
#include "Text.h"
#include "Music.h"
#include "Collision.h"
#include "Walls.h"
#include "Player.h"
#include "Score.h"
#include "TextAndOptions.h"
#include "Mouse.h"
#pragma once
class CGame
{
public:
	CGame();
	~CGame();
	void gameLoop();
	int theGame();

private:
	Csprites* background;
	CPlayer* player;

	//score
	CScore* score;

	//game objects
	CWalls* walls;
	CTextAndOptions* textAndOptions;

	int screenWidth;
	int screenHeight;

	//gives game an FPS
	int runTime;
	int runSpeed;

	//the mouse
	CMouse* mouse;
	CCollision* mouseCollision;

	bool quit;
	CSDL_setup* sdl_Setup;
};

