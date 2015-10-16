#pragma once;
class Csprites
{
public:
	Csprites(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int imageW, int imageH);
	~Csprites();

	void drawReg(int x, int y);
	void drawMotionBlur(int x, int y, int blurLevel);
	void setAplpha(int solidity);
	int getAlpha();
	void setAngle(int angle);
	std::string getImage();
	void setImage(std::string FilePath);

	SDL_Rect getRect();

	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getW();
	void setW(int w);
	int getH();
	void setH(int h);

	int getFrame();
	void setFrame(int newFrame);
	int getFrameRow();
	void setFrameRow(int newFrameRow);
	
private:
	int alpha;
	int imageWidth;
	int imageHeight;
	int frame;
	int frameRow;

	std::string filePath;
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Rect crop;
	SDL_Renderer* renderer;
};