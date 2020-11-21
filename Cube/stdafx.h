#ifdef __unix__         
#define PREFERRED_RENDERER "opengl"

#elif defined(_WIN32) || defined(WIN32) 

#define PREFERRED_RENDERER "direct3d"
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#endif


#include <iostream>
#include <memory>
#include <atomic> 
#include <functional>
#include <queue>
#include <vector>
#include <optional>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>
#include <tuple>
#include "SDL.h"


