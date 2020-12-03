#pragma once
#include "stdafx.h"
enum MessageType_t :Uint16 {
	E_Renderer_Render,			//request RenderManager to render a new scene
	

	E_ErrMng_TriggerError,		//request ErrorManager to trigger error

	E_Input_RequestPoll,        //request InputManager to poll events

	E_Scene_UserUpdate,         //request SceneManager to call user draw method

	E_Engine_SystemQuit,        //Signal Engine that we have SystemQuit

	E_Scene_KeyEvent,			//Signal SceneManager that we have key down event

	E_Scene_MouseEvent,				//Signal SceneManager that we have a mouse event

	


};
