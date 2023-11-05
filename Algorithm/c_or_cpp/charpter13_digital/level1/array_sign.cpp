#include <stdio.h>

int arraySign(int* nums, int numsSize) {
    int sign = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            return 0;
        }
        if (nums[i] < 0) {
            sign = -sign;
        }
    }
    return sign;
}
 
int main() {
    int nums[] = {1, -2, 3, 0, -4};
    int length = sizeof(nums) / sizeof(nums[0]);
    int result = arraySign(nums,length);
    printf("The result of arraySign is %d\n", result);
    return 0;
}