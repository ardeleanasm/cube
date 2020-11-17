#include "stdafx.h"
#include "SceneManager.h"
#include "Pixel.h"
SceneManager::SceneManager()
{

	
}

void SceneManager::Init(const size_t windowWidth, const size_t windowHeight)
{
	n_WindowWidth = windowWidth;
	n_WindowHeight = windowHeight;
	p_DrawTarget = new Sprite(n_WindowWidth, n_WindowHeight);
}

SceneManager::~SceneManager()
{
}

void SceneManager::Draw(size_t x, size_t y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	p_DrawTarget->SetPixel(x, y, Pixel(r, g, b, a));
		
}

void SceneManager::UpdateEvent()
{
	g_MessageBus = Message(E_Renderer_Scene, p_DrawTarget);
	Send(g_MessageBus);
}

void SceneManager::OnNotify(Message message)
{
	if (message.GetEventType() == E_Scene_UserUpdate) {
		DrawScene();
	}
	
}

void SceneManager::HandleEvent()
{
}
