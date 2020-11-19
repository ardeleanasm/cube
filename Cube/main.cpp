// cube.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "Engine.h"
#include "SceneManager.h"

class GameLogic : public SceneManager {
protected:
	void DrawScene()
	{
		for (int x = 0; x < n_WindowWidth; x++) {
			for (int y = 0; y <n_WindowHeight; y++) {
				Draw(x, y, rand() % 256, rand() % 256, rand() % 256, 255); 

			}

		}
		CommitDraw();
	}
};

int main(int argc, char** args)
{
	GameLogic *gameLogic = new GameLogic();
	Engine* engine = new Engine("Cube");
	engine->Start(gameLogic);
	engine->Run();
	engine->Stop();
	delete engine;
	
		
	return 0;
}
