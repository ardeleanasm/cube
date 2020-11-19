#include "stdafx.h"
#include "Sprite.h"



Sprite::Sprite()
{
	
	n_SpriteWidth = 0;
	n_SpriteHeight = 0;
}

Sprite::Sprite(std::string imageFile)
{
	LoadFromFile(imageFile);
}

Sprite::Sprite(size_t width, size_t height)
{
	
	n_SpriteWidth = width;
	n_SpriteHeight = height;
	p_Surface = SDL_CreateRGBSurface(0, n_SpriteWidth, n_SpriteHeight, 32, 0, 0, 0, 0);

	
}

Sprite::~Sprite()
{
	SDL_FreeSurface(p_Surface);
}

void Sprite::LoadFromFile(std::string imageFile)
{
	
}



void Sprite::SetPixel(size_t x, size_t y, Pixel p)
{
	if (x >= 0 && x < n_SpriteWidth && y >= 0 && y < n_SpriteHeight)
	{
		//Convert the pixels to 32 bit
		Uint32* pixels = (Uint32*)p_Surface->pixels;

		//Set the pixel
		pixels[(y * p_Surface->w) + x] = p.value.rgba;
		
	}
}