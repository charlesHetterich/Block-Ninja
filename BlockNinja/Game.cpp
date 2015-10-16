#include "stdafx.h"
#include "Game.h"


CGame::CGame()
{
	quit = false;
	screenWidth = 600;
	screenHeight = 700;
	sdl_Setup = new CSDL_setup(&quit, screenWidth, screenHeight);

	background = new Csprites(sdl_Setup->GetRenderer(), "images/background.png", 0, 0, screenWidth, screenHeight, 100, 100);
	player = new CPlayer(sdl_Setup);

	//initialize game objects
	walls = new CWalls(sdl_Setup);
	textAndOptions = new CTextAndOptions(sdl_Setup);

	//initialize score
	score = new CScore(sdl_Setup);

	//gives game an FPS
	runSpeed = 3; //12 is about 80 FPS
	runTime = SDL_GetTicks();

	//the mouse
	mouse = new CMouse(sdl_Setup);
	mouseCollision = new CCollision();

	//set a randomizer seed
	srand(time(NULL));
}


CGame::~CGame()
{
	delete mouseCollision;
	delete mouse;
	delete textAndOptions;
	delete score;
	delete sdl_Setup;
	delete background;
	delete player;
	delete walls;
}

void CGame::gameLoop()
{
	while (!quit && sdl_Setup->mainEvent->type != SDL_QUIT)
	{
		if (runTime + runSpeed < SDL_GetTicks())
		{
			sdl_Setup->begin();

			mouse->setMousePosition();

			theGame();

			sdl_Setup->end();

			runTime = SDL_GetTicks();
		}
	}
}

int CGame::theGame()
{
	background->drawReg(0, 0);

	if (!player->getPlayerPlaying())
	{
		textAndOptions->displayStartInstruction();
	}

	if (player->getPlayerPlaying())
	{
		if (player->getPlayerLife())
		{
			walls->moveZone();
			walls->moveWalls();
			walls->spawnWalls();
			walls->showZone();
		}

		walls->showWalls();
		score->displayScore();
	}
	
	if (player->getPlayerLife()) { player->movePlayer(); }
	player->drawPlayerPath();
	player->drawPlayer();

	if (player->checkForNewZone(walls))
	{
		walls->newZone(player->player->getX() + player->player->getW());
		score->setScore(score->getScore() + 1);
	}

	if (player->checkCollision(walls))
	{
		player->playerDie();
	}

	if (!player->getPlayerLife())
	{
		textAndOptions->displayDeadScreen();
		if (mouse->mouseLeftClick() && mouseCollision->checkMouseCollision(mouse->getMouseX(), mouse->getMouseY(), textAndOptions->restartButton->getRect()))
		{
			player->resetPlayer();
			walls->resetWalls();
			score->resetScore();
		}
	}

	return 0;
}