#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		m_A = 0;
		m_B = 0;
	}

	//this指针的本质是一个指针常量，指针的指向不可修改，相当于 Type* const pointer;
	//如果想让指针指向的值也不可以修改
  //在成员函数后面加const，修饰的是this指向，让指针指向的值不可以被修改，相当于 const Type* const pointer;
	void ShowPerson() const {
		//this = NULL; //不能修改this指针的指向 Person* const this;
		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的 当不是const函数时

		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
	}

	void MyFunc() {
		m_A = 10000;
	}

public:
	int m_A;
	mutable int m_B; //即使在常函数中，也可以修改这个值
};


//const修饰对象  常对象
void test01() {

	const Person person; //常量对象  
	cout << person.m_A << person.m_B << endl;
	//person.mA = 100; //常对象不能修改成员变量的值,但是可以访问
	person.m_B = 100; //但是常对象可以修改mutable修饰成员变量

	cout << person.m_A << person.m_B << endl;

	//常对象访问成员函数
	//person.MyFunc(); //常对象不能调用普通的成员函数

}

int main() {

	test01();

	return 0;
}