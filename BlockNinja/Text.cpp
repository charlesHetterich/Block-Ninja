#include "stdafx.h"
#include "Text.h"


CText::CText(CSDL_setup* csdl_setup)
{
	font = nullptr;
	sdl_setup = csdl_setup;
	TTF_Init();
	rect.h = 100;
	rect.w = 200;
	rect.x = 20;
	rect.y = 20;
	Color3 = { 255, 255, 255 };
	font = TTF_OpenFont("fonts/RockoUltraFLF.ttf", 100);
}

CText::~CText()
{
	delete sdl_setup;
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	TTF_Quit();
}
void CText::createText(int textSize, std::string text, int x, int y, int w, int h)
{
	
	TTF_Init();
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	//open the font
	//Color3 = { 255, 255, 255 };
	//font = TTF_OpenFont(fontFile.c_str(), textSize);

	//render the message to an SDL_Surface, as that's what ttf_renderText_x returns
	surf = TTF_RenderText_Solid(font, text.c_str(), Color3);
	texture = SDL_CreateTextureFromSurface(sdl_setup->GetRenderer(), surf);

	SDL_RenderCopy(sdl_setup->GetRenderer(), texture, NULL, &rect);
		
	//Clean up unneeded stuff
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
}