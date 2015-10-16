#include "stdafx.h"
#include "sprites.h"

Csprites::Csprites(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int imageW, int imageH)
{
	//FILE* x = FilePath;
	renderer = passed_renderer;
	filePath = FilePath;
	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());

	if (image == NULL)
	{
		std::cout << "Couldn't load " << FilePath.c_str() << std::endl;
	}
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	imageWidth = imageW;
	imageHeight = imageH;

	crop.x = 0;
	crop.y = 0;
	crop.w = imageWidth;
	crop.h = imageHeight;

	alpha = 255;
}


Csprites::~Csprites()
{
	SDL_DestroyTexture(image);
}

void Csprites::drawReg(int x, int y)
{
	int OGRectX = rect.x;
	int OGRectY = rect.y;
	rect.x += x;
	rect.y += y;

	SDL_RenderCopy(renderer, image, &crop, &rect);

	rect.x = OGRectX;
	rect.y = OGRectY;
}

void Csprites::drawMotionBlur(int x, int y, int blurLevel)
{
	int OGRectX = rect.x;
	int OGRectY = rect.y;
	rect.x += x;
	rect.y += y;

	SDL_RenderCopy(renderer, image, NULL, &rect);

	rect.x = OGRectX;
	rect.y = OGRectY;
}

void Csprites::setAplpha(int solidity)
{
	alpha = solidity;
	SDL_SetTextureAlphaMod(image, alpha);
	
}

int Csprites::getAlpha()
{
	return alpha;
}

void Csprites::setAngle(int angle)
{

}

int Csprites::getX()
{
	return rect.x;
}

void Csprites::setX(int x)
{
	rect.x = x;
}

int Csprites::getY()
{
	return rect.y;
}

void Csprites::setY(int y)
{
	rect.y = y;
}

int Csprites::getW()
{
	return rect.w;
}

void Csprites::setW(int w)
{
	rect.w = w;
}

int Csprites::getH()
{
	return rect.h;
}

void Csprites::setH(int h)
{
	rect.h = h;
}

SDL_Rect Csprites::getRect()
{
	return rect;
}

std::string Csprites::getImage()
{
	return filePath;
	SDL_SetTextureAlphaMod(image, alpha);
}

void Csprites::setImage(std::string FilePath)
{
	filePath = FilePath;
	image = IMG_LoadTexture(renderer, filePath.c_str());
	
}

int Csprites::getFrame()
{
	return frame;
}

void Csprites::setFrame(int newFrame)
{
	frame = newFrame;
	crop.x = imageWidth*frame;
}

int Csprites::getFrameRow()
{
	return frameRow;
}

void Csprites::setFrameRow(int newFrameRow)
{
	frameRow = newFrameRow;
	crop.y = imageHeight*frameRow;
}
