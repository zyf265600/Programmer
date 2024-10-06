#include <stdio.h>

bool isPowerOfTwo(int n)
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
    int n = 12;

    if (isPowerOfTwo(n))
    {
        printf("%d is a power of 2.\n", n);
    }
    else
    {
        printf("%d is not a power of 2.\n", n);
    }
    return 0;
}