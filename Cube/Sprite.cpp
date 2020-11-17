#include "stdafx.h"
#include "Sprite.h"
#include "Pixel.h"


Sprite::Sprite()
{
	v_PixelData.clear();
	n_SpriteWidth = 0;
	n_SpriteHeight = 0;
}

Sprite::Sprite(std::string imageFile)
{
	LoadFromFile(imageFile);
}

Sprite::Sprite(size_t width, size_t height)
{
	if (v_PixelData.size())
	{
		v_PixelData.clear();
	}
	n_SpriteWidth = width;
	n_SpriteHeight = height;
	for (size_t i = 0; i < width * height; i++)
	{
		v_PixelData.push_back(Pixel());
	}
}

Sprite::~Sprite()
{
	if (v_PixelData.size())
	{
		v_PixelData.clear();
	}
}

void Sprite::LoadFromFile(std::string imageFile)
{
	
}

Pixel* Sprite::GetData()
{
	return v_PixelData.data();
}

Pixel Sprite::GetPixel(size_t x, size_t y)
{
	if (x >= 0 && x < n_SpriteWidth && y >= 0 && y < n_SpriteHeight)
	{
		return v_PixelData.at((y * n_SpriteWidth + x));
	}
	return Pixel(0, 0, 0, 0);
}

void Sprite::SetPixel(size_t x, size_t y, Pixel p)
{
	if (x >= 0 && x < n_SpriteWidth && y >= 0 && y < n_SpriteHeight)
	{
		v_PixelData[(y * n_SpriteWidth + x)] = p;
	}
}