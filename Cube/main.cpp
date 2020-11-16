// cube.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "Engine.h"


int main(int argc, char** args)
{
	Engine* engine = new Engine("Cube");
	engine->Start();
	engine->Run();
	engine->Stop();
	delete engine;
	return 0;
}
