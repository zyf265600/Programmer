#include <vector>
#include <iostream>
using namespace std;

void test01()
{
    vector< vector<int> > v;

    //创建小容器
    vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

    for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
}

int main()
{
    return 0;
}