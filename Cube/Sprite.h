#pragma once
#include "stdafx.h"
class Pixel;
class Sprite
{
public:
	Sprite();
	Sprite(std::string imageFile);
	Sprite(size_t width, size_t height);
	~Sprite();

	void LoadFromFile(std::string imageFile);
	inline size_t GetSpriteWidth() { return n_SpriteWidth; }
	inline size_t GetSpriteHeight() { return n_SpriteHeight; }
	Pixel* GetData();
	Pixel GetPixel(size_t x, size_t y);
	void SetPixel(size_t x, size_t y, Pixel p);
protected:
private:
	size_t n_SpriteWidth;
	size_t n_SpriteHeight;
	std::vector<Pixel> v_PixelData;
};


