#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "无参构造函数!" << endl;
		mAge = 0;
	}

	Person(int age) {
		cout << "有参构造函数!" << endl;
		mAge = age;
	}

	Person(const Person& p) {
		cout << "拷贝构造函数!" << endl;
		mAge = p.mAge;
	}

	//析构函数在释放内存之前调用
	~Person() {
		cout << "析构函数!" << endl;
	}
    
public:
	int mAge;
};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01() {

	Person man(100); //p对象已经创建完毕
	Person newman(man); //调用拷贝构造函数 括号法
	Person newman2 = man; //调用拷贝构造函数 隐式转换法

	Person newman3;
	newman3 = man; //不是调用拷贝构造函数，赋值操作
}

//2. 值传递的方式给函数形参
//相当于Person p1 = p; 创建一个副本出来

void doWork(Person p1) {}//调用拷贝构造函数 Person p1 = p
void test02() {
	Person p; //无参构造函数
	doWork(p);
}

//3. 以值方式返回局部对象（C++11后拷贝优化，返回时不使用拷贝构造函数，返回同一地址的对象，即使不使用引用返回）
/*需要说明的是，有些编译器出于程序执行效率的考虑，编译的时候进行了优化，函数返回值对象就不用复制构造函数初始化了，
  这并不符合 C++ 的标准。上面的程序，用 Visual Studio 2010 编译后的输出结果如上所述，
  但是在 Dev C++ 4.9 中不会调用复制构造函数。57行 p1 变成全局变量，才会调用拷贝构造函数。对这一点，读者不必深究。*/
Person doWork2()
{
    //static Person p1; //如果想返回引用对象 test03() 中的doWork2() 就会返回 对象p1 Person P = doWork2();就会调用拷贝构造函数了
    Person p1; //无参构造函数
	cout << (int *)&p1 << endl;
	return p1;
}

void test03()
{
	Person p = doWork2(); //这里Person p = doWork2()不会调用拷贝构造是因为处理器优化，p的空间直接存储了dowork2()的返回值 （p1 就是 p）这种行为是复制省略 而不是拷贝构造
	cout << (int *) &p << endl;
}


int main() {

	// test01();
	// test02();
	test03();

	return 0;
}