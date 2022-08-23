#include <iostream>
using namespace std;

class Person
{
public:
    int age;

    Person() {}

    Person(int age)
    {
        // this 指针指向的是调用的成员函数所属的对象
        this->age = age;
    }

    ~Person() {}

    //如果这里不使用Person&而是Person
    //返回时会调用拷贝构造函数  此时的返回值就是一个拷贝体  跟原来的p2不一样 表现在地址不一样，这样后面的.PersonAddAge就不作用在p2上了
    //这样等于只运行了一次年龄加的操作 20
    Person &PersonAddPerson(const Person &p1)
    {
        this->age += p1.age;

        // this是指向p2的指针，而*this指向p2的本体
        return *this;
    }
    
};

// 1. 解决名称冲突
void test01()
{
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;
}

// 2.返回对象本身用 *this
void test02()
{
    Person p1(10);
    Person p2(10);
    //链式编程思想（无限追加）
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "p2.age = " << p2.age << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}