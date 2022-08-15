#include <iostream>
using namespace std;

int *func()
{
    int a = 10;
    return &a;
}

int main()
{

    int *p = func();

    cout << *p << endl;//第一次能正确打印数字是因为编译器做了保留
    cout << *p << endl;//第二次数据就释放了

    return 0;
}