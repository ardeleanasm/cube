#pragma once
#include "BusNode.h"
#include "Message.h"
#include "RenderManager.h"
#include "Sprite.h"
#include "vector2d.h"
class SceneManager : public BusNode
{
public:
	SceneManager();
	void Init(const Sint32 windowWidth, const Sint32 windowHeight, RenderManager *renderer);
	virtual ~SceneManager();
	void UpdateEvent();
protected:
	virtual void DrawScene() {
		
	}

#pragma region Draw Routines
	/**
	 * DrawCircle, FillCircle, DrawSprite and their implementation are inspired from olcPixelGameEngine
	 * created by Javidx9 (OneLoneCoder) and published on 
	 * https://github.com/OneLoneCoder/olcPixelGameEngine
	 */
	void Draw(Sint32 x, Sint32 y, Uint8 r,Uint8 g,Uint8 b,Uint8 a);
	void Background(Pixel p = WHITE);
	void DrawLine(Sint32 x1, Sint32 y1, Sint32 x2, Sint32 y2, Pixel p=WHITE, Uint32 pattern = 0xFFFFFFFF);
	void DrawLine(const Vector2Di_T& pos1, const Vector2Di_T& pos2, Pixel p = WHITE, Uint32 pattern = 0xFFFFFFFF);
	
	// Draws a circle located at (x,y) with radius
	void DrawCircle(Sint32 x, Sint32 y, Sint32 radius, Pixel p = WHITE, uint8_t mask = 0xFF);
	
	void DrawCircle(const Vector2Di_T& pos, Sint32 radius, Pixel p = WHITE, uint8_t mask = 0xFF);

	// Fills a circle located at (x,y) with radius
	void FillCircle(Sint32 x, Sint32 y, Sint32 radius, Pixel p = WHITE);
	void FillCircle(const Vector2Di_T& pos, Sint32 radius, Pixel p = WHITE);
	
	// Draws a rectangle at (x,y) to (x+w,y+h)
	void DrawRect(Sint32 x, Sint32 y, Sint32 w, Sint32 h, Pixel p = WHITE);
	void DrawRect(const Vector2Di_T& pos, const Vector2Di_T& size, Pixel p = WHITE);
	
	// Fills a rectangle at (x,y) to (x+w,y+h)
	void FillRect(Sint32 x, Sint32 y, Sint32 w, Sint32 h, Pixel p = WHITE);
	void FillRect(const Vector2Di_T& pos, const Vector2Di_T& size, Pixel p = WHITE);
		
	// Draws an entire sprite at well location (x,y)
	void DrawSprite(Sint32 x, Sint32 y, Sprite* sprite, Uint32 scale = 1, Uint8 flip = 0u);
	void DrawSprite(const Vector2Di_T& pos, Sprite* sprite, Uint32 scale = 1, Uint8 flip = 0u);

#pragma endregion


	void OnNotify(Message message);
	Sint32 n_WindowWidth;
	Sint32 n_WindowHeight;
private:
	RenderManager* p_Renderer = nullptr;
	
	Sprite* p_DrawTarget = nullptr;
	Message g_MessageBus;

};
