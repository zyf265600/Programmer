#include <iostream>
using namespace std;

//继承同名成员处理方式 and 同名静态成员处理方式
class Base
{

public:
    int m_A;
    static int m_B;

public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base - func()调用" << endl;
    }

    void func(int a)
    {
        cout << "Base - func(int a)调用" << endl;
    }

    static void funcS()
    {
        cout << "Base - static funcS()调用" << endl;
    }

    static void funcS(int a)
    {
        cout << "Base - static funcS(int a)调用" << endl;
    }
};

//静态成员(对象共用，都能更改)
int Base::m_B = 1;

class Son : public Base
{

public:
    int m_A;
    int static m_B;

public:
    Son()
    {
        m_A = 200;
    }

    //当子类与父类拥有同名的成员函数，子类会“隐藏”父类中“所有版本”的同名成员函数
    //如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    void func()
    {
        cout << "Son - func()调用" << endl;
    }

    static void funcS()
    {
        cout << "Son - static funcS()调用" << endl;
    }
};

//同名静态成员(对象共用，都能更改)
int Son::m_B = 2;

void test01()
{
    Son s;
    //子类访问父类同名成员需要加作用域
    cout << "Son下的m_A = " << s.m_A << endl;
    cout << "Base下的m_A = " << s.Base::m_A << endl;
}

void test02()
{

    Son s;
    s.func();
    //当子类与父类拥有同名的成员函数，子类会“隐藏”父类中“所有版本”的同名成员函数
    //如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    s.Base::func();
    //即使子类中没有的同名重载也需要加父类的作用域
    s.Base::func(10);
}

void test03()
{
    //通过对象访问
    cout << "通过对象访问： " << endl;
    Son s;
    //第一个冒号代表着 要访问子类作用域
    //第二个冒号代表着 访问父类作用域下
    cout << "Son  下 m_B = " << s.Son::Base::m_B << endl;
    cout << "Base 下 m_B = " << s.Base::m_B << endl;

    //通过类名访问
    cout << "通过类名访问： " << endl;
    cout << "Son  下 m_B = " << Son::m_B << endl;
    //第一个冒号代表着 要通过类名的方式来访问
    //第二个冒号代表着 访问父类作用域下
    //然而 不可以通过父类访问子类 Base::Son::m_B
    cout << "Base 下 m_B = " << Son::Base::m_B << endl;
}

void test04()
{
    // 1、通过对象
    Son s;
    s.funcS();
    s.Base::funcS();
    s.Base::funcS(3);

    // 2、通过类名
    Son::funcS();
    Base::funcS();
    Son::Base::funcS(4);
}

int main()
{
    test01();
    test02();
    // test03();
    // test04();
    return 0;
}