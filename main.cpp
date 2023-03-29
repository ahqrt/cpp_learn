#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;
int sum_arr(int arr[], int n);
void plusArrElement(vector<int>* arr);

int main() {
    const int ArSize = 8;
    int cookies[ArSize] {1, 2, 4, 8, 16, 32, 64, 128};
//    array<int, ArSize> cookies = {1, 2, 4, 8, 16, 32, 64, 128};

//    const 在类型前 和 类型后
//    const在类型前，代表不能修改指向的值，但是可以修改指针的指向
//    const int* pt  = cookies;
//    pt = new int;

//    const在类型后，代表不能修改指针的指向，但是可以修改指向的值
//    int* const pt  = cookies;
//    pt[0] += 1;

//    vector<int> cookies {1, 2, 4, 8, 16, 32, 64, 128};
//    plusArrElement(&cookies);
    // int sum = sum_arr(cookies, ArSize);
    for (int i = 0; i< ArSize; i++) {
        cout << cookies[i] << " ";
    }
    return 0;
}

int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

void plusArrElement(vector<int>* arr)
{
    for (int i = 0; i < (*arr).size() ; i++) {
        (*arr)[i] += 1;
    }
}


