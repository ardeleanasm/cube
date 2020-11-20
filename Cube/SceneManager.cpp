#include "stdafx.h"
#include "SceneManager.h"
#include "Sprite.h"
SceneManager::SceneManager()
{

	
}

void SceneManager::Init(const Sint32 windowWidth, const Sint32 windowHeight, RenderManager* renderer)
{
	n_WindowWidth = windowWidth;
	n_WindowHeight = windowHeight;
	p_DrawTarget = new Sprite(n_WindowWidth, n_WindowHeight);
	p_Renderer = renderer;
}

SceneManager::~SceneManager()
{
}



void SceneManager::Draw(Sint32 x, Sint32 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	
	p_DrawTarget->SetPixel(x, y, Pixel(r,g,b,a));
		
}




void SceneManager::UpdateEvent()
{
	p_Renderer->Prepare(p_DrawTarget);
}

void SceneManager::OnNotify(Message message)
{
	if (message.GetEventType() == E_Scene_UserUpdate) {
		DrawScene();
	}

}

void SceneManager::Background(Pixel p)
{
	for (int x = 0; x < n_WindowWidth; x++) {
		for (int y = 0; y < n_WindowHeight; y++) {
			Draw(x, y, p.value.red, p.value.green, p.value.blue, p.value.alpha);

		}

	}
}


void SceneManager::DrawLine(Sint32 x1, Sint32 y1, Sint32 x2, Sint32 y2, Pixel p, Uint32 pattern )
{
	
	auto rol = [&](void) { pattern = (pattern << 1) | (pattern >> 31); return pattern & 1; };

	Sint32 dx, dy,dx1,dy1,px,py,xe,ye,i;
	dx = x2 - x1;
	dy = y2 - y1;
	dx1 = abs(dx);
	dy1 = abs(dy);
	Sint32 x, y;
	//straight vertical line
	if (dx == 0) {
		if (y2 < y1) {
			std::swap(y1, y2);
		}
		for (y = y1; y <= y2; y++) {
			if (rol())
				Draw(x1, y, p.value.red, p.value.green, p.value.blue, p.value.alpha);
		}
		return;
	}

	//straight horizontal line
	if (dy == 0) {
		if (x2 < x1) {
			std::swap(x1, x2);
		}
		for (x = x1; x <= x2; x++) {
			if (rol())
				Draw(x, y1, p.value.red, p.value.green, p.value.blue, p.value.alpha);
		}
		return;
	}

	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;

	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1; y = y1; xe = x2;
		}
		else
		{
			x = x2; y = y2; xe = x1;
		}

		if (rol()) Draw(x, y, p.value.red, p.value.green, p.value.blue, p.value.alpha);

		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
				px = px + 2 * dy1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) y = y + 1; else y = y - 1;
				px = px + 2 * (dy1 - dx1);
			}
			if (rol()) Draw(x, y, p.value.red, p.value.green, p.value.blue, p.value.alpha);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1; y = y1; ye = y2;
		}
		else
		{
			x = x2; y = y2; ye = y1;
		}

		if (rol()) Draw(x, y, p.value.red, p.value.green, p.value.blue, p.value.alpha);

		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
				py = py + 2 * dx1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) x = x + 1; else x = x - 1;
				py = py + 2 * (dx1 - dy1);
			}
			if (rol()) Draw(x, y, p.value.red, p.value.green, p.value.blue, p.value.alpha);
		}
	}
}

void SceneManager::DrawLine(const Vector2Di_T& pos1, const Vector2Di_T& pos2, Pixel p, Uint32 pattern)
{
	DrawLine(pos1.X(), pos1.Y(), pos2.X(), pos2.Y(), p, pattern);
}

void SceneManager::DrawCircle(Sint32 x, Sint32 y, Sint32 radius, Pixel p, uint8_t mask)
{
	if (
			radius < 0 || 
			x < -radius || y < -radius || 
			x - n_WindowWidth>radius || y - n_WindowHeight>radius
		)
		return;
	if (radius > 0) {
		Sint32 x0 = 0;
		Sint32 y0 = radius;
		Sint32 d = 3 - 2 * radius;

		while (y0 >= x0) // only formulate 1/8 of circle
		{
			// Draw even octants
			if (mask & 0x01) Draw(x + x0, y - y0, p.value.red, p.value.green, p.value.blue, p.value.alpha);// Q6 - upper right right
			if (mask & 0x04) Draw(x + y0, y + x0, p.value.red, p.value.green, p.value.blue, p.value.alpha);// Q4 - lower lower right
			if (mask & 0x10) Draw(x - x0, y + y0, p.value.red, p.value.green, p.value.blue, p.value.alpha);// Q2 - lower left left
			if (mask & 0x40) Draw(x - y0, y - x0, p.value.red, p.value.green, p.value.blue, p.value.alpha);// Q0 - upper upper left
			if (x0 != 0 && x0 != y0)
			{
				if (mask & 0x02) Draw(x + y0, y - x0, p.value.red, p.value.green, p.value.blue, p.value.alpha);// Q7 - upper upper right
				if (mask & 0x08) Draw(x + x0, y + y0, p.value.red, p.value.green, p.value.blue, p.value.alpha);// Q5 - lower right right
				if (mask & 0x20) Draw(x - y0, y + x0, p.value.red, p.value.green, p.value.blue, p.value.alpha);// Q3 - lower lower left
				if (mask & 0x80) Draw(x - x0, y - y0, p.value.red, p.value.green, p.value.blue, p.value.alpha);// Q1 - upper left left
			}

			if (d < 0)
				d += 4 * x0++ + 6;
			else
				d += 4 * (x0++ - y0--) + 10;
		}
	}
	else {
		Draw(x, y, p.value.red, p.value.green, p.value.blue, p.value.alpha);
	}
}

