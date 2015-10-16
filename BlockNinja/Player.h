#pragma once
#include "SDL_setup.h"
#include "sprites.h"
#include "Collision.h"
#include "Walls.h"
class CPlayer
{
public:
	CPlayer(CSDL_setup* csdl_setup);
	~CPlayer();
	void drawPlayer();
	void drawPlayerPath();
	void movePlayer();
	bool checkCollision(CWalls* walls);
	bool checkForNewZone(CWalls* walls);
	bool getPlayerPlaying();
	void playerDie();
	bool getPlayerLife();
	
	void resetPlayer();
	Csprites* player;
private:

	int playerDeathImageFrameRate;
	int playerDeathImageFrameTimer;
	Csprites* playerDeathImage;
	Csprites* playersPath[50];
	int playersPathAmount;
	int currentPlayersPath;
	int playerPathCycle;
	int playerPathShrinkSpeed;
	int playerPathShrinkTimer;
	bool changePathY;

	int playerSpeed;
	bool playerMoving;
	bool playerAlive;

	CCollision* wallCollisions;
	int wallsAmount;
	int currentWall;
	int currentWallPart;

	CSDL_setup* sdl_Setup;
};

