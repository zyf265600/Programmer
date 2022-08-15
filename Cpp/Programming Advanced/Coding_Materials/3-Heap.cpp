#include <iostream>
using namespace std;

int *func()
{
    //利用new关键字，可以将数据开辟到堆区
    //指针，本质也是局部变量，放在栈上，指针保存的数据是放在堆区
    //new返回的是该数据类型的指针
    int *a = new int(10);
    return a;
}

int main()
{

    int *p = func();

	cout << *p << endl;
	cout << *p << endl;

	//利用delete释放堆区数据
	delete p;

	//cout << *p << endl; //报错，释放的空间不可访问，如果不报错存粹是运气好！


    //堆区开辟数组
	int* arr = new int[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//释放数组 delete 后加 []，如果没有释放，操作系统认为你不想释放，它会继续给你保留着让你用。
	delete[] arr;

	return 0;
}