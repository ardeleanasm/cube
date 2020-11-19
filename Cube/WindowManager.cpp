#include "stdafx.h"
#include "CubeEngineErrors.h"
#include "WindowManager.h"

WindowManager::WindowManager()
{

	
}

WindowManager::~WindowManager()
{
	if (p_Window != nullptr) {
		SDL_DestroyWindow(p_Window);
	}
}

void WindowManager::Init(std::string title, int posX, int posY, int width, int height, bool fullScreen)
{
	Uint32 flags = 0ul;
	if (fullScreen) {
		flags |= SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		g_ErrorEventMessage = ESDLInit;
		
	}
	else {
		p_Window = SDL_CreateWindow(title.c_str(), posX, posY, width, height, flags);
		if (p_Window == nullptr) {
			g_ErrorEventMessage =EWindowInit;
		
		}
		
	}
}





