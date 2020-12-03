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

Sprite::Sprite(Sint32 width, Sint32 height)
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



void Sprite::SetPixel(Sint32 x, Sint32 y, Pixel p)
{
	if (x >= 0 && x < n_SpriteWidth && y >= 0 && y < n_SpriteHeight)
	{
		//Convert the pixels to 32 bit
		Uint32* pixels = (Uint32*)p_Surface->pixels;

		//Set the pixel
		pixels[(y * p_Surface->w) + x] = p.value.rgba;
		
	}
}

Pixel Sprite::GetPixel(Sint32 x, Sint32 y)
{
	if (x >= 0 && x < n_SpriteWidth && y >= 0 && y < n_SpriteHeight)
	{
		
		//Convert the pixels to 32 bit
		Uint32* pixels = (Uint32*)p_Surface->pixels;

		//Get the requested pixel
		return pixels[(y * p_Surface->w) + x];
	}
	return WHITE;
}
