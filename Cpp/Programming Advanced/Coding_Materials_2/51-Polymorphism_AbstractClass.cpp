#include <iostream>
using namespace std;

class Base
{

public:
    //纯虚函数
    //类中只要有一个纯虚函数就称为抽象类
    //抽象类无法实例化对象
    //子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base
{
    virtual void func()
    {
        cout << "Son - func调用" << endl;
    };
};

class Grandson : public Son
{
    virtual void func()
    {
        cout << "Grandson - func调用" << endl;
    };
};

void test01()
{

    // 抽象类不允许实例化对象
    // Base b;
    // new Base;

    Son s; //子类必须重写父类的纯虚函数，否则视为抽象类，也无法实例化对象
    Base *b = new Son;
    b->func();
    delete b;

    Grandson g; //子类必须重写父类的纯虚函数，否则视为抽象类，也无法实例化对象
    b = new Grandson;
    b->func();
    delete b;
}

int main()
{
    test01();
    return 0;
}