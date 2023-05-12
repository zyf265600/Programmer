#include <iostream>
using namespace std;

// 1.函数重载需要函数都在同一个作用域下
// 2.函数名称相同
// 3.函数参数类型不同 或者 个数不同 或者 顺序不同

void func()
{
    cout << "func 的调用！" << endl;
}
void func(int a) //函数参数类型不同
{
    cout << "func (int a) 的调用！" << endl;
}

void func(double a) //函数参数类型不同
{
    cout << "func (double a)的调用！" << endl;
}
void func(int a, double b) //个数不同
{
    cout << "func (int a ,double b) 的调用！" << endl;
}
void func(double a, int b) //顺序不同
{
    cout << "func (double a ,int b)的调用！" << endl;
}

//函数返回值不可以作为函数重载条件
// int func(double a, int b)
//{
//	cout << "func (double a ,int b)的调用！" << endl;
//}

int main()
{

    func();
    func(10);
    func(3.14);
    func(10, 3.14);
    func(3.14, 10);

    return 0;
}