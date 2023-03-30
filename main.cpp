#include <iostream>
#include <vector>
using namespace std;

class CustomError: public exception
{
public:
    CustomError(int code, const string& message):m_code(code), m_message(message) {}

    const char* what() const noexcept override
    {
        return (m_message + "[Error code: " + to_string(m_code) + "]").c_str();
    }

    int code() const {return  m_code; }
private:
    string m_message;
    int m_code;
};

//void print(string&& str)
//{
//    str = "hello liuliu";
//    cout << str << endl;
//}
template<typename T>
inline void print(T&& str) {
    str = "Hello world";
    cout << str << endl;
}


string getPhoneNum() {
    cout << "请输入手机号码" << endl;
    string result;
    cin >> result;
    if (result.length() != 11) {
        throw CustomError(12, "手机号长度不够");
    }
    else{
        return result;
    };
}


int main() {

//        左值是表达式结束后依然存在的持久对象（代表一个在内存中占有确定位置的对象），右值是表达式结束时不再存在的临时对象
    string phoneNum;
    try {
        phoneNum = getPhoneNum();
    } catch (const exception& ex) {
        cout << ex.what() << endl;
        return 0;
    };

    cout << "用户输入的手机号是" << phoneNum << endl;
//    cout << "用户输入的手机号是" << e.code << endl;
    return 0;
}