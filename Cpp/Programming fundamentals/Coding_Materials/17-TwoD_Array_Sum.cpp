#include <iostream>
#include <string>
using namespace std;

int main()
{

    int score[3][3]{{100, 100, 100}, {90, 50, 100}, {60, 70, 80}};

    string names[3]{"张三", "李四", "王五"};

    for (size_t i = 0; i < sizeof(score) / sizeof(score[0]); ++i)
    {
        int mark= 0;
        for (size_t j = 0; j < sizeof(score[0]) / sizeof(score[0][0]); ++j)
        {
            mark = mark + score[i][j];
        }

        cout << names[i] << "同学的总分是：" << mark << endl;

    }

    return 0;
}