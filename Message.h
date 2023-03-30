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
    // 复制构造函数 也是浅拷贝
    Message(const Message& msg) = delete;
    // = 运算符
    void operator= (const Message& msg) = delete;
    ~Message() {
        instance = nullptr;
    };
    static Message* getInstance() {
        if (instance == nullptr) {
            instance = new Message();
        }
        return instance;
    };
    const int MessageId;

private:
    //    把构造函数设置为私有化，这样对象就不能初始化了
    Message() : MessageId {createMessageId()}{};

    int createMessageId() {
        std::random_device dev;
        return dev();
    }

    inline static Message* instance {nullptr};
};

#endif //CPP_LEARN_MESSAGE_H
