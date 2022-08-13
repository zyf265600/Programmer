#include <iostream>
using namespace std;

int main()
{

    // 1、指针的定义
    int a = 10; //定义整型变量a

    //指针定义语法： 数据类型 * 变量名 ;
    int *p;

    //指针变量赋值
    p = &a;                                 //指针指向变量a的地址
    cout << "a的地址为: " << &a << endl;    //打印数据a的地址
    cout << "p指针的地址为: " << p << endl; //打印指针变量p

    // 2、指针的使用
    //通过*操作指针变量指向的内存
    cout << "*p = " << *p << endl;

    *p = 20;
    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;

    //3. 指针的内存大小
    cout << sizeof(p) << endl;
	cout << sizeof(char *) << endl;
	cout << sizeof(float *) << endl;
	cout << sizeof(double *) << endl;

    return 0;
}