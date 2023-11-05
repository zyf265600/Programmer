#include <stdio.h>

 
int findMin(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    while (low < high) {
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high]) {
            high = pivot;
        } else {
            low = pivot + 1;
        }
    }
    return nums[low];
}

int main()
{
    int array[] = {5,6,7,1, 2, 3, 4};
    int index = findMin(array, 6);
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