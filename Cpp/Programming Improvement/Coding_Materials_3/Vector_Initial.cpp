#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printVector(vector<int> &v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << (*it) << " "; 
    }
    cout << endl;
}

int main(){

    // 无参构造
    vector<int> v1;

    for (size_t i = 0; i < 10; ++i)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 区间拷贝构造
    vector<int> v2 (v1.begin(), v1.end());
    printVector(v2);

    // 相同元素构造
    vector<int > v3 (10, 0);
    printVector(v3);

    // 拷贝构造函数
    vector<int > v4 (v1);
    printVector(v4);
    
    return 0;
}