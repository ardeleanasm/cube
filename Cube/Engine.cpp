#include "stdafx.h"
#include "Engine.h"
#include "MessageBus.h"
#include "ErrorManager.h"
#include "WindowManager.h"
#include "RenderManager.h"
Engine::Engine(std::string gameTitle)
{
    s_GameTitle = gameTitle;
}

Engine::~Engine()
{
}

void Engine::Start()
{
    /*Initialize Memory*/

    /*Initialize comm buss*/
    p_MessageBus = std::make_shared<MessageBus>();

    /*Register Error Manager*/
    p_ErrorManager = std::make_unique<ErrorManager>();
    p_ErrorManager->Register(p_MessageBus.get());

    /*Register Window Manager*/
    p_WindowManager = std::make_unique<WindowManager>();
    p_WindowManager->Register(p_MessageBus.get());
    p_WindowManager->Init(s_GameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    
    /*Register Renderer */
    p_RenderManager = std::make_unique<RenderManager>();
    p_RenderManager->Register(p_MessageBus.get());
    p_RenderManager->Init(p_WindowManager->GetWindowObject());
    this->Register(p_MessageBus.get());
    b_IsRunning = true;
}

void Engine::Run()
{
    while (b_IsRunning) {
        HandleEvents();
        Update();
        p_MessageBus->Notify();
        /*Input->readInput();
        isRunning = GameLogic->doLogic();
        Camera->update();
        World->update();
        GUI->update();
        AI->update();
        Audio->play();
        Render->draw();*/

    }
}

void Engine::Stop()
{
    SDL_Quit();
}

void Engine::Update()
{
    Message render("render");
    Send(render);
}

void Engine::OnNotify(Message message)
{
}

void Engine::HandleEvents()
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
