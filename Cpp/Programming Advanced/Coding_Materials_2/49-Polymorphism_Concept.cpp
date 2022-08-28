#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
    //虚函数
    //Speak函数就是虚函数
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

//小猫类
class Cat : public Animal
{
public:
    //重写 函数返回值类型 名称 参数
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

//小狗类
class Dog :public Animal
{
public:

	void speak()
	{
		cout << "小狗在说话" << endl;
	}

};

//执行说话的函数
//父类的指针或引用可以直接指向子类对象
//地址早绑定 在编译阶段确定函数地址
//然而我们希望让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段才能确定，就是晚绑定
//使用虚函数
void DoSpeak(Animal &animal) //Animal &animal = cat;
{
	animal.speak();
}

//多态满足条件： 
//1、有继承关系
//2、子类重写父类中的虚函数

//动态多态使用
//父类的指针或引用 执行子类对象

int main()
{
    Cat cat;
    DoSpeak(cat);

    Dog dog;
    DoSpeak(dog);
    return 0;
}
