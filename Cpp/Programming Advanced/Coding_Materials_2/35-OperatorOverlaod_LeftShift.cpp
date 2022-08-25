#include <iostream>
using namespace std;

//左移运算符重载
class Person
{
    friend ostream &operator<<(ostream &cout, Person p);

private:
    int m_A;
    int m_B;

public:
    Person(int a, int b) : m_A(a), m_B(b) {}

public:
    //利用成员函数重载 左移运算符 p.operator << (cout) 简化版本 p << cout
    //成员函数 实现不了 cout << p 不是我们想要的效果，即使能实现  p << cout
    //（cout是一个ostream（标准输出流）类型的对象）所以能作为形参传递
    // ostream& operator<<(ostream &cout)
    // {
    //     cout << m_A << endl;
    //     cout << m_B << endl;
    //     return cout;
    // }
};

//为达到预期效果，即 cout << p
//只能利用全局函数重载左移运算符
// ostream对象只能有一个
//正常的 cout 输出一个数据后返回的还是 cout 就可以继续输出下一个数据 所以在这里要返回cout的引用去继续通过 << 输出接下来的字符（链式编程）
ostream &operator<<(ostream &cout, Person p) // ostream对象只能有一个 必须引用传递
{
    cout << p.m_A << endl;
    cout << p.m_B << endl;
    return cout;
}

void test01()
{
    Person p1(10, 10);

    // p1 << cout << endl; //能用，但不符合预期
    // operator<<(cout,p1); 顺序固定 先cout 后 person 对象
    cout << p1 << endl; //正常的cout输出一个数据后返回的还是 cout 就可以继续输出下一个数据
}

int main()
{
    test01();
    return 0;
}
