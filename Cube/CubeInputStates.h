#pragma once
#include "stdafx.h"

enum CubeKeysState_t : Uint8 {
	EKeyDown,
	EKeyUp
};

enum CubeMouseState_t :Uint8 {
	ENoClick,
	ELeftMouseButtonUp,
	ELeftMouseButtonDown,
	ERightMouseButtonUp,
	ERightMouseButtonDown,
	EMiddleMouseButtonUp,
	EMiddleMouseButtonDown
};