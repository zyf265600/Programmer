#include <iostream>
using namespace std;

//继承中的对象模型
//从父类继承过来的成员，哪些属于子类对象中？
class Father{

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son :public Father
{
public:
	int m_D;
};

void test01()
{
    //16
    //父类中所有非静态成员属性都会被子类继承下去
    //父类中私有成员属性，是被编译器给隐藏了，因此访问不到， 但确实被继承下去了
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main() {

	test01();

	return 0;
}