#include <stdio.h>

 
int peakIndexInMountainArray(int* arr, int arrSize) {
    int n = arrSize;
    int ans = -1;
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    int array[] = {1, 2, 3, 4, 3, 2, 1};
    int index = peakIndexInMountainArray(array, 7);
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