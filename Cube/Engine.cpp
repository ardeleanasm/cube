#include "stdafx.h"
#include "Engine.h"
#include "CubeEvent.h"
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

    /*Register Error Manager*/
    p_ErrorManager = std::make_unique<ErrorManager>();

    /*Register Window Manager*/
    p_WindowManager = std::make_unique<WindowManager>();
    p_WindowManager->Init(s_GameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, n_WindowWidth, n_WindowHeight, false);
    p_WindowManager->RegisterCallback(
        [=](CubeEvent eventId, Uint16 eventData) {this->HandleEvent(eventId, eventData); }
    );


    /*Register Input manager*/
    p_InputManager = std::make_unique<InputManager>();
    p_InputManager->RegisterCallback(
        [=](CubeEvent eventId, Uint16 eventData) {this->HandleEvent(eventId, eventData); }
    );

    /*Register Renderer */
    p_RenderManager = std::make_unique<RenderManager>(n_WindowWidth, n_WindowHeight);
    p_RenderManager->Init(p_WindowManager->GetWindowObject());
    p_RenderManager->RegisterCallback(
        [=](CubeEvent eventId, Uint16 eventData) {this->HandleEvent(eventId, eventData); }
    );
    
    /*Register SceneManager*/
    p_SceneManager = std::unique_ptr<SceneManager>(arg);
    p_SceneManager->Init(n_WindowWidth, n_WindowHeight,p_RenderManager.get());
    p_SceneManager->RegisterCallback(
        [=](CubeEvent eventId, Uint16 eventData) {this->HandleEvent(eventId,eventData); }
    );



    b_IsRunning = true;

}

void Engine::HandleEvent(CubeEvent eventId, Uint16 eventData) {
    if (eventId == EV_CUBE_QUIT) {
        b_IsRunning = false;
    }
}

void Engine::Run()
{
    while (b_IsRunning) {
        /*Read Keys*/
        p_InputManager->HandleEvent();
        
        /*Update SceneManager*/
        p_SceneManager->UpdateScene();
        
       
        /*Update Renderer*/
        p_RenderManager->Render();

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



