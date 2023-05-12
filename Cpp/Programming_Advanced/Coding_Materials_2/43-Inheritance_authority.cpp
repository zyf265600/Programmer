#include <iostream>
using namespace std;

//继承方式
class Father
{

public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

//公共继承
class Son1 : public Father
{

public:
    void func()
    {
        m_A = 10; //父类中的公共权限成员 到子类中依然是公共权限
        m_B = 10; //父类中的保护权限成员 到子类中依然是保护权限
     // m_C = 10; //父类中的私有权限成员 到子类中不可访问
    }
};

//保护继承
class Son2 : protected Father
{
public:
    void func()
    {
        m_A = 20; //父类中的公共权限成员 到子类中变为保护权限
        m_B = 20; //父类中的保护权限成员 到子类中依然是保护权限
     // m_C = 20; //父类中的私有权限成员 到子类中不可访问
    }
};

//私有继承
class Son3 : private Father
{
public:
    void func()
    {
        m_A = 30; //父类中的公共权限成员 到子类中变为私有权限
        m_B = 30; //父类中的保护权限成员 到子类中变为私有权限
     // m_C = 30; //父类中的私有权限成员 到子类中不可访问
    }
};

class Grandson3 : public Son3{
public:
    void func()
    {
    // m_A = 100; //父类中的私有权限成员 到子类中不可访问
    // m_B = 100; //父类中的私有权限成员 到子类中不可访问
    // m_C = 100; //父类中的私有权限成员 到子类中不可访问
    }

};

void test01()
{
    Son1 s1;
    s1.m_A; //公共权限，类外可以访问
    //s1.m_B; 保护权限，类外不能访问
    //s1.m_C; 私有权限，类外不能访问

    Son2 s2;
    //s2.m_A; 保护权限，类外不能访问
    //s1.m_B; 保护权限，类外不能访问
    //s1.m_C; 私有权限，类外不能访问

    Son3 s3;
    //s3.m_A; 私有权限，类外不能访问
    //s1.m_B; 私有权限，类外不能访问
    //s1.m_C; 私有权限，类外不能访问
}

int main()
{
    test01();
    return 0;
}