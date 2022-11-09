#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//插入和删除
void test01()
{
    vector<int> v1;
    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);
    //尾删
    v1.pop_back();
    printVector(v1);
    //插入
    v1.insert(v1.begin(), 100);
    printVector(v1);

    vector<int>::iterator it = v1.begin();
    v1.insert(it, 2, 1000);
    printVector(v1);

    v1.insert(it + 5, 666);
    printVector(v1);

    //删除
    v1.erase(v1.begin());
    printVector(v1);

    //清空
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1为空" << endl;
    }
}

int main()
{

    test01();

    return 0;
}