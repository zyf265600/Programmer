#include <iostream>
using namespace std;

//空指针访问成员函数
class Person {
public:

	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}

	void ShowPerson() {
        //判断保证代码的健壮性,防止是空指针调用成员函数
		if (NULL == this) {//这样写如果不小心少打一个等于号 编译器会示警，this = NULL 则不会
			return;
		}
		cout << this-> mAge << endl;
	}

public:
	int mAge;
};

void test01()
{
	Person * p = NULL;
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
}

int main() {

	test01();

	return 0;
}