#pragma once
#include "BusNode.h"
#include "Sprite.h"
class RenderManager :public BusNode
{
public:
	RenderManager(const Sint32 windowWidth, const Sint32 windowHeight);
	virtual ~RenderManager();
	
	void Init(SDL_Window* window);
	void Prepare(Sprite* sprite);
	void UpdateEvent();
protected:
	void Render();
	void OnNotify(Message message);
private:
	SDL_Renderer* p_Renderer = nullptr;
	SDL_Texture* p_Texture = nullptr;
	Sint32 n_WindowWidth;
	Sint32 n_WindowHeight;
	Sprite* p_Sprite = nullptr;
};


