#include <string>
#include <iostream>
#include "Message.h"

int main()
{
    auto msg1 = Message::getInstance();
    auto msg2 = Message::getInstance();

    cout << "msg1->MessageId：" << msg1->MessageId << endl //输出：msg1->MessageId：1053936909
         << "msg2->MessageId：" << msg2->MessageId << endl;

    delete msg2;

    auto msg3 = Message::getInstance();
    cout << "msg3->MessageId：" << msg3->MessageId << endl;
    return 0;
}