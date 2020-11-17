#include "stdafx.h"
#include "RenderManager.h"
#include "MessageType.h"
#include "Pixel.h"

RenderManager::RenderManager(const size_t windowWidth, const size_t windowHeight) :n_WindowWidth(windowWidth), n_WindowHeight(windowHeight)
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
	int rendererIndex = -1;
	if (window != nullptr) {
		for (int i = 0; i < SDL_GetNumRenderDrivers(); ++i)
		{
			SDL_RendererInfo rendererInfo = {};
			SDL_GetRenderDriverInfo(i, &rendererInfo);
			if (rendererInfo.name != std::string(PREFERRED_RENDERER))
			{
			
				continue;
			}
			rendererIndex = i;
			break;
		}
		p_Renderer = SDL_CreateRenderer(window, rendererIndex, 0);
	}

	

	
}

void RenderManager::UpdateEvent()
{
}

void RenderManager::OnNotify(Message message)
{
	if (message.GetEventType() == E_Renderer_Render) {
		Render();

	}
	if (message.GetEventType() == E_Renderer_Scene) {
		p_Sprite = message.GetEventSpriteObj();
		
	}
}

void RenderManager::Render()
{
	SDL_RenderClear(p_Renderer);
	//Draw stuff
	if (p_Sprite != nullptr) {
		for (size_t i = 0; i < n_WindowWidth; i++) {
			for (size_t j = 0; j < n_WindowHeight; j++) {
				Pixel p = p_Sprite->GetPixel(i, j);
				SDL_SetRenderDrawColor(p_Renderer, p.GetChannelRed(), p.GetChannelGreen(), p.GetChannelBlue(), p.GetChannelAlpha());
				SDL_RenderDrawPoint(p_Renderer, i, j);
			}
		}
		
	}
	

	SDL_RenderPresent(p_Renderer);
}



