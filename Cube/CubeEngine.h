#pragma once
class CubeEngine
{
public:
	CubeEngine();
	~CubeEngine();
	void CubeInit(std::string title,int posX,int posY,int width,int height, bool fullScreen);
	
	void CubeRun();
protected:
	void HandleEvent();
	void Update();
	void Render();
	void Clean();
private:
	SDL_Window* p_Window = nullptr;
	SDL_Renderer* p_Renderer = nullptr;
	std::atomic<bool> b_IsRunning{ false };
};