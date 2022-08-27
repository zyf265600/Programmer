#include <iostream>
using namespace std;

//动物类
class Animal //此时公共的父类Animal称为虚基类
{
public:
    int m_Age;
};

//利用虚继承可以解决菱形继承问题
//继承前加virtual关键字后，变为虚继承
//羊类
class Sheep : virtual public Animal //继承前加virtual关键字后，变为虚继承
{
    public:
    int m_Age;
};

//驼类
class Camelus : virtual public Animal //继承前加virtual关键字后，变为虚继承
{
};

//羊驼类
class Alpaca : public Camelus, public Sheep //继承前加virtual关键字后，变为虚继承
{
};

void test01()
{
    Alpaca a;
    // a.m_Age; 报错 二义性 不确定继承哪一个
    a.Sheep::m_Age = 100;
    a.Camelus::m_Age = 200;
    //当菱形继承 两个父类具有相同的数据 可以加作用域加以区分
    cout << "a.Sheep::m_Age = " << a.Sheep::m_Age << endl;
    cout << "a.Camelus::m_Age = " << a.Camelus::m_Age << endl;
    cout << "a.Sheep::Animal::m_Age = " << a.Sheep::Animal::m_Age << endl;
    cout << "a.Camelus::Animal::m_Age = " << a.Camelus::Animal::m_Age << endl;
    cout << "a.Animal::m_Age = " << a.Animal::m_Age << endl;
    cout << "a.m_Age = " << a.m_Age << endl;

    //然而这份数据我们只需要一份就可以 现在两份资源浪费 到底多少岁？
    //使用虚拟继承 合并参数
    //实现原理：
}

int main()
{
    test01();
    return 0;
}