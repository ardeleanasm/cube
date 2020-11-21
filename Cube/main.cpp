// cube.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "Engine.h"
#include "SceneManager.h"
#include "CubeInputStates.h"
class GameLogic : public SceneManager {
protected:
	void DrawScene()
	{
		/*for (int x = 0; x < n_WindowWidth; x++) {
			for (int y = 0; y <n_WindowHeight; y++) {
				Draw(x, y, rand() % 256, rand() % 256, rand() % 256, 255); 

			}

		}*/
		
		
		DrawLine(0, 0, 800, 600, GREEN, 0xAA55AA55);
		DrawLine(0, 0, 800, 600, GREEN,0xAA55AA55);
		DrawLine(0, 300, 800, 300, RED,0xAA55AA55);
		DrawLine(400, 0, 400, 600, BLUE, 0xAA55AA55);
		DrawCircle(400, 300, 100, CYAN);
		
		DrawRect(0, 0, 100, 100,DARK_YELLOW);
		
		
		CommitChanges();
	}

	void HandleKeyEvents(Sint8 key, Uint8 state) {
		if (key == 'a' && state == EKeyDown ) {
			FillCircle(200, 200, 50, YELLOW);
		}
		if (key == 'b') {
			i++;
			FillRect(150, 0, 100*i, 100, DARK_YELLOW);
		}
		CommitChanges();
	}
private:
	int i = 0;
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
