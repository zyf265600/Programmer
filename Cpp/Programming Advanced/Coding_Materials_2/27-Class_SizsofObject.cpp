#include <iostream>
using namespace std;

class Person
{
private:
    //非静态成员变量占对象空间 属于类的对象上
    //这里不再是空对象，占用内存不再是 1 + 4 = 5 而是直接为 int 占用的大小 4 bytes
    int mA;

    //静态成员变量不占对象空间 不属于属于类的对象上
    static int mB;

public:
    Person() {}

    Person(int m_Age)
    {
        mA = m_Age;
    }

    ~Person() {}

    //函数也不占对象空间，所有函数共享一个函数实例 不属于属于类的对象上
    void func()
    {
        cout << "mA:" << this->mA << endl;
    }

    //静态成员函数也不占对象空间 不属于属于类的对象上
    static void sfunc()
    {
    }
};

void test01()
{
    //空对象占用内存空间为 1
    // C++编译器会给每个对象也分配一个字节空间，是为了区分空对象占内存空间的位置（占坑）
    //这意味着每一个空对象都有一个独一无二的内存地址
    Person p;
    cout << "size of p is " << sizeof(p) << endl;
}

int main()
{
    test01();
    return 0;
}