#pragma once
#include "BusNode.h"
#include "Sprite.h"
#include "Message.h"
class SceneManager : public BusNode
{
public:
	SceneManager();
	void Init(const size_t windowWidth, const size_t windowHeight);
	virtual ~SceneManager();
	void UpdateEvent();
protected:
	virtual void DrawScene() {
		
	}
	void Draw(size_t x, size_t y, Uint8 r,Uint8 g,Uint8 b,Uint8 a);
	void OnNotify(Message message);

	size_t n_WindowWidth;
	size_t n_WindowHeight;
private:
	Message g_MessageBus;
	void HandleEvent();
	Sprite* p_DrawTarget = nullptr;


};
