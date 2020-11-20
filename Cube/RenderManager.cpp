#include "stdafx.h"
#include "RenderManager.h"


RenderManager::RenderManager(const size_t windowWidth, const size_t windowHeight) :n_WindowWidth(windowWidth), n_WindowHeight(windowHeight)
{
	
}

RenderManager::~RenderManager()
{
	if (p_Renderer != nullptr) {
		SDL_DestroyRenderer(p_Renderer);

	}
	if (p_Texture != nullptr) {
		SDL_DestroyTexture(p_Texture);
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
		p_Renderer = SDL_CreateRenderer(window, rendererIndex, SDL_RENDERER_ACCELERATED);

		if (p_Renderer != nullptr) {
			p_Texture = SDL_CreateTexture(p_Renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, n_WindowWidth, n_WindowHeight);
			//TODO: Change access to streaming

		}

	}

	

	
}

void RenderManager::Prepare(Sprite* sprite)
{
	p_Sprite = sprite;
}


void RenderManager::Render()
{
	SDL_RenderClear(p_Renderer);
	
	SDL_UpdateTexture(p_Texture, NULL, p_Sprite->GetSurface()->pixels, p_Sprite->GetSurface()->pitch);

	SDL_RenderCopy(p_Renderer, p_Texture, NULL, NULL);

	SDL_RenderPresent(p_Renderer);
	
}



