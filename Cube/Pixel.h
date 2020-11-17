#pragma once
#include "stdafx.h"
class Pixel
{
public:
	Pixel()
	{
		u_PixelColour.red = 0u;
		u_PixelColour.green = 0u;
		u_PixelColour.blue = 0u;
		u_PixelColour.alpha = 255u;
	}
	Pixel(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255)
	{
		u_PixelColour.red = red;
		u_PixelColour.green = green;
		u_PixelColour.blue = blue;
		u_PixelColour.alpha = alpha;
	}
	Pixel(Uint32 colour)
	{
		u_PixelColour.value = colour;
	}
	~Pixel()
	{

	}
	inline Uint8 GetChannelRed() { return u_PixelColour.red; }
	inline Uint8 GetChannelGreen() { return u_PixelColour.green; }
	inline Uint8 GetChannelBlue() { return u_PixelColour.blue; }
	inline Uint8 GetChannelAlpha() { return u_PixelColour.alpha; }
	inline Uint32 GetPixelColour() { return u_PixelColour.value; }
	inline bool operator==(const Pixel& p) const {
		return u_PixelColour.value == p.u_PixelColour.value;
	}
	inline bool operator!=(const Pixel& p) const {
		return u_PixelColour.value != p.u_PixelColour.value;
	}
	enum Mode { NORMAL, MASK, ALPHA };
protected:
private:
	union
	{
		Uint32 value;
		struct
		{
			Uint8 red;
			Uint8 green;
			Uint8 blue;
			Uint8 alpha;
		};
	}u_PixelColour;
};
