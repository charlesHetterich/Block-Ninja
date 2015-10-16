#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer(CSDL_setup* csdl_setup)
{
	sdl_Setup = csdl_setup;

	player = new Csprites(sdl_Setup->GetRenderer(), "images/white_block.png", 100, sdl_Setup->getScreenHeight / 2, 20, 20, 100, 100);
	playerDeathImage = new Csprites(sdl_Setup->GetRenderer(), "images/playerdie.png", NULL, NULL, 20, 20, 16, 18);
	playerDeathImageFrameRate = 10;

	playerSpeed = 2;
	playerPathShrinkSpeed = 4;

	wallsAmount = 10;

	//players trail
	playersPathAmount = 50;
	while (currentPlayersPath < playersPathAmount)
	{
		playersPath[currentPlayersPath] = new Csprites(sdl_Setup->GetRenderer(), "images/white_block.png", NULL, NULL, NULL, NULL, 100, 100);
		currentPlayersPath++;
	}
	currentPlayersPath = 0;

	wallCollisions = new CCollision();
	playerAlive = true;
}


CPlayer::~CPlayer()
{
	delete playerDeathImage;
	delete playersPath;
	delete player;
	delete wallCollisions;
}

void CPlayer::drawPlayerPath()
{
	if (playerPathShrinkTimer > playerPathShrinkSpeed && playerAlive)
	{
		playersPath[playerPathCycle]->setW(player->getW());
		playersPath[playerPathCycle]->setH(player->getH());
		playersPath[playerPathCycle]->setX(player->getX());
		playersPath[playerPathCycle]->setY(player->getY());
		playersPath[playerPathCycle]->setAplpha(250);

		playerPathCycle++;
	}
	if (playerPathCycle == playersPathAmount) { playerPathCycle = 0; }

	while (currentPlayersPath < playersPathAmount)
	{
		playersPath[currentPlayersPath]->drawReg(0, 0);
		
		if (playerPathShrinkTimer > playerPathShrinkSpeed)
		{
			if (changePathY == true)
			{
			playersPath[currentPlayersPath]->setY(playersPath[currentPlayersPath]->getY() + 1);
			}
			playersPath[currentPlayersPath]->setW(playersPath[currentPlayersPath]->getW() - 1);
			playersPath[currentPlayersPath]->setH(playersPath[currentPlayersPath]->getH() - 1);
			if (playerAlive) { playersPath[currentPlayersPath]->setX(playersPath[currentPlayersPath]->getX() - 4); }
			playersPath[currentPlayersPath]->setAplpha(playersPath[currentPlayersPath]->getAlpha() - 10);
		}
		currentPlayersPath++;
	}
	currentPlayersPath = 0;
	if (changePathY == true) { changePathY = false; }
	else { changePathY = true; }
	if (playerPathShrinkTimer > playerPathShrinkSpeed) { playerPathShrinkTimer = 0; }
	playerPathShrinkTimer++;
}

void CPlayer::drawPlayer()
{
	if (playerAlive){ player->drawReg(0, 0);  }
	else
	{
		
		if (playerDeathImageFrameTimer > playerDeathImageFrameRate)
		{
			playerDeathImage->setX(player->getX());
			playerDeathImage->setY(player->getY());
			playerDeathImage->setFrame(playerDeathImage->getFrame() + 1);
			playerDeathImageFrameTimer = 0;
		}
		playerDeathImageFrameTimer++;
		playerDeathImage->drawReg(0, 0);
	}
	
}

void CPlayer::movePlayer()
{
	switch (sdl_Setup->GetMainEvent()->type)
	{
	case SDL_KEYDOWN:

		switch (sdl_Setup->GetMainEvent()->key.keysym.sym)
		{
		case SDLK_SPACE:
				playerSpeed = -playerSpeed;
				playerMoving = true;
			break;
		}
		break;

	default:
		break;
	}
	if (playerMoving == false)
	{
		playerSpeed = -playerSpeed;
		while (currentPlayersPath < playersPathAmount)
		{
			playersPath[currentPlayersPath]->drawReg(0, 0);

			if (playerPathShrinkTimer > playerPathShrinkSpeed)
			{
				playersPath[currentPlayersPath]->setX(playersPath[currentPlayersPath]->getX() - 4);
			}
			currentPlayersPath++;
		}
		currentPlayersPath = 0;
	}
	player->setY(player->getY() + playerSpeed);
	if (player->getY() < 0)
	{
		player->setY(0);
		while (currentPlayersPath < playersPathAmount)
		{
			playersPath[currentPlayersPath]->drawReg(0, 0);

			if (playerPathShrinkTimer > playerPathShrinkSpeed)
			{
				playersPath[currentPlayersPath]->setX(playersPath[currentPlayersPath]->getX() - 4);
			}
			currentPlayersPath++;
		}
		currentPlayersPath = 0;
	}
	if (player->getY() + player->getH() > sdl_Setup->getScreenHeight)
	{
		player->setY(sdl_Setup->getScreenHeight - player->getH());
		while (currentPlayersPath < playersPathAmount)
		{
			playersPath[currentPlayersPath]->drawReg(0, 0);

			if (playerPathShrinkTimer > playerPathShrinkSpeed)
			{
				playersPath[currentPlayersPath]->setX(playersPath[currentPlayersPath]->getX() - 4);
			}
			currentPlayersPath++;
		}
		currentPlayersPath = 0;
	}
}

bool CPlayer::checkCollision(CWalls* walls)
{
	wallCollisions->resetCollisionTruth();

	while (currentWall < wallsAmount)
	{
		while (currentWallPart < 2)
		{
			wallCollisions->checkCollisionState(player->getRect(), walls->wall[currentWall][currentWallPart]->getRect());
			currentWallPart++;
		}
		currentWallPart = 0;
		currentWall++;
	}
	currentWall = 0;

	return wallCollisions->collisionState[4];
}

bool CPlayer::checkForNewZone(CWalls* walls)
{
	while (currentWall < wallsAmount)
	{
		while (currentWallPart < 2)
		{
			if (walls->wall[currentWall][currentWallPart]->getX() == player->getX() + player->getW()) { return true; }
			currentWallPart++;
		}
		currentWallPart = 0;
		currentWall++;
	}
	currentWall = 0;

	return false;
}

bool CPlayer::getPlayerPlaying()
{
	return playerMoving;
}

void CPlayer::playerDie()
{
	playerAlive = false;
}

bool CPlayer::getPlayerLife()
{
	return playerAlive;
}

void CPlayer::resetPlayer()
{
	player->setY(sdl_Setup->getScreenHeight / 2);
	playerMoving = false;
	playerAlive = true;
	playerDeathImage->setFrame(0);

	while (currentPlayersPath < playersPathAmount)
	{
		playersPath[currentPlayersPath]->setW(NULL);
		playersPath[currentPlayersPath]->setH(NULL);
		currentPlayersPath++;
	}
	currentPlayersPath = 0;
}