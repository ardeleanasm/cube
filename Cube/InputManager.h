#pragma once
#include "Component.h"
class InputManager:public Component
{
public: 
	InputManager();
	virtual ~InputManager();
	
	
	void HandleEvent();
protected:
	
private:
	

};

