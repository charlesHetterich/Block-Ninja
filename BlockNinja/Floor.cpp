#include "stdafx.h"
#include "Floor.h"


CFloor::CFloor(CSDL_setup* csdl_setup)
{
	sdl_Setup = csdl_setup;

	floorW = 50;
	floorH = 40;
	floorSpeed = 1;

	floorsAmount = 20;

	while (currentFloor < floorsAmount)
	{
		floor[currentFloor] = new Csprites(sdl_Setup->GetRenderer(), "images/floor.png", initialFloorX, sdl_Setup->getScreenHeight - floorH, floorW, floorH, 48, 48);
		initialFloorX += floorW;
		currentFloor++;
	}
	currentFloor = 0;
}


CFloor::~CFloor()
{
	delete floor;
}

void CFloor::drawFloors()
{
	while (currentFloor < floorsAmount)
	{
		floor[currentFloor]->drawReg(0, 0);
		currentFloor++;
	}
	currentFloor = 0;
}

void CFloor::moveFloors()
{
	while (currentFloor < floorsAmount)
	{
		floor[currentFloor]->setX(floor[currentFloor]->getX() - floorSpeed);
		
		if (floor[currentFloor]->getX() + floor[currentFloor]->getW() < 0 && currentFloor != 0) { floor[currentFloor]->setX(floor[currentFloor - 1]->getX() + floor[currentFloor - 1]->getW()); }
		if (floor[currentFloor]->getX() + floor[currentFloor]->getW() < 0 && currentFloor == 0) { floor[currentFloor]->setX(floor[floorsAmount - 1]->getX() + floor[floorsAmount - 1]->getW() - floorSpeed); }

		currentFloor++;
	}
	currentFloor = 0;


}