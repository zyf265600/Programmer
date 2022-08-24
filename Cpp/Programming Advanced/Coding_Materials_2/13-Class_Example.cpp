#include <iostream>
using namespace std;

class Student
{
    //类中的属性和行为统一称为成员
    //属性 成员属性 成员变量
    //行为 成员函数 成员方法

public: //属性
    string m_name;
    int m_id;

public: //行为
    void setName(string name)
    {
        m_name = name;
    }
    void setID(int id)
    {
        m_id = id;
    }

    void showStudent()
    {
        cout << "name:" << m_name << " ID:" << m_id << endl;
    }
};

int main()
{

    Student stu;
    stu.setName("德玛西亚");
    stu.setID(250);
    stu.showStudent();

    return 0;
}
