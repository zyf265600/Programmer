#include <iostream>
using namespace std;

int main()
{

    cout << "short 类型所占内存空间为： " << sizeof(short) << endl;

    cout << "int 类型所占内存空间为： " << sizeof(int) << endl;

    cout << "long 类型所占内存空间为： " << sizeof(long) << endl;

    cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;

    short num1 = 10;
    int num2 = 10;
    long num3 = 10;
    long long num4 = 10;

    cout << "short 类型所占内存空间为： " << sizeof(num1) << endl;

    cout << "int 类型所占内存空间为： " << sizeof(num2) << endl;

    cout << "long 类型所占内存空间为： " << sizeof(num3) << endl;

    cout << "long long 类型所占内存空间为： " << sizeof(num4) << endl;

    return 0;
}