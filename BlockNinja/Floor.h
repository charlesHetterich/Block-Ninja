#pragma once
#include "SDL_setup.h"
#include "sprites.h"
class CFloor
{
public:
	CFloor(CSDL_setup* csdl_setup);
	~CFloor();
	void drawFloors();
	void moveFloors();

private:
	Csprites* floor[20];
	int floorsAmount;
	int currentFloor;
	int floorCycle;

	int floorW;
	int floorH;
	int floorSpeed;

	int initialFloorX;

	CSDL_setup* sdl_Setup;
};

