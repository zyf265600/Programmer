#include <iostream>
using namespace std;

class Beverage
{

public:
    void Boil()
    {
        cout << "煮水" << endl;
    }

    virtual void Brew() = 0;

    virtual void Pour()
    {
        cout << "倒入杯中" << endl;
    }

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

class Coffee : public Beverage
{
public:
    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }

    virtual void Side()
    {
        cout << "加糖和牛奶" << endl;
    }
};

class Tea : public Beverage
{
public:
    virtual void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }

    virtual void Side()
    {
        cout << "加柠檬" << endl;
    }
};

//业务函数
void DoWork(Beverage *drink)
{
    drink->MakeDrink();
    delete drink;
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