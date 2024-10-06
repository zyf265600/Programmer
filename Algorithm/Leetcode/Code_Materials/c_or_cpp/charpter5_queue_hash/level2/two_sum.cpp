#include <stdio.h>
#include <stdbool.h>

int *twoSum(int *nums, int numsSize, int target)
{
    int *result = (int *)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    result[0] = -1; // 如果没有找到匹配的结果，返回-1
    result[1] = -1;

    
     return result;
}

int main(){

   int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int *result1 = twoSum(nums1, sizeof(nums1) / sizeof(nums1[0]), target1);
    if (result1[0] == 0 && result1[1] == 1)
    {
        printf("Test case 1 passed\n");
    }
    else
    {
        printf("Test case 1 failed\n");
    }

}