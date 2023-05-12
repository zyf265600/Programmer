#include <iostream>
using namespace std;

//重载关系运算符
class Person
{
    friend ostream &operator<<(ostream &cout, Person p);

private:
    string m_Name;
    int m_Age;

public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }

    bool operator== (Person p){
        if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        {
            return true;
        } else
        {
            return false;
        }
    }

    bool operator!= (Person p){
        if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        {
            return false;
        } else
        {
            return true;
        }
    }
};

ostream &operator<<(ostream &cout, Person p)
{
    cout << "姓名：" << p.m_Name << "\t年龄：" << p.m_Age;
    return cout;
}

void test01()
{
    Person a("孙悟空", 18);
    Person b("悟空", 18);

    cout << a << endl;
    cout << b << endl;

    if (a == b)
    {
        cout << "a和b相等" << endl;
    }
    else
    {
        cout << "a和b不相等" << endl;
    }

    if (a != b)
    {
        cout << "a和b不相等" << endl;
    }
    else
    {
        cout << "a和b相等" << endl;
    }
}

int main()
{
    test01();
    return 0;
}