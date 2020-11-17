#include "stdafx.h"
#include "Engine.h"
#include "MessageType.h"
#include "MessageBus.h"
#include "Message.h"
#include "ErrorManager.h"
#include "WindowManager.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
Engine::Engine(std::string gameTitle)
{
    s_GameTitle = gameTitle;
}

Engine::~Engine()
{
}

void Engine::Start(SceneManager* arg)
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
    p_WindowManager->Init(s_GameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, n_WindowWidth, n_WindowHeight, false);
    
    /*Register Input manager*/
    p_InputManager = std::make_unique<InputManager>();
    p_InputManager->Register(p_MessageBus.get());
    

    /*Register Renderer */
    p_RenderManager = std::make_unique<RenderManager>(n_WindowWidth, n_WindowHeight);
    p_RenderManager->Register(p_MessageBus.get());
    p_RenderManager->Init(p_WindowManager->GetWindowObject());
    
    
    /*Register SceneManager*/
    p_SceneManager = std::unique_ptr<SceneManager>(arg);
    p_SceneManager->Register(p_MessageBus.get());
    p_SceneManager->Init(n_WindowWidth, n_WindowHeight);
    


    this->Register(p_MessageBus.get());
    b_IsRunning = true;

}

void Engine::Run()
{
    while (b_IsRunning) {
        /*Read Keys*/
        g_BusMessage = Message(E_Input_RequestPoll);
        UpdateEvent();
        /*Update Renderer*/
        g_BusMessage = Message(E_Renderer_Render);
        UpdateEvent();

        /*Update SceneManager*/
        g_BusMessage = Message(E_Scene_UserUpdate);
        UpdateEvent();
        /*Commit Transactions*/
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

void Engine::UpdateEvent()
{
    
    Send(g_BusMessage);
}

void Engine::OnNotify(Message message)
{
    if (message.GetEventType() == E_Engine_SystemQuit) {
        b_IsRunning = false;
    }
}


