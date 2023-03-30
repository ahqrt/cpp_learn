#include <string>
#include "Message.h"

int main()
{

    string msgContent{"明天下午三点开会"};
    Message *msg {new Message(12, 34, msgContent)};
    msg->sendMessage();
    Message *msg2 {new Message(34, 123, msgContent)};
    msg2->sendMessage();
    delete msg;
    delete msg2;
    return 0;
}