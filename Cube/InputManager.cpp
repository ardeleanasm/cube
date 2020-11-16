#include "stdafx.h"
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
        g_MessageBus = Message(E_Engine_SystemQuit);
        UpdateEvent();
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
