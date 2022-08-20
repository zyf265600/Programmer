#include <iostream>
using namespace std;

//函数重载注意事项
//1、引用作为重载条件

void func(int &a)
{
	cout << "func (int &a) 调用 " << endl;
}

void func(const int &a) //const int &a = 10; 合法
{
	cout << "func (const int &a) 调用 " << endl;
}


//2、函数重载碰到函数默认参数

void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
	cout << "func2(int a) 调用" << endl;
}

int main() {
	
	int a = 10;
	func(a); //调用无const，因为是变量
	func(10);//调用有const，因为是常数，如果放到 void func(int &a) 中，就是int &a = 10，是非法的


	//func2(10); //碰到默认参数产生歧义，需要避免。编译器不知道你在这里是要用第一个函数还是第二个。

	return 0;
}