#include "stdafx.h"
#include "ErrorManager.h"



void ErrorManager::UpdateEvent()
{
	//Send(Message)
}

void ErrorManager::OnNotify(Message message)
{
	if (message.GetEventType() == E_ErrMng_TriggerError) {
		Uint16 event = message.GetEventData();
		std::cout << "Error:" << event;

	}
}
