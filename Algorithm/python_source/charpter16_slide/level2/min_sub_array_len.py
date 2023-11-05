# coding=utf-8
class MinSubArrayLen:
    def minSubArrayLen(self, s, nums):
        if not nums:
            return 0
        n = len(nums)
        ans = n + 1
        start, end = 0, 0
        total = 0
        while end < n:
            total += nums[end]
            while total >= s:
                ans = min(ans, end - start + 1)
                total -= nums[start]
                start += 1
            end += 1

        return 0 if ans == n + 1 else ans


if __name__ == '__main__':
    target = 7
    nums = [2, 3, 1, 2, 4, 3]

    minSubArrayLen = MinSubArrayLen()
    print minSubArrayLen.minSubArrayLen(target, nums)
