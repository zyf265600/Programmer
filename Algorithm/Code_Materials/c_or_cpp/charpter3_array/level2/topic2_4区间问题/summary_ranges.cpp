# coding=utf-8
class SummaryRanges:
    def summaryRanges(self, nums):
        n = len(nums)
        res = []
        slow, fast = 0, 0
        while fast < n:
            if fast < n - 1 and nums[fast + 1] == nums[fast] + 1:
                fast += 1
            else:
                res.append((nums[slow], nums[fast]))
                slow = fast + 1
                fast = fast + 1
        # 此时res的内容如下：
        # [(0, 2), (4, 5), (7, 7)]
        print res
        # 转换成需要的字符串样式
        def p(x):
            slow, fast = x
            if slow == fast:
                return str(slow)
            else:
                return str(slow) + '->' + str(fast)

        return list(map(p, res))


if __name__ == '__main__':
    nums = [0, 1, 2, 4, 5, 7]
    summaryRanges = SummaryRanges()
    print summaryRanges.summaryRanges(nums)
