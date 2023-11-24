# coding=utf-8
class FindLengthOfLCIS:
    def findLengthOfLCIS(self, nums):
        ans = 0
        n = len(nums)
        start = 0
        for i in range(n):
            if i > 0 and nums[i] <= nums[i - 1]:
                start = i
            ans = max(ans, i - start + 1)
        return ans

    def findLengthOfLCIS2(self, nums):
        cur_len = 1
        res = 1
        for i in range(len(nums)):
            if nums[i - 1] > nums[i]:
                cur_len = 1
            else:
                cur_len = cur_len + 1
            res = max(cur_len, res)
        return res


if __name__ == '__main__':
    nums = [1, 3, 5, 4, 7]
    findLengthOfLCIS = FindLengthOfLCIS()
    print findLengthOfLCIS.findLengthOfLCIS2(nums)
