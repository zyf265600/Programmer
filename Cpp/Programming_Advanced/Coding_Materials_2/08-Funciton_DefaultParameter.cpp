#include <iostream>
using namespace std;

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值（不然为了让后面没有默认参数的变量都有值传递，还是要传递每一个变量，默认参数就没有意义了）
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数

int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

int func2(int a = 10, int b = 10);
int func2(int a, int b) {//如果函数声明有默认值，函数实现的时候就不能有默认参数
	return a + b;
}

int main() {

	cout << "ret = " << func(20, 20) << endl;
	cout << "ret = " << func(100) << endl;

	return 0;
}