#include <iostream>
using namespace std;

class Animal
{

public:
    Animal()
    {
        cout << "Animal 构造函数调用！" << endl;
    }

    //纯虚函数
    virtual void Speak() = 0;

    //虚析构
    //利用虚析构可以解决，父类指针释放子类对象时，不干净的问题
    // virtual ~Animal()
    // {
    //     cout << "Animal 虚析构函数调用！" << endl;
    // }

    //纯虚析构 
    //需要声明也需要实现，因为如果父类中也有数据开辟到堆区，也需要释放
    //即 纯虚析构函数也要有函数体，用来做一些基类的清理工作，防止基类出现内存泄漏。
    //有了纯虚析构之后 这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;
};

Animal::~Animal()
{
    cout << "Animal 纯虚析构函数调用！" << endl;
}

class Cat : public Animal
{
public:
    string *m_Name;

public:
    Cat(string name)
    {
        cout << "Cat 构造函数调用！" << endl;
        m_Name = new string(name);
    }

    virtual void Speak()
    {
        cout << *m_Name << "小猫在说话!" << endl;
    }

    virtual ~Cat()
    {
        cout << "Cat析构函数调用!" << endl;
        if (this->m_Name != nullptr)
        {
            delete m_Name;
            m_Name = nullptr;
        }
    }
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->Speak();
    //通过父类指针去析构，不会调用子类中析构函数，导致子类如果有堆区属性，会出现内存泄漏
    //怎么解决？给基类增加一个虚析构函数
    //虚析构函数就是用来解决通过父类指针释放子类对象
    delete animal;
}

int main()
{
    test01();
    return 0;
}