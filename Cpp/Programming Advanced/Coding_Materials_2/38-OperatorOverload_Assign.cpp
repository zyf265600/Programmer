#include <iostream>
using namespace std;

//重载赋值运算符 只能通过成员函数实现，不可以通过全局函数
class Person
{
    friend ostream &operator<<(ostream &cout, Person p);

private:
    //年龄的指针
    int *m_Age;

public:
    Person(int age)
    {
        //将年龄数据开辟到堆区
        m_Age = new int(age);
    }

    Person(const Person &p)
    {
        this->m_Age = new int(*p.m_Age);
    }

    //链式编程
    Person& operator=(Person p)
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        this->m_Age = new int(*p.m_Age);

        //返回自身
        return *this;
    }

    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
};

ostream &operator<<(ostream &cout, Person p)
{
    cout << *p.m_Age;
    return cout;
}

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(100);
    cout << "p1的年龄为：" << p1 << endl;
    cout << "p2的年龄为：" << p2 << endl;
    cout << "p3的年龄为：" << p3 << endl;

    p3 = p2 = p1; //赋值操作
    cout << "p1的年龄为：" << p1 << endl;
    cout << "p2的年龄为：" << p2 << endl;
    cout << "p3的年龄为：" << p3 << endl;
}

int main()
{
    test01();
    return 0;
}