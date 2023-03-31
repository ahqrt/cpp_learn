#include <iostream>
#include <string>
#include <format>

using namespace std;

//移除字符串左侧空白符
void ltrim(string& s) {
    auto endPosition = find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    });
    s.erase(s.begin(), endPosition);
};


void replace(function<void (string& a)> fn, string& s)
{
    fn(s);
}

void print(string& s) {
    cout << s << endl;
}

int main() {
    string string1 {"    liuliu"};

    replace( [](string& s) {
        cout << s << endl;
    }, string1);
}