#pragma once
#include "stdafx.h"
#include "MessageType.h"
#include "Sprite.h"
class Message
{
public:
    Message() {

    }
    Message(const Uint16 eventType, const Uint16 eventData)
    {
        e_EventType = (MessageType_t)eventType;
        g_EventDataU16 = eventData;
    }

    Message(const Uint16 eventType)
    {
        e_EventType = (MessageType_t)eventType;
    }

    
    ~Message()
    {


    }

    MessageType_t GetEventType() const
    {
        return e_EventType;
    }

    Uint16 GetEventDataU16() const
    {
        return g_EventDataU16;
    }

private:
    MessageType_t e_EventType;
    Uint16 g_EventDataU16;
    

};