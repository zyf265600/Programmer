#include <fstream>
#include <iostream>
using namespace std;

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

// 左移运算符重载
ostream &operator<<(ostream &cout, Person p)
{
    cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
    return cout;
}

void test01()
{
    //打开文件
    ifstream ifs("58-person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    //读文件
    Person p;
    ifs.read((char *)&p, sizeof(p));
    cout << p;
}

int main()
{
    test01();
    return 0;
}