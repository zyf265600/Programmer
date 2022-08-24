#include <iostream>
using namespace std;

class Building
{
    //告诉编译器 Goodgay类是Building类的好朋友，可以访问到Building类中私有内容
    friend class Goodgay;

public:
    Building();

    ~Building()
    {
        cout << "Building析构函数!" << endl;
    }

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};

//类作友元
class Goodgay
{
public:
    //好基友要访问的建筑
    Building *building;

    Goodgay();
    void visit(); //参观函数 要访问Building中的属性

    ~Goodgay()
    {
        //在这里，什么时候指针什么时候消亡（被delete），指针对象成员building什么时候析构
        delete building;
        cout << "Goodgay析构函数!" << endl;
    }
};

//类内函数 类外实现
Building::Building()
{
    cout << "Building无参构造函数!" << endl;
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

Goodgay::Goodgay()
{
    cout << "Goodgay无参构造函数!" << endl;
    //创建建筑物的对象
    building = new Building;
}

void Goodgay::visit()
{
    cout << "好基友正在访问" << building->m_SittingRoom << endl;
    cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void test01()
{
    Goodgay goodgay;
    goodgay.visit();
}

int main()
{
    test01();
    return 0;
}