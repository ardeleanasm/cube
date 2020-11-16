#pragma once
#include "BusNode.h"
#include "Message.h"
class WindowManager: public BusNode
{
public:
	WindowManager();
	virtual ~WindowManager();
	void Init(std::string title,int posX,int posY,int width,int height, bool fullScreen);
	

	void UpdateEvent();
	SDL_Window* GetWindowObject() {
		return p_Window;
	}
protected:
	void OnNotify(Message message);
private:
	SDL_Window* p_Window = nullptr;
	EventData<Uint16> g_ErrorEventMessage;
	
	
};