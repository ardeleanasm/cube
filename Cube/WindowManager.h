#pragma once
#include "Component.h"
class WindowManager : public Component
{
public:
	WindowManager();
	virtual ~WindowManager();
	void Init(std::string title,int posX,int posY,int width,int height, bool fullScreen);
	

	
	SDL_Window* GetWindowObject() {
		return p_Window;
	}
protected:
	
private:
	SDL_Window* p_Window = nullptr;
	Uint16 g_ErrorEventMessage;
	
	
};