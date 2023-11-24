#include <stdio.h>

int fmax(int maxSum, int sum)
{
    if (maxSum > sum)
    {
        return maxSum;
    }
    return sum;
}
double findMaxAverage(int *nums, int numsSize, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    int maxSum = sum;
    for (int i = k; i < numsSize; i++)
    {
        sum = sum - nums[i - k] + nums[i];
        maxSum = fmax(maxSum, sum);
    }
    return (double)(maxSum) / k;
}

int main()
{
    int nums[] = {1,12,-5,-6,50,3};
    int numsSize = 5;
    int k = 3;
    double result = findMaxAverage(nums, numsSize, k);
    printf("The maximum average is: %lf\n", result);
    return 0;
}