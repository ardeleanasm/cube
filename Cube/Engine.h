#pragma once
#include "stdafx.h"
#include "BusNode.h"
class Message;
class MessageBus;
class ErrorManager;
class WindowManager;
class RenderManager;
class InputManager;
class Engine:public BusNode
{
public:
	Engine(std::string gameTitle);
	~Engine();
	void Start();
	void Run();
	void Stop();
	void UpdateEvent();
protected:
private:
	void OnNotify(Message message);
	void HandleEvents();
	std::string s_GameTitle;
	std::atomic<bool> b_IsRunning{ false };
	std::shared_ptr<MessageBus> p_MessageBus;
	std::unique_ptr<ErrorManager> p_ErrorManager;
	std::unique_ptr<WindowManager> p_WindowManager;
	std::unique_ptr<RenderManager> p_RenderManager;
	std::unique_ptr<InputManager> p_InputManager;
	Message g_BusMessage;
};

