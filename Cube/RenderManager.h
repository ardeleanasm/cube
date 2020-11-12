#pragma once
#include "BusNode.h"
class RenderManager:public BusNode
{
public:
	RenderManager();
	virtual ~RenderManager();
	
	void Init(SDL_Window* window);
	void Update();
	
protected:
	void Render();
	void OnNotify(Message message);
private:
	SDL_Renderer* p_Renderer = nullptr;
	
};