//
// Created by ahqrt on 2023/3/30.
//
#include <iostream>
#include <random>
#include "Message.h"

Message::Message(int fromUserId, int toUserId, string &messageContent)
    :FromUserId{fromUserId}, ToUserId{toUserId}, MessageContent {messageContent}, MessageId {createMessageId()}
    {
        MsgCount += 1;
    }

void Message::sendMessage()
{
    cout << "from: " << FromUserId << endl
    << "To " << ToUserId << endl
    << "Message: " << MessageContent << endl
    << "MessageCount: " << Message::MsgCount << endl
    << "MessageId: "<< MessageId << endl;
}

int Message::createMessageId() {
    std::random_device dev;
    return dev();
}