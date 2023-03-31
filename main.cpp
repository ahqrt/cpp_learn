#include <iostream>
#include <chrono>
#include <future>  //future与async都是在此定义的
#include <string>
using namespace std;

/**
 * 等待线程的返回值
 * 使用标准库为我们提供的 std::async 方法和 std::future 对象来获取线程的返回值
 */


int main() {
    auto func = [](int num)->int {
        cout << "线程已经开始执行啦" << endl;
        this_thread::sleep_for(chrono::seconds(6)); //子线程等待6秒
        cout << "线程执行结束啦" << endl;
        return num*3;
    };

//    使用 async 方法创建一个线程，此方法返回一个 future 对象
    future<int> result = async(func, 2);
    this_thread::sleep_for(chrono::seconds(3));
    cout << "开始获取线程返回值" << endl; //输出：开始获取线程返回值
    int val = result.get(); //获取线程返回值，这里会等待线程执行结束
    cout << "线程执行结果为" << val << endl;  //线程执行结果为369

}