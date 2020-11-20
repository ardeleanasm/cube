#pragma once
#include "stdafx.h"

struct Pixel
{
	
	inline Pixel() {
		value.rgba = 0xFFFFFFFFu;
	}
	inline Pixel(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha=0xFFu)
	{
		value.red = red;
		value.green = green;
		value.blue = blue;
		value.alpha = alpha;
	}
	inline Pixel(Uint32 p)
	{
		value.rgba = p;
	}
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

static const Pixel GREY(192u, 192u, 192u), DARK_GREY(128, 128, 128), VERY_DARK_GREY(64, 64, 64),
RED(255, 0, 0), DARK_RED(128, 0, 0), VERY_DARK_RED(64, 0, 0),
YELLOW(255, 255, 0), DARK_YELLOW(128, 128, 0), VERY_DARK_YELLOW(64, 64, 0),
GREEN(0, 255, 0), DARK_GREEN(0, 128, 0), VERY_DARK_GREEN(0, 64, 0),
CYAN(0, 255, 255), DARK_CYAN(0, 128, 128), VERY_DARK_CYAN(0, 64, 64),
BLUE(0, 0, 255), DARK_BLUE(0, 0, 128), VERY_DARK_BLUE(0, 0, 64),
MAGENTA(255, 0, 255), DARK_MAGENTA(128, 0, 128), VERY_DARK_MAGENTA(64, 0, 64),
WHITE(255, 255, 255), BLACK(0, 0, 0), BLANK(0, 0, 0, 0);

class Sprite
{
public:
	Sprite();
	Sprite(std::string imageFile);
	Sprite(Sint32 width, Sint32 height);
	~Sprite();

	void LoadFromFile(std::string imageFile);
	inline Sint32 GetSpriteWidth() { return n_SpriteWidth; }
	inline Sint32 GetSpriteHeight() { return n_SpriteHeight; }
	inline SDL_Surface* GetSurface() { return p_Surface; }
	inline void SetSurface(SDL_Surface* surface) { p_Surface = surface; }
	void SetPixel(Sint32 x, Sint32 y, Pixel value);
	Pixel GetPixel(Sint32 x, Sint32 y);
	enum Flip : Uint8 {FLIP_NONE, FLIP_HORIZONTAL,FLIP_VERTICAL};
protected:
private:
	Sint32 n_SpriteWidth;
	Sint32 n_SpriteHeight;
	SDL_Surface* p_Surface;
	
};


