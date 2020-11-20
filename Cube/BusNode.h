#pragma once
#include "stdafx.h"
#include "Message.h"
#include "MessageBus.h"
class BusNode
{
public:
    BusNode() {}

    virtual void UpdateEvent() {};
    void Register(MessageBus* messageBus) {
        this->messageBus = messageBus;
        this->messageBus->AddReceiver(this->GetNotifyFunc());
    };
protected:
    MessageBus* messageBus;

    std::function<void(Message)> GetNotifyFunc()
    {
        auto messageListener = [=](Message message) -> void {
            this->OnNotify(message);
        };
        return messageListener;
    }

    void Send(Message message)
    {
        messageBus->SendMessage(message);
    }

    virtual void OnNotify(Message message)
    {
        // Do something here. Your choice. You could do something like this.
        // std::cout << "Siopao! Siopao! Siopao! (Someone forgot to implement onNotify().)" << std::endl;
    }
};