#include <string>
#include <iostream>
#include <memory>
#include "Message.h"

class MyClass
{
public:
    int val;
    MyClass(int value):val(value){};
    ~MyClass(){};
};

int main()
{
    shared_ptr<MyClass> myClass0 = make_shared<MyClass>(10);
    cout << "myClass0 useCount" << myClass0.use_count() << endl;
    {
        auto myClass1 {myClass0};
        //myClass1诞生
        cout << "myClass0 useCount：" << myClass0.use_count() << endl;
        //输出：myClass0 useCount：2
        cout << "myClass1 useCount：" << myClass1.use_count() << endl;
        //输出：myClass1 useCount：2
        {
            shared_ptr<MyClass> myClass2{ myClass1 };
            //myClass2诞生
            cout << "myClass1 useCount：" << myClass1.use_count() << endl;
            //输出：myClass1 useCount：3
            cout << "myClass2 useCount：" << myClass2.use_count() << endl;
            //输出：myClass2 useCount：3
        } //myClass2消亡
    } //myClass1消亡
    cout << "myClass0 useCount：" << myClass0.use_count() << endl;
    //输出：myClass0 useCount：1
}//myClass0消亡，堆内存释放