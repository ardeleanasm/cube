#include "stdafx.h"
#include "SceneManager.h"
#include "Sprite.h"
SceneManager::SceneManager()
{

	
}

void SceneManager::Init(const size_t windowWidth, const size_t windowHeight, RenderManager* renderer)
{
	n_WindowWidth = windowWidth;
	n_WindowHeight = windowHeight;
	p_DrawTarget = new Sprite(n_WindowWidth, n_WindowHeight);
	p_Renderer = renderer;
}

SceneManager::~SceneManager()
{
}



void SceneManager::Draw(size_t x, size_t y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	Pixel p;
	p.value.red = r;
	p.value.green = g;
	p.value.blue = b;
	p.value.alpha = a;
	p_DrawTarget->SetPixel(x, y, p);
		
}



void SceneManager::UpdateEvent()
{
	p_Renderer->Prepare(p_DrawTarget);
}

void SceneManager::OnNotify(Message message)
{
	if (message.GetEventType() == E_Scene_UserUpdate) {
		DrawScene();
	}

}
