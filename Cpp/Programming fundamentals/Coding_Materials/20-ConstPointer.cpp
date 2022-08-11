#include <iostream>
using namespace std;

int main()
{

    // const int  ptr;   ptr为常量，初始化后不可更改
    // const int* ptr;   *ptr为常量，不能通过*ptr改变它指向的内容
    // int const* ptr;   *ptr为常量，同上
    // int* const ptr;   ptr为常量，初始化后不能再指向其它地址

    int a = 10;
    int b = 20;

    // const修饰的是指针，指针指向可以改，指针指向的值不可以更改
    const int *p1 = &a;
    p1 = &b; //正确
    //*p1 = 100;  报错

    a = 10; //可以，这是在重新赋值

    // const修饰的是常量，指针指向不可以改，指针指向的值可以更改
    int *const p2 = &a;
    // p2 = &b; //错误
    *p2 = 100; //正确

    // const既修饰指针又修饰常量
    const int *const p3 = &a;
    // p3 = &b; //错误
    //*p3 = 100; //错误

    return 0;
}