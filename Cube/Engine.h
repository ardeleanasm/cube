#pragma once
#include "stdafx.h"
#include "CubeEvent.h"

class ErrorManager;
class WindowManager;
class RenderManager;
class InputManager;
class SceneManager;
class Engine
{
public:
	Engine(std::string gameTitle);
	~Engine();
	void Start(SceneManager *arg);
	void Run();
	void Stop();
	

	void HandleEvent(CubeEvent eventId, Uint16 eventData);
protected:
private:
	//HandleEvent will replace messagebus! ;)
	
	std::string s_GameTitle;
	std::atomic<bool> b_IsRunning{ false };

	std::unique_ptr<ErrorManager> p_ErrorManager;
	std::unique_ptr<WindowManager> p_WindowManager;
	std::unique_ptr<RenderManager> p_RenderManager;
	std::unique_ptr<InputManager> p_InputManager;
	std::unique_ptr<SceneManager> p_SceneManager;
	const size_t n_WindowWidth = 800;
	const size_t n_WindowHeight = 600;
	
};

