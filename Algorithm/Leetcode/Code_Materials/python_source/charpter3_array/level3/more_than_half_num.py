# coding=utf-8
import collections


class MoreThanHalfNum:
    # hash 法
    def moreThanHalfNum(self, nums):
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)
    # 拓展方法
    def moreThanHalfNum2(self, nums):
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate


if __name__ == '__main__':
    nums = [1, 2, 3, 2, 2, 2, 5, 4, 2]
    moreThanHalfNum = MoreThanHalfNum()
    print moreThanHalfNum.moreThanHalfNum(nums)
