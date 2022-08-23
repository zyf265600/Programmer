#include <iostream>
using namespace std;

//手机类
class Phone
{
private:
    string m_PhoneName;

public:
    Phone(string name) //有参构造函数
    {
        m_PhoneName = name;
        cout << "Phone构造" << endl;
    }

    ~Phone()
    {
        cout << "Phone析构" << endl;
    }

    string getPhoneName()
    {

        return m_PhoneName;
    }
};

//人类
class Person
{
//成员变量
private:
    string m_Name;
    Phone m_Phone;

//成员函数
public:
    //初始化列表可以告诉编译器调用哪一个构造函数
    Person(string name, string pName) : m_Name(name), m_Phone(pName)
    {
        cout << "Person构造" << endl;
    }

    ~Person()
    {
        cout << "Person析构" << endl;
    }

    void playGame()
    {
        cout << m_Name << " 使用" << m_Phone.getPhoneName() << " 牌手机! " << endl;
    }
};
void test01()
{
    //当类中成员是其他类对象时，我们称该成员为 对象成员
    //构造的顺序是 ：先调用对象成员的构造，再调用本类构造
    //析构顺序与构造相反
    Person p("张三", "苹果X");
    p.playGame();
}

int main()
{

    test01();

    return 0;
}