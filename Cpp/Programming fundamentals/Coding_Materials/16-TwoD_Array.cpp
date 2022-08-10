#include <iostream>
using namespace std;

int main()
{

    //二维数组数组名
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    cout << "二维数组大小： " << sizeof(arr) << endl;
    cout << "二维数组一行大小： " << sizeof(arr[0]) << endl;
    cout << "二维数组元素大小： " << sizeof(arr[0][0]) << endl;

    cout << "二维数组行数： " << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "二维数组列数： " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

    //地址
    cout << "二维数组首地址：" << arr << endl;
    cout << "二维数组第一行地址：" << arr[0] << endl;
    cout << "二维数组第二行地址：" << arr[1] << endl;

    cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
    cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;

    return 0;
}