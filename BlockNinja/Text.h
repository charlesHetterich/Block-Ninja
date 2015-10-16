#pragma once
#include "SDL_setup.h"
#include "sprites.h"

class CText
{
public:
	CText(CSDL_setup* csdl_setup);
	~CText();
	void createText(int textSize, std::string text, int x, int y, int w, int h);

private:

	SDL_Texture *texture;
	SDL_Surface *surf;

	SDL_Rect rect;
	Csprites* image;
	CSDL_setup* sdl_setup;

	SDL_Color Color3;
	TTF_Font *font;
	//text = TTF_RenderText_Solid(font, "hello world", Color3)
};

