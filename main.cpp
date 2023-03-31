#include <iostream>
#include <thread>  //线程类型在此头文件中定义
#include <string>
using namespace std;

int main() {
    auto func = [](int tId, int num) {
        for (std::size_t i = 0; i < num; i++) {
            string str = "thread id" + to_string(tId) + " print: " + to_string(i) + "\n";
            cout << str;
        }
    };

    int num = 6;

    thread t(func, 0, std::ref(num));
//    thread t2(func, 1, 6);
    t.join();
//    t2.join();
}