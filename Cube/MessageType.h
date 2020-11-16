#pragma once

enum MessageType_t :Uint16 {
	E_Renderer_Render,

	E_ErrMng_TriggerError,

	E_Input_RequestPoll,
	
	E_Engine_SystemQuit,
};

