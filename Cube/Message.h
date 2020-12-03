#pragma once
#include "stdafx.h"
#include "MessageType.h"
#include "Sprite.h"
class Message
{
public:
    Message() {

    }
    Message(const Uint16 eventType, const Uint64 eventData)
    {
        e_EventType = (MessageType_t)eventType;
        g_EventDataU64 = eventData;
    }

    Message(const Uint16 eventType)
    {
        e_EventType = (MessageType_t)eventType;
    }

    Message(const Uint16 eventType, const std::pair<Sint8,Uint8> eventData){
        e_EventType = (MessageType_t)eventType;
        g_EventDataPair = eventData;
    }

    Message(const Uint16 eventType, const std::tuple<Uint8, Sint32, Sint32> eventData) {
        e_EventType = (MessageType_t)eventType;
        g_EventDataTriple = eventData;
    }
    
   
    ~Message()
    {


    }

    MessageType_t GetEventType() const
    {
        return e_EventType;
    }

    Uint64 GetEventDataU64() const
    {
        return g_EventDataU64;
    }

    


    std::pair<Sint8, Uint8> GetEventDataPair() const {
        return g_EventDataPair;
    }

    std::tuple<Uint8, Sint32, Sint32> GetEventDataTriple() const {
        return g_EventDataTriple;
    }
private:
    MessageType_t e_EventType;
    Uint64 g_EventDataU64;
    
    std::pair<Sint8, Uint8> g_EventDataPair;
    std::tuple<Uint8, Sint32, Sint32> g_EventDataTriple;
    

};