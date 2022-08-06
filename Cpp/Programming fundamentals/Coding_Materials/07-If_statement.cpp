#include <iostream>
using namespace std;

int main()
{
    int weight1, weight2, weight3;
    int max;

    cout << "请输入第一只小猪的重量：";
    cin >> weight1;

    cout << "请输入第二只小猪的重量：";
    cin >> weight2;

    cout << "请输入第三只小猪的重量：";
    cin >> weight3;

    if (weight1 > weight2)
    {
        max = weight1;
        if (weight3 > weight1)
        {
            max = weight3;
        }
    }
    else if (weight2 > weight3)
    {
        max = weight2;
    }
    else if ((weight1 != weight2) && (weight2 != weight3))
    {
        max = weight3;
    }
    else
    {
        cout << "三只小猪一样重" << endl;
        max = -1;
    }

    if (max == weight1)
    {
        cout << "第一只小猪最重" << endl;
    }
    else if (max == weight2)
    {
        cout << "第二只小猪最重" << endl;
    }
    else if (max == weight3)
    {
        cout << "第三只小猪最重" << endl;
    }
}
