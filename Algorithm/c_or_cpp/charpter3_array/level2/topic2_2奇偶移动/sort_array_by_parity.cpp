# coding=utf-8
class SortArrayByParity:
    # 对撞型双指针法
    def sortArrayByParity(self, nums):
        n = len(nums)
        res, left, right = [0] * n, 0, n - 1
        for num in nums:
            if num % 2 == 0:
                res[left] = num
                left += 1
            else:
                res[right] = num
                right -= 1
        return res

    # 基于冒泡排序的方法
    def sortArrayByParity2(self, nums):
        n = len(nums)
        i = 0
        while i < n:
            for j in range(0, n - 1 - i):
                if (nums[j] % 2 != 0) and (nums[j + 1] % 2 == 0):
                    tmp = nums[j]
                    nums[j] = nums[j + 1]
                    nums[j + 1] = tmp
            i = i + 1
        return nums


if __name__ == '__main__':
    nums = [3, 1, 2, 4]
    sortArrayByParity = SortArrayByParity()
    print sortArrayByParity.sortArrayByParit2(nums)
