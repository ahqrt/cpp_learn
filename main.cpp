#include <iostream>
#include <thread>
#include <string>
using namespace std;

int main() {
    auto func = [](int i) {
        string str = "第" + to_string(i) + "个线程在工作"+ "\n";
        cout << str;
    };
    //我的实验设备CPU为i9-9900K，8核16线程
    //此处得到的值为16
    int threadNum = thread::hardware_concurrency();
    threadNum = threadNum == 0 ? 2 : threadNum;  //确保线程数量不要为0
    threadNum = min(threadNum, 32);  //确保线程数量不要超过32个
    //输出：我的电脑可以开启16个线程
    cout << "我的电脑可以开启" << threadNum << "个线程" << endl;
    for (size_t i = 0; i < threadNum; ++i) {
        thread t(func,i);
        t.detach();
    }
    auto c = getchar();
}