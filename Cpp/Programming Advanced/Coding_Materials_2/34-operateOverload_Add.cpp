#include <iostream>
using namespace std;

//加号运算符重载

class Person
{
public:
	int m_A;
	int m_B;

	//无参构造函数
	Person()
	{
		cout << "无参构造函数!" << endl;
	}

	//有参构造函数
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//拷贝构造函数
	Person(const Person &p)
	{
		cout << "拷贝构造函数!" << endl;
		this->m_A = p.m_A;
		this->m_B = p.m_B;
	}

	// 1. 成员函数实现 + 号运算符重载
	Person operator+ (Person &p1){
		Person temp;
		temp.m_A = this->m_A + p1.m_A;
		temp.m_B = this->m_B + p1.m_B;
		return  temp;
	}


	//析构函数在释放内存之前调用
	~Person()
	{
		cout << "析构函数!" << endl;
	}
};

void test01()
{
	Person p1 (10,10);
	Person p2 (10,10);
	Person p3 = p1 + p2;
	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
}

// 2. 全局函数实现 + 号运算符重载

int main()
{
	test01();
	return 0;
}