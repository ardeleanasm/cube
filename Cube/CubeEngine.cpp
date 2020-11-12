#include "stdafx.h"
#include "CubeEngine.h"

CubeEngine::CubeEngine()
{
	
}

CubeEngine::~CubeEngine()
{
}

void CubeEngine::CubeInit(std::string title, int posX, int posY, int width, int height, bool fullScreen)
{
	Uint32 flags = 0ul;
	if (fullScreen) {
		flags |= SDL_WINDOW_FULLSCREEN;
	}
	

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		//Ooops, an error
		b_IsRunning = false;
	}
	else {
		p_Window = SDL_CreateWindow(title.c_str(), posX, posY, width, height, flags);
		if (p_Window == nullptr) {
			//Ooops, an error
		}
		p_Renderer = SDL_CreateRenderer(p_Window, -1, 0);
		if (p_Renderer == nullptr) {
			//Ooops, an error
		}
		SDL_SetRenderDrawColor(p_Renderer, 0, 0, 0, 0);
		b_IsRunning = true;
	}
}

void CubeEngine::CubeRun()
{
	while (b_IsRunning) {
		HandleEvent();
		Update();
		Render();
	}
	Clean();
}

void CubeEngine::HandleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		b_IsRunning = false;
		break;
	default:
		break;
	}
}

void CubeEngine::Update()
{

}

void CubeEngine::Render()
{
	SDL_RenderClear(p_Renderer);
	//Draw stuff
	SDL_RenderPresent(p_Renderer);
}

void CubeEngine::Clean()
{

	SDL_DestroyRenderer(p_Renderer);
	SDL_DestroyWindow(p_Window);
	SDL_Quit();
}
