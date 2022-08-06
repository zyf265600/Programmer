#include <iostream>
#include <ctime> //要调用time()，需要加入头文件ctime。
using namespace std;

// srand((int)time(0)); // 产生随机种子  把0换成NULL也行

// // Generate random number
// for (int i = 0; i < 10; i++) //输出十次
// {
//     cout << rand() % 100 << " "; //范围在[0,100)的随机整数数
// }
// cout << endl;
// cout << rand() / double(RAND_MAX) << endl; //生成0～1之间的浮点数

int main()
{
    srand((int)time(0));           // 产生随机种子  把0换成NULL也行
    int random = 1 + rand() % 100; //范围在[1,100]的随机整数数
    int guess = 0;
    // cout << random << endl;

    while (random != guess)
    {
        cout << "Please enter your guess number:" << endl;
        cin >> guess;

        if (guess > random)
        {
            cout << "Your number is too high!" << endl;
        }
        else if (guess < random)
        {
            cout << "Your number is too low!" << endl;
        }
        else
        {
            cout << "Your number is correct!" << endl;
        }
    }

    return 0;
}