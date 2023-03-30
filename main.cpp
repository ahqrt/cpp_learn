#include <string>
#include <iostream>
#include "Message.h"

int main()
{
    TextMessage txtMsg;
    txtMsg.Text = "明天下午要去开会";

    Send(txtMsg);

    FileMessage fileMsg;
    fileMsg.FilePath = "c://hello.png";
    Send(fileMsg);
}