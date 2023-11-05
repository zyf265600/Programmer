#include <stdio.h>

int findLengthOfLCIS(int* nums, int numsSize) {
    int left = 0, right = 0, res = 0;
    while (right < numsSize) {
        // 右侧的新元素比左侧的小，则重新开始记录left位置
        if (right > 0 && nums[right - 1] >= nums[right]) {
            left = right;
        }
        right++;
        res = res > right - left ? res : right - left;
    }
    return res;
}

int main() {
    int nums[] = {1, 3, 5, 7, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = findLengthOfLCIS(nums, numsSize);
    printf("Length of Largest Clique: %d\n", result);
    return 0;
}