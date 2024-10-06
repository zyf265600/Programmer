# coding=utf-8
class Monotonic(object):

    # 方法1
    def is_monotonic(self, nums):
        return self.is_sorted(nums, True) or self.is_sorted(nums, False)

    def is_sorted(self, nums, increasing):
        i, high = 0, len(nums) - 1
        for i in range(high):
            if increasing:
                if nums[i] > nums[i + 1]:
                    return False
            else:
                if nums[i] < nums[i + 1]:
                    return False
        return True

    # 方法2
    def is_monotonic2(self, nums):
        inc = True
        dec = True
        n = len(nums) - 1
        for i in range(n):
            if nums[i] > nums[i + 1]:
                inc = False
            if nums[i] < nums[i + 1]:
                dec = False
        return inc or dec


if __name__ == '__main__':
    monotonic = Monotonic()
    a = [1, 2, 3, 4]
    print(monotonic.is_monotonic2(a))