void SceneManager::DrawCircle(const Vector2Di_T& pos, Sint32 radius, Pixel p, uint8_t mask)
{
	DrawCircle(pos.X(), pos.Y(), radius, p, mask);
}

void SceneManager::FillCircle(Sint32 x, Sint32 y, Sint32 radius, Pixel p)
{
	if (
			radius < 0 || 
			x < -radius || y < -radius || 
			x - n_WindowWidth>radius || y - n_WindowHeight>radius
		)
		return;

	if (radius > 0)
	{
		Sint32 x0 = 0;
		Sint32 y0 = radius;
		Sint32 d = 3 - 2 * radius;

		auto drawline = [&](int sx, int ex, int y)
		{
			for (int x = sx; x <= ex; x++)
				Draw(x, y, p.value.red, p.value.green, p.value.blue, p.value.alpha);
		};

		while (y0 >= x0)
		{
			drawline(x - y0, x + y0, y - x0);
			if (x0 > 0)	drawline(x - y0, x + y0, y + x0);

			if (d < 0)
				d += 4 * x0++ + 6;
			else
			{
				if (x0 != y0)
				{
					drawline(x - x0, x + x0, y - y0);
					drawline(x - x0, x + x0, y + y0);
				}
				d += 4 * (x0++ - y0--) + 10;
			}
		}
	}
	else {
		Draw(x, y, p.value.red, p.value.green, p.value.blue, p.value.alpha);
	}
}

void SceneManager::FillCircle(const Vector2Di_T& pos, Sint32 radius, Pixel p)
{
	FillCircle(pos.X(), pos.Y(), radius, p);
}

void SceneManager::DrawRect(Sint32 x, Sint32 y, Sint32 w, Sint32 h, Pixel p)
{
	DrawLine(x, y, x + w, y, p);
	DrawLine(x + w, y, x + w, y + h, p);
	DrawLine(x + w, y + h, x, y + h, p);
	DrawLine(x, y + h, x, y, p);
}

void SceneManager::DrawRect(const Vector2Di_T& pos, const Vector2Di_T& size, Pixel p)
{
	DrawRect(pos.X(), pos.Y(), size.X(), size.Y(), p);
}

void SceneManager::FillRect(Sint32 x, Sint32 y, Sint32 w, Sint32 h, Pixel p)
{
	SDL_Rect rectangle = { x,y,w,h };
	SDL_Surface* surface = p_DrawTarget->GetSurface();
	SDL_FillRect(surface, &rectangle, p.value.rgba);
	p_DrawTarget->SetSurface(surface);
}

void SceneManager::FillRect(const Vector2Di_T& pos, const Vector2Di_T& size, Pixel p)
{
	FillRect(pos.X(), pos.Y(), size.X(), size.Y(), p);
}


void SceneManager::DrawSprite(Sint32 x, Sint32 y, Sprite* sprite, Uint32 scale, Uint8 flip)
{
	if (sprite == nullptr)
		return;

	Sint32 fxs = 0, fxm = 1, fx = 0;
	Sint32 fys = 0, fym = 1, fy = 0;
	if (flip & Sprite::Flip::FLIP_HORIZONTAL) { fxs = sprite->GetSpriteWidth() - 1; fxm = -1; }
	if (flip & Sprite::Flip::FLIP_VERTICAL) { fys = sprite->GetSpriteHeight() - 1; fym = -1; }

	if (scale > 1)
	{
		fx = fxs;
		for (Sint32 i = 0; i < sprite->GetSpriteWidth(); i++, fx += fxm)
		{
			fy = fys;
			for (Sint32 j = 0; j < sprite->GetSpriteHeight(); j++, fy += fym)
				for (Uint32 is = 0; is < scale; is++)
					for (Uint32 js = 0; js < scale; js++) {
						Pixel p = sprite->GetPixel(fx, fy);
						Draw(x + (i * scale) + is, y + (j * scale) + js, p.value.red, p.value.green, p.value.blue, p.value.alpha);
					}
		}
	}
	else
	{
		fx = fxs;
		for (Sint32 i = 0; i < sprite->GetSpriteWidth(); i++, fx += fxm)
		{
			fy = fys;
			for (Sint32 j = 0; j < sprite->GetSpriteHeight(); j++, fy += fym) {
				Pixel p = sprite->GetPixel(fx, fy);
				Draw(x + i, y + j, p.value.red, p.value.green, p.value.blue, p.value.alpha);
			}

		}
	}
	
}

void SceneManager::DrawSprite(const Vector2Di_T& pos, Sprite* sprite, Uint32 scale, Uint8 flip)
{
	DrawSprite(pos.X(), pos.Y(), sprite, scale, flip);
}


