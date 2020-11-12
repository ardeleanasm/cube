#include "stdafx.h"
#include "RenderManager.h"


RenderManager::RenderManager()
{

}

RenderManager::~RenderManager()
{
	if (p_Renderer != nullptr) {
		SDL_DestroyRenderer(p_Renderer);

	}
}

void RenderManager::Init(SDL_Window* window)
{
	if (window != nullptr) {
		p_Renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(p_Renderer, 0, 0, 0, 0);
	}
}

void RenderManager::Update()
{
}

void RenderManager::OnNotify(Message message)
{
	if (message.GetEvent().compare("render") == 0) {
		Render();

	}
}

void RenderManager::Render()
{
	SDL_RenderClear(p_Renderer);
	//Draw stuff
	SDL_RenderPresent(p_Renderer);
}



