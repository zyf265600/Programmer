#include <iostream>
using namespace std;

//重载递减运算符
class MyInteger
{
    friend ostream &operator<<(ostream &cout, MyInteger myint);

public:
    MyInteger()
    {
        m_Num = 100;
    }

    MyInteger& operator--()
    {
        this->m_Num = this->m_Num - 1;
        return *this;
    }

    MyInteger operator--(int)
    {
        MyInteger temp = *this;
        this->m_Num = this->m_Num - 1;
        return temp;
    }

private:
    int m_Num;
};

ostream &operator<<(ostream &cout, MyInteger myint)
{
    cout << myint.m_Num;
    return cout;
}

void test01()
{
    MyInteger myint;

    cout << --(--myint) << endl;
    cout << myint << endl;
    cout << --(--myint) << endl;
    cout << myint << endl;
}
void test02()
{
    MyInteger myint;

    cout << myint-- << endl;
    cout << myint << endl;
    cout << myint-- << endl;
    cout << myint << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}