#include <iostream>
using namespace std;

//继承方式
//公共继承
class Father
{

public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son : public Father
{

public:
    void func()
    {
        m_A; //父类中的公共权限成员 到子类中依然是公共权限
        m_B; //父类中的保护权限成员 到子类中依然是保护权限
     // m_C; //父类中的私有权限成员 到子类中不可访问
    }
};

int main()
{
    
    return 0;
}