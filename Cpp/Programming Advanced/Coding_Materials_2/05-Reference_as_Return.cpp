#include <iostream>
using namespace std;

//返回局部变量引用
int &test01()
{
    int a = 10; //局部变量
    return a;
}

//返回静态变量引用
int &test02()
{
    static int a = 20;
    return a;
}

int main()
{

    //不能返回局部变量的引用
    int &ref = test01();
    cout << "ref = " << ref << endl; //第一次结果正确是因为编译器做了保留
    cout << "ref = " << ref << endl;

    //如果函数做左值，那么必须返回引用
    int &ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000; //如果函数的返回值是引用，这个函数可以作为左值

    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    //可以理解为test02()返回的是a的原名，ref2是a的别名

    return 0;
}