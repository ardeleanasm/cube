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

    Message(const Uint16 eventType, Sprite*eventData)
    {
        e_EventType = (MessageType_t)eventType;
        p_EventSpriteObj = eventData;
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

    Sprite* GetEventSpriteObj() const
    {
        return p_EventSpriteObj;
    }

private:
    MessageType_t e_EventType;
    Uint16 g_EventDataU16;
    Sprite* p_EventSpriteObj;

};


