#pragma once
#include "stdafx.h"
#include "CubeEvent.h"
class Component
{
public:
    Component() {}
    ~Component() {}

    void RegisterCallback(std::function<void(CubeEvent eventId, Uint16 eventData)> method) {
        f_Callback = method;

    }
protected:
    void Invoke(CubeEvent eventId, Uint16 eventData) {
        f_Callback(eventId,eventData);
    }
    std::function<void(CubeEvent eventId,Uint16 eventData)> f_Callback;





};