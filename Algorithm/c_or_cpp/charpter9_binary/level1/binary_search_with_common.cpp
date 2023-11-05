#include <stdio.h>

// 存在相同元素的二分查找
int search(int *nums, int target, int numsSize)
{
    if (nums == NULL || numsSize == 0)
    {
        return -1;
    }
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            // 找到之后，往左边找
            while (mid != 0 && nums[mid] == target)
            {
                mid--;
            }
            if (mid == 0 && nums[mid] == target)
            {
                return mid;
            }
            return mid + 1;
        }
    }
    return -1;
}

int main()
{
    int array[] = {1, 3, 3, 3, 3, 3, 5, 7, 9};
    int index = search(array, 3, 9);
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