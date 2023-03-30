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
    unique_ptr<MyClass> myClass = make_unique<MyClass>(10);
//    auto myClass2 = myClass;  error 独占指针不能复制

    //一旦被重新赋值，之前关联的堆空间立即被释放
    myClass = make_unique<MyClass>(20);


// weak_ptr   弱指针主要是用于解决共享指针的循环引用问题
    cout << myClass->val << endl;
}
