#pragma once

#include "Component.h"
#include "Sprite.h"
class RenderManager:public Component
{
public:
	RenderManager(const size_t windowWidth, const size_t windowHeight);
	virtual ~RenderManager();
	
	void Init(SDL_Window* window);
	void Prepare(Sprite* sprite);
	void Render();
	
protected:
	
private:
	SDL_Renderer* p_Renderer = nullptr;
	SDL_Texture* p_Texture = nullptr;
	size_t n_WindowWidth;
	size_t n_WindowHeight;
	Sprite* p_Sprite = nullptr;
};