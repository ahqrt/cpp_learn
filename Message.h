//
// Created by ahqrt on 2023/3/30.
//

#ifndef CPP_LEARN_MESSAGE_H
#define CPP_LEARN_MESSAGE_H

#include <string>
#include <random>
using namespace std;

class Message
{
public:
    Message(): MessageId{createMessageId()} {}
    const int MessageId;
    virtual void sendMessage() {};

private:
    int createMessageId() {
        std::random_device dev;
        return dev();
    }
};

class TextMessage : public Message
{
public:
    TextMessage() : Message() {};

    void sendMessage() override { //重写父类消息
        cout << "发送文本消息" << MessageId << ":" << Text << endl;
    };

    string Text;
};

class FileMessage: public Message
{
public:
    FileMessage(): Message() {};
    void sendMessage() override {
        cout << "发送文件消息：" << MessageId << ":" << FilePath << endl;
    };
    string FilePath;
};


void Send(Message& msg) {
    msg.sendMessage();
};

#endif //CPP_LEARN_MESSAGE_H
