#include <iostream>
using namespace std;

// 1、构造函数分类
//  按照参数分类分为 有参和无参构造（无参又称为默认构造函数）
//  按照类型分类分为 普通构造和拷贝构造（除拷贝构造外的都是普通构造）

class Person{

public:
    //无参（默认）构造函数
    Person(){
        cout << "无参构造函数!" << endl;
    }

    //有参构造函数
    Person(int a){
        age = a;
        cout << "有参构造函数!" << endl;
    }

    //拷贝构造函数（把一个对象的值拷贝过来）
    //const 限制不能把被拷贝者的值更改
    //必须是&引用传递 因为如果是值传递，形参是实参的拷贝，而要拷贝实参就要用拷贝构造函数
    //用拷贝构造函数 如果是值传递，形参是实参的拷贝，而要拷贝实参就要用拷贝构造函数。。。
    //陷入infinite recurrence
    Person(const Person &p){
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }

    //析构函数
    ~Person(){
        cout << "析构函数!" << endl;
    }

public:
    int age;
};

// 2、构造函数的调用
//调用无参构造函数
void test01(){
    Person p; //调用无参构造函数
}

//调用有参的构造函数
void test02(){

    // 2.1  括号法，常用
    Person p1(10);
    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    // Person p2();

    // 2.2 显式法
    Person p2 = Person(10); //等号右面是匿名对象 将这个对象命名为 等号左边的名字
    Person p3 = Person(p2);
    Person(10); //单独写就是匿名对象  当前行结束之后，马上析构

    //注意2：不能利用拷贝构造函数 初始化匿名对象 编译器认为是对象声明
    // Person (p3); == Person p3;

    // 2.3 隐式转换法
    Person p4 = 10; // 相当于 Person p4 = Person(10);
    Person p5 = p4; // 相当于 Person p5 = Person(p4);
} 

int main()
{
    test01();
    test02();

    return 0;
}