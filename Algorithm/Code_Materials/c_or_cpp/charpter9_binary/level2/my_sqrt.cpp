#include <stdio.h>

 
int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

int main()
{
  
    int index = mySqrt(101);
    if (index == -1)
    {
        printf("Target not found in the array.\n");
    }
    else
    {
        printf("Target found at index %d.\n", index);
    }
    return 0;
}