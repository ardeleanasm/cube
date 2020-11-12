#pragma once
#include "stdafx.h"
#include "Message.h"
class MessageBus
{
public:
    MessageBus() {
        messages = std::queue<Message>();
    };
    ~MessageBus() {};

    void AddReceiver(std::function<void(Message)> messageReceiver)
    {
        receivers.push_back(messageReceiver);
    }

    void SendMessage(Message message)
    {
        messages.push(message);
    }

    void Notify()
    {
        while (!messages.empty()) {
            for (auto iter = receivers.begin(); iter != receivers.end(); iter++) {
                (*iter)(messages.front());
            }

            messages.pop();
        }
    }

private:
    std::vector<std::function<void(Message)>> receivers;
    std::queue<Message> messages;
};
