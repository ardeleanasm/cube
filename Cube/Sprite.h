#pragma once
#include "stdafx.h"

struct Pixel
{
	inline bool operator==(const Pixel& p) const {
		return value.rgba == p.value.rgba;
	}
	inline bool operator!=(const Pixel& p) const {
		return value.rgba != p.value.rgba;
	}
	union
	{
		Uint32 rgba;
		struct
		{
			Uint8 red;
			Uint8 green;
			Uint8 blue;
			Uint8 alpha;
		};
	}value;
	
};


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
	inline SDL_Surface* GetSurface() { return p_Surface; }
	void SetPixel(size_t x, size_t y, Pixel value);
protected:
private:
	size_t n_SpriteWidth;
	size_t n_SpriteHeight;
	SDL_Surface* p_Surface;
	
};


