#include "stdafx.h"
#include "InputManager.h"
#include "CubeInputStates.h"
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
        g_MessageBus = Message(E_Engine_SystemQuit);
        UpdateEvent();
        break;
    case SDL_KEYDOWN:
        g_MessageBus = Message(E_Scene_KeyEvent, std::pair<Sint8, Uint8>(event.key.keysym.sym, EKeyDown));
        UpdateEvent();
        break;
    case SDL_KEYUP:
        g_MessageBus = Message(E_Scene_KeyEvent, std::pair<Sint8, Uint8>(event.key.keysym.sym, EKeyUp));
        UpdateEvent();
        break;
    case SDL_MOUSEMOTION:
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
    {
        Sint32 x=0, y=0;
        SDL_GetMouseState(&x, &y);
        
        auto handleMouseClick = [=](Sint32 x, Sint32 y, bool isDown) {
            if (isDown) {
                if (SDL_BUTTON(SDL_BUTTON_LEFT)) {
                    g_MessageBus = Message(E_Scene_MouseEvent, std::make_tuple((Uint8)ELeftMouseButtonDown, x, y));
                }
                if (SDL_BUTTON(SDL_BUTTON_RIGHT)) {
                    g_MessageBus = Message(E_Scene_MouseEvent, std::make_tuple((Uint8)ERightMouseButtonDown, x, y));
                }
                if (SDL_BUTTON(SDL_BUTTON_MIDDLE)) {
                    g_MessageBus = Message(E_Scene_MouseEvent, std::make_tuple((Uint8)EMiddleMouseButtonDown, x, y));
                }
            }
            else {
                if (SDL_BUTTON(SDL_BUTTON_LEFT)) {
                    g_MessageBus = Message(E_Scene_MouseEvent, std::make_tuple((Uint8)ELeftMouseButtonUp, x, y));
                }
                if (SDL_BUTTON(SDL_BUTTON_RIGHT)) {
                    g_MessageBus = Message(E_Scene_MouseEvent, std::make_tuple((Uint8)ERightMouseButtonUp, x, y));
                }
                if (SDL_BUTTON(SDL_BUTTON_MIDDLE)) {
                    g_MessageBus = Message(E_Scene_MouseEvent, std::make_tuple((Uint8)EMiddleMouseButtonUp, x, y));
                }

            }
            UpdateEvent();

        };
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            handleMouseClick(x, y, true);
        }
        if (event.type == SDL_MOUSEBUTTONUP) {
            handleMouseClick(x, y, false);
        }
        
        
    }
        break;
    case SDL_MOUSEWHEEL:
        break;
    default:
        break;
    }
}

void InputManager::UpdateEvent()
{
    Send(g_MessageBus);
}

void InputManager::OnNotify(Message message)
{
    if (message.GetEventType() == E_Input_RequestPoll) {
        HandleEvent();
    }
}