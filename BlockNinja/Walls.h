#pragma once
#include "SDL_setup.h"
#include "sprites.h"
class CWalls
{
public:
	CWalls(CSDL_setup* csdl_setup);
	~CWalls();
	void spawnWalls();
	void showWalls();
	void moveWalls();
	void moveZone();
	void showZone();
	void newZone(int newPos);

	void resetWalls();

	Csprites* wall[10][2];

private:
	int zoneChangeCycle;
	Csprites* currentZone[2];
	int wallSpeed;
	int wallsAmount;

	int currentWall;
	int currentWallPart;

	int wallCycle;

	int spawnTimer;
	int spawnRate;

	bool playerInZone;

	CSDL_setup* sdl_Setup;
};

