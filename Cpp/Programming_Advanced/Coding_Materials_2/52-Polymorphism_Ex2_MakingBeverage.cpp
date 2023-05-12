#include <iostream>
using namespace std;

class AbstractBeverage
{

public:
    //煮水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒杯
    virtual void Pour() = 0;
    //加料
    virtual void Side() = 0;

    //规定流程
    void MakeDrink()
    {
        Boil();
        Brew();
        Pour();
        Side();
    }
};

class Coffee : public AbstractBeverage
{
public:
    //烧水
    virtual void Boil()
    {
        cout << "煮农夫山泉!" << endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout << "冲泡咖啡!" << endl;
    }
    //倒入杯中
    virtual void Pour()
    {
        cout << "将咖啡倒入杯中!" << endl;
    }
    //加入辅料
    virtual void Side()
    {
        cout << "加入牛奶!" << endl;
    }
};

class Tea : public AbstractBeverage
{
public:
    //烧水
    virtual void Boil()
    {
        cout << "煮自来水!" << endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout << "冲泡茶叶!" << endl;
    }
    //倒入杯中
    virtual void Pour()
    {
        cout << "将茶水倒入杯中!" << endl;
    }
    //加入辅料
    virtual void Side()
    {
        cout << "加入枸杞!" << endl;
    }
};

//业务函数
void DoWork(AbstractBeverage *drink) // AbstractBeverage *drink = new Coffee;
{
    drink->MakeDrink();
    delete drink; //释放内存
}

void test01()
{
    //制作咖啡
    DoWork(new Coffee);
    cout << "--------------" << endl;

    //制作茶
    DoWork(new Tea);
}

int main()
{
    test01();
    return 0;
}