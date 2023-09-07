#include <iostream>
using namespace std;

//交换整型函数
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//交换浮点型函数
void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

// 函数模版
template <class T> //声明一个模版，告诉编译器后面代码中紧跟着的 T 不要报错，T 是一个通用数据类型
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;

    // swapInt(a, b);

    //利用模板实现交换
    // 1、自动类型推导
    Swap (a, b);

    // 2、显示指定类型
    Swap<int> (a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << &b << endl;
    


}

int main()
{
    test01();
    return 0;
}