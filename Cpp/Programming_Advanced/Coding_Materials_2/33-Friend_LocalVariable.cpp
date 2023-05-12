#include <iostream>
using namespace std;

//可以声明一个类而不定义它。这个声明，有时候被称为前向声明(forward declaration)。
//在声明之后，定义之前，类Screen是一个不完全类型(incompete type)，即已知Screen是一个类型，但不知道包含哪些成员。
//不完全类型只能以有限方式使用，不能定义该类型的对象，
//不完全类型只能用于定义指向该类型的指针及引用，或者用于声明(而不是定义)使用该类型作为形参类型或返回类型的函数。
class Building;

class Goodgay
{

public:
    Goodgay();
    ~Goodgay();
    void visit();  //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
    void visit2(); //不让visit2函数作为Building的好朋友，不可以可以发访问Building中私有内容

private:
    Building *building;
};

class Building
{
    //告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
    friend void Goodgay::visit();

public:
    Building();

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};

//类外实现成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

Goodgay::Goodgay()
{
    building = new Building;
}

Goodgay::~Goodgay()
{
    delete building;
}

void Goodgay::visit()
{
    cout << "好基友正在访问 " << building->m_SittingRoom << endl;
    cout << "好基友正在访问 " << building->m_BedRoom << endl;
}

void Goodgay::visit2()
{
    cout << "好基友正在访问 " << building->m_SittingRoom << endl;
    // cout << "好基友正在访问 " building->m_BedRoom << endl;
}

void test01()
{
    Goodgay g1;
    g1.visit();
    g1.visit2();
}

int main()
{
    test01();
    return 0;
}