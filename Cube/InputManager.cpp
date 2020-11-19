#include "stdafx.h"
#include "Component.h"
#include "InputManager.h"

InputManager::InputManager()
{
    
}

InputManager::~InputManager()
{
}



void InputManager::HandleEvent()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        Invoke(EV_CUBE_QUIT,0u);
        break;
    case SDL_KEYDOWN:
    case SDL_KEYUP:
    case SDL_MOUSEMOTION:
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
    case SDL_MOUSEWHEEL:
        break;
    default:
        break;
    }
}

