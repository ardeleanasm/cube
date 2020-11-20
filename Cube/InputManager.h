#pragma once
#include "BusNode.h"
#include "Message.h"
class InputManager : public BusNode
{
public:
	InputManager();
	virtual ~InputManager();

	void UpdateEvent();
protected:
	void OnNotify(Message message);
private:
	Message g_MessageBus;
	void HandleEvent();
};