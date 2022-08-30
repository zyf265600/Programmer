#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal 构造函数" << endl;
    }

    virtual void eat()
    {
        cout << "能吃什么就吃什么" << endl;
    }
    virtual void run() {}

    Animal(const Animal &a){
        cout << "Animal 拷贝构造函数" << endl;
    }

    ~Animal()
    {
        cout << "Animal 析构函数" << endl;
    }

private:
    int name;
};
class Dog : public Animal
{
public:
    Dog()
    {
        cout << "Dog 构造函数" << endl;
    }
    virtual void eat()
    {
        cout << "吃狗粮" << endl;
    }
    virtual void shout() {}

    Dog(const Dog &a){
        cout << "Dog 拷贝构造函数" << endl;
    }
    ~Dog()
    {
        cout << "Dog 析构函数" << endl;
    }

private:
    int age;
};
int main()
{
    // Dog dog;
    // Animal &animal1 = dog;
    Animal *animal2 = new Dog;
    // Animal animal3 = dog; //相当于 Animal animal3 = Dog(dog); 显示法 去调用构造函数 会调用 Animal 的拷贝函数

    // animal1.eat();
    animal2->eat();
    delete animal2; //无法释放子类对象，此时需要使用虚析构 详见 54-Polymorphism_Destructor 
    // animal3.eat();
}