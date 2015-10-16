#pragma once
#include "SDL_setup.h"
#include "sprites.h"

class CTextAndOptions
{
public:
	CTextAndOptions(CSDL_setup* csdl_setup);
	~CTextAndOptions();
	void displayStartInstruction();
	void displayDeadScreen();

	//buttons
	Csprites* restartButton;
	Csprites* menuButton;
private:
	//start instruction
	int startInstructionW;
	int startInstructionH;
	Csprites* startInstruction;
	bool startInstructionDisapearing;

	//score
	int scoreTextW;
	int scoreTextH;
	Csprites* scoreText;
	int highScoreTextW;
	int highScoreTextH;
	Csprites* highScoreText;

	//buttons
	int restartButtonW;
	int restartButtonH;

	int menuButtonW;
	int menuButtomH;


	CSDL_setup* sdl_Setup;
};