//
// Created by ahqrt on 2023/3/30.
//

#ifndef CPP_LEARN_MESSAGE_H
#define CPP_LEARN_MESSAGE_H

#include <string>
using namespace std;

class Message
{
public:
    Message(int fromUserId, int toUserId, string& messageContent);
    void sendMessage();
    const int MessageId;
    const int ToUserId;
    const int FromUserId;
    const string& MessageContent;
    static inline int MsgCount{0};

private:
    int createMessageId();
};

#endif //CPP_LEARN_MESSAGE_H
