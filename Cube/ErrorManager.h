#pragma once
#include "stdafx.h"
#include "BusNode.h"
class ErrorManager:public BusNode
{
public:
	ErrorManager(){}
	~ErrorManager() {}
	void UpdateEvent();
protected:
private:
	void OnNotify(Message message);

};

