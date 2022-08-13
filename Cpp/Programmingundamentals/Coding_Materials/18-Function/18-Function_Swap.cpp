#include "18-Function_Swap.hpp"

void swap(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}