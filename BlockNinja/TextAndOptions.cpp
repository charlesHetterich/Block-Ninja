#include "stdafx.h"
#include "TextAndOptions.h"


CTextAndOptions::CTextAndOptions(CSDL_setup* csdl_setup)
{
	sdl_Setup = csdl_setup;

	//starting instruction text
	startInstructionW = (50 * 11) / 2;
	startInstructionH = (50 * 2.5) / 2;
	startInstruction = new Csprites(sdl_Setup->GetRenderer(), "images/startinstruction.png", (sdl_Setup->getScreenWidth / 2) - (startInstructionW / 2), ((sdl_Setup->getScreenHeight / 2) - (startInstructionH / 2)) - 100, startInstructionW, startInstructionH, 176, 42);
	startInstruction->setAplpha(0);

	//score
	scoreTextW = (50 * 6)/4;
	scoreTextH = (50)/4;
	scoreText = new Csprites(sdl_Setup->GetRenderer(), "images/score_text.png", (sdl_Setup->getScreenWidth / 2) - (scoreTextW/2), 300, scoreTextW, scoreTextH, 96, 18);
	highScoreTextW = (50 * 11)/4;
	highScoreTextH = (50)/4;
	highScoreText = new Csprites(sdl_Setup->GetRenderer(), "images/highscore_text.png", (sdl_Setup->getScreenWidth / 2) - (highScoreTextW/2), 330, highScoreTextW, highScoreTextH, 176, 18);

	//buttons
	restartButtonW = (50 * 9)/3;
	restartButtonH = (50 * 3)/3;
	restartButton = new Csprites(sdl_Setup->GetRenderer(), "images/deadButtons.png", ((sdl_Setup->getScreenWidth / 2) - (restartButtonW / 2)) - 110, 400, restartButtonW, restartButtonH, 144, 48);
	menuButtonW = (50 * 9)/3;
	menuButtomH = (50 * 3)/3;
	menuButton = new Csprites(sdl_Setup->GetRenderer(), "images/deadButtons.png", ((sdl_Setup->getScreenWidth / 2) - (restartButtonW / 2)) + 110, 400, restartButtonW, restartButtonH, 144, 48);
	menuButton->setFrameRow(1);
}


CTextAndOptions::~CTextAndOptions()
{
	delete restartButton;
	delete menuButton;
	delete scoreText;
	delete highScoreText;
	delete startInstruction;
}

void CTextAndOptions::displayStartInstruction()
{
	startInstruction->drawReg(0, 0);
	if (startInstructionDisapearing) { startInstruction->setAplpha(startInstruction->getAlpha() - 1); }
	if (!startInstructionDisapearing) { startInstruction->setAplpha(startInstruction->getAlpha() + 1); }
	if (startInstruction->getAlpha() == 0) { startInstructionDisapearing = false; }
	if (startInstruction->getAlpha() == 255) { startInstructionDisapearing = true; }
}

void CTextAndOptions::displayDeadScreen()
{
	scoreText->drawReg(0, 0);
	highScoreText->drawReg(0, 0);
	restartButton->drawReg(0, 0);
	menuButton->drawReg(0, 0);
}