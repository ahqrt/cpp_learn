#include <iostream>
#include <string>

using namespace std;


struct inflatable
{
    string name;
    float volume;
    double price;
};

//union

union one4all
{
    int int_val;
    long log_val;
    double double_val;
};


enum spectrum { red, orange, yellow, blue, green, violet };

int main() {
//    init a struct
    inflatable hat {"hello", 100, 10};
//    struct can store different type
//    but union can only store on type and one value
    one4all pail;
    pail.int_val = 4;
    cout << pail.int_val << endl;
    pail.double_val = 1.34;
    cout << pail.int_val << endl;
    cout << pail.double_val << endl;

    spectrum band = spectrum::green;

    cout << band << endl;

    return 0;
}
