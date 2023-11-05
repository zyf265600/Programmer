# coding=utf-8
class FindMaxAverage:
    def findMaxAverage(self, nums, k):
        low = 0
        all = sum(nums[0:k])
        avg = all
        for i in range(k, len(nums)):
            all = all + nums[i] - nums[low]
            low += 1
            avg = max(avg, all)
        return avg / k


if __name__ == '__main__':
    nums = [1, 12, -5, -6, 50, 3]
    k = 4
    findMaxAverage = FindMaxAverage()
print findMaxAverage.findMaxAverage(nums, k)
