#include <string>
#include <iostream>
#include <memory>
#include "Message.h"

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


int main()
{

//    vector<int> vect1 {1, 2, 3, 4, 5, 6};
//    vector<double> vect2{1.1,2.2,3.3,4.4,9.9,8.8,7.7,6.6};
//
//    auto result1 = getLargestNumber(vect1);
//    auto result2 = getLargestNumber(vect2);
//
//    auto res = getBiggerNum(10, 100.0);
//    cout << res << endl;
//    cout << result1 << endl;
//    cout << result2 << endl;

    Dic<int> dic;
    dic.pushBack({"test1", 123});
    dic.pushBack({"test2", 234});
    dic.pushBack({"test3", 345});

    cout << dic["test2"] << endl;
}
