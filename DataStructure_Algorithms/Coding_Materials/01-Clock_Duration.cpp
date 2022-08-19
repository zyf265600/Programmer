#include <iostream>
#include <math.h>
using namespace std;

clock_t start, stop; /* clock_t是clock()函数返回的变量类型 */
double duration;     /* 记录被测函数运行时间，以秒为单位 */
#define MAXK 1e7     /* 被测函数最大重复调用次数 */

double f1(int maxN, double x)
{
    double p = 0; // product

    for (size_t i = 0; i < maxN; ++i)
    {
        p = p + i * pow(x, i);
    }

    // cout << p << endl; //检查结果
    return p;
}

double f2(int maxN, double x)
{
    double p = maxN - 1; // product

    for (size_t i = 0; i < maxN - 1; ++i)
    {

        p = (maxN - 1 - i) + x * p;
        --p;
    }

    // cout << p << endl; //检查结果
    return p;
}

int main()
{
    const int maxN = 10; //多项式最大项数，即多项式阶数+1
    double x = 1.1;      //自变量x

    /* 不在测试范围内的准备工作写在clock()调用之前*/

    start = clock(); /* 开始计时 */

    /* 把被测函数加在这里 */
    for (size_t i = 0; i < MAXK; i++)
    {
        f1(maxN, x);
    }

    stop = clock();                                       /* 停止计时 */
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC; /* 计算运行时间 */
    duration = duration / MAXK;                           /* 计算函数单次运行的时间 */

    /* 其他不在测试范围的处理写在后面，例如输出duration的值 */
    cout << "处理时间：" << duration << " 秒" << endl;

    start = clock(); /* 开始计时 */

    /* 把被测函数加在这里 */
    for (size_t i = 0; i < MAXK; i++)
    {
        f2(maxN, x);
    }

    stop = clock();                                       /* 停止计时 */
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC; /* 计算运行时间 */
    duration = duration / MAXK;                           /* 计算函数单次运行的时间 */

    /* 其他不在测试范围的处理写在后面，例如输出duration的值 */
    cout << "处理时间：" << duration << " 秒" << endl;

    return 0;
}