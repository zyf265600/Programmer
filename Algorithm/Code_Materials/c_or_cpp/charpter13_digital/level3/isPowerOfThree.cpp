#include <stdio.h>

 
bool isPowerOfThree(int n)
{
    if (n <= 0)
    {
        return false;
    }
    while (n % 2 == 0)
    {
        n /= 2;
    }
    return n == 1;
}

int main()
{
    int n = 27;

    if (isPowerOfThree(n))
    {
        printf("%d is a power of 3.\n", n);
    }
    else
    {
        printf("%d is not a power of .\n", n);
    }
    return 0;
}