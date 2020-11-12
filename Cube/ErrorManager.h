#pragma once
#include "stdafx.h"
#include "BusNode.h"
class ErrorManager:public BusNode
{
public:
	ErrorManager(){}
	~ErrorManager() {}
	void Update();
protected:
private:
	void OnNotify(Message message);
};

