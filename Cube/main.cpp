// cube.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "CubeEngine.h"
using namespace std;

int main(int argc, char** args)
{
	CubeEngine* engine = new CubeEngine();
	engine->CubeInit("Cube",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
	engine->CubeRun();
	delete engine;
	return 0;
}
