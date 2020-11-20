#pragma once
#include "BusNode.h"
#include "Sprite.h"
class RenderManager :public BusNode
{
public:
	RenderManager(const size_t windowWidth, const size_t windowHeight);
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
	size_t n_WindowWidth;
	size_t n_WindowHeight;
	Sprite* p_Sprite = nullptr;
};


