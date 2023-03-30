#include <string>
#include <iostream>
#include <memory>
#include "Message.h"
#include <functional>
// 函数模版
template <typename T, typename = std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>>>
T getLargestNumber(const vector<T>& vect)
{
    T largestNumber {vect.at(0)};

    for (auto& val : vect) {
        if (val > largestNumber) {
            largestNumber = val;
        }
    }
    return largestNumber;
}

template<typename T1, typename T2, typename = std::enable_if<std::is_integral_v<T1> && std::is_floating_point_v<T2>>>
auto getBiggerNum(T1 param1, T2 param2)
{
    return param1 > param2 ? param1 : param2;
}


// 模版类 键值对
template <typename T>
class KeyValPair
{
public:
    string key;
    T value;
    KeyValPair(string k, T v): key(k), value(v) {};
};

// 模版类 键值字典
template <typename T>
class Dic
{
public:
    vector<KeyValPair<T>> vect;
    Dic() = default;
    void pushBack(KeyValPair<T> val)
    {
        vect.push_back(val);
    };

    auto operator[](string key)
    {
        for (KeyValPair<T>& pair: vect) {
            if (pair.key == key) {
                return pair.value;
            }
        }
    }
};


//void print(string& content) {
//    cout << content << endl;
//}

// 为函数指针定义别名
using printType = void (*) (string&);

// 最好使用标准库的function模版
//void callPrint(printType f, string& param) {
void callPrint(function<void(string&)> f, string& param) {
    f(param);
}
auto print = [](auto param) {
    std::cout << param << std::endl;
};

int main()
{
////    string content{"hello world"};
////
//////    callPrint(print, content);
////    vector<int> vect{ 0,1,2,3,4,5,6,7,8,9 };
//////    C++ 中的匿名函数通常以 [capture](parameters) -> returnType { body }
////    for_each(begin(vect), end(vect), [](int param) {
////        cout << param << endl;
////    });
//    string str { "等忙完这一阵子，" };
//    string str2 {"就可以接着忙下一阵子了。"};
//    auto print = [&str](string& param) {
//        string str2 { "马克思说：" };
//        //输出： 马克思说：等忙完这一阵子，就可以接着忙下一阵子了。
//        cout << str2 << str << param << std::endl;
//    };
    print(123);
}
