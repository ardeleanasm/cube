#pragma once
#include "stdafx.h"
#include "MessageType.h"

template <typename V>
class EventData {
public:
    EventData() {

    }
    EventData(const V event) {
        g_Event = event;
    }
    ~EventData() {

    }

    V GetEvent() const {
        return g_Event;
    }

private:
    MessageType_t e_EventType;
    V g_Event;
};

class Message
{
public:
    Message() {

    }
    Message(const Uint16 eventType, const EventData<Uint16> eventData)
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

    Uint16 GetEventData() const
    {
        return g_EventDataU16.GetEvent();
    }

private:
    MessageType_t e_EventType;
    EventData<Uint16> g_EventDataU16;

};


