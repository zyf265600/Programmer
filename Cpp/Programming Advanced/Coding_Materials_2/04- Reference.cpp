#include <iostream>
using namespace std;

int main()
{

    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int A = 10;
    int B = 20;
    // int &c; //错误，引用必须初始化
    int &C = A; //一旦初始化后，就不可以更改
    C = B;      //这是赋值操作，不是更改引用

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;

    // int a = 0;
    // int const *d = &a;

    // int &b = a; // int* const b = &a;
    // int &c = b; // int* const c = &b;
    // int *e = &b;

    // cout << &a << endl;
    // cout << &b << endl;
    // cout << &c << endl;
    // cout << &d << endl;
    // cout << &e << endl;

    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // cout << d << endl;
    // cout << e << endl;

    return 0;
}