#ifdef __unix__         
#define LINUX
#elif defined(_WIN32) || defined(WIN32) 
#define WINDOWS

#endif
#ifdef WINDOWS
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif // _WIN32



#include <iostream>
#include <memory>
#include <atomic> 

#include "SDL.h"