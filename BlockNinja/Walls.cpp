#include "stdafx.h"
#include "Walls.h"


CWalls::CWalls(CSDL_setup* csdl_setup)
{
	//wall settings
	wallSpeed = 1;
	spawnRate = 300;


	sdl_Setup = csdl_setup;
	wallsAmount = 10;
	while (currentWall < wallsAmount)
	{
		while (currentWallPart < 2)
		{
			wall[currentWall][currentWallPart] = new Csprites(sdl_Setup->GetRenderer(), "images/white_block.png", NULL, NULL, 5, NULL, 100, 100);
			currentWallPart++;
		}
		currentWallPart = 0;
		currentWall++;
	}
	currentWall = 0;

	currentZone[0] = new Csprites(sdl_Setup->GetRenderer(), "images/zonefeeling.png", 0, 0, (wallSpeed*spawnRate) + wall[0][0]->getW(), sdl_Setup->getScreenHeight, 1, 1);
	currentZone[0]->setAplpha(0);
	currentZone[1] = new Csprites(sdl_Setup->GetRenderer(), "images/zonefeeling.png", 0, 0, (wallSpeed*spawnRate) + wall[0][0]->getW(), sdl_Setup->getScreenHeight, 1, 1);
	currentZone[1]->setAplpha(0);
}


CWalls::~CWalls()
{
	delete currentZone;
	delete wall;
}

void CWalls::spawnWalls()
{
	if (spawnTimer > spawnRate)
	{
		wall[wallCycle][0]->setX(sdl_Setup->getScreenWidth);
		wall[wallCycle][0]->setY(0);
		wall[wallCycle][0]->setH(rand() % (sdl_Setup->getScreenHeight - 170) + 20);

		wall[wallCycle][1]->setX(sdl_Setup->getScreenWidth);
		wall[wallCycle][1]->setY(wall[wallCycle][0]->getY() + wall[wallCycle][0]->getH() + 150);
		wall[wallCycle][1]->setH(sdl_Setup->getScreenHeight - wall[wallCycle][1]->getY());

		wallCycle++;
		if (wallCycle == 10) { wallCycle = 0; }
		spawnTimer = 0;
	}
	spawnTimer++;
}

void CWalls::moveWalls()
{
	while (currentWall < wallsAmount)
	{
		while (currentWallPart < 2)
		{
			wall[currentWall][currentWallPart]->setX(wall[currentWall][currentWallPart]->getX() - wallSpeed);
			currentWallPart++;
		}
		currentWallPart = 0;
		currentWall++;
	}
	currentWall = 0;
}

void CWalls::showWalls()
{
	while (currentWall < wallsAmount)
	{
		while (currentWallPart < 2)
		{
			wall[currentWall][currentWallPart]->drawReg(0, 0);
			currentWallPart++;
		}
		currentWallPart = 0;
		currentWall++;
	}
	currentWall = 0;
}


void CWalls::resetWalls()
{
	while (currentWall < wallsAmount)
	{
		while (currentWallPart < 2)
		{
			wall[currentWall][currentWallPart]->setX(NULL);
			wall[currentWall][currentWallPart]->setY(NULL);
			wall[currentWall][currentWallPart]->setH(NULL);

			wallCycle = 0;

			currentWallPart++;
		}
		currentWallPart = 0;
		currentWall++;
	}
	currentWall = 0;
	playerInZone = false;
}

void CWalls::newZone(int newPos)
{	
	currentZone[zoneChangeCycle]->setFrame(2);
	currentZone[zoneChangeCycle]->setAplpha(250);

	zoneChangeCycle++;
	if (zoneChangeCycle == 2) { zoneChangeCycle = 0; }

	currentZone[zoneChangeCycle]->setFrame(1);
	currentZone[zoneChangeCycle]->setX(newPos);
	playerInZone = true;
}

void CWalls::moveZone()
{
	currentZone[0]->setX(currentZone[0]->getX() - wallSpeed);
	currentZone[1]->setX(currentZone[1]->getX() - wallSpeed);

	if (zoneChangeCycle != 0) 
	{ 
		if (currentZone[0]->getAlpha() >= 1) currentZone[0]->setAplpha(currentZone[0]->getAlpha() - 1);
		if (currentZone[1]->getAlpha() < 150) currentZone[1]->setAplpha(currentZone[1]->getAlpha() + 2); 
	}
	if (zoneChangeCycle != 1) 
	{ 
		if (currentZone[1]->getAlpha() >= 1) currentZone[1]->setAplpha(currentZone[1]->getAlpha() - 1);
		if (currentZone[0]->getAlpha() < 150) currentZone[0]->setAplpha(currentZone[0]->getAlpha() + 2); 
	}
}

void CWalls::showZone()
{
	if (playerInZone == true)
	{
		currentZone[0]->drawReg(0, 0);
		currentZone[1]->drawReg(0, 0);
	}
}