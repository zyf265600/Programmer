# coding=utf-8
class DeleteVal:
    # 快慢型双指针
    def removeElement(self, nums, val):
        fast = 0
        slow = 0

        while fast < len(nums):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1

        return slow

    # 对撞型双指针
    def removeElement2(self, nums, val):
        right = len(nums) - 1
        left = 0
        while left <= right:
            if (nums[left] == val) and (nums[right] != val):
                tmp = nums[left]
                nums[left] = nums[right]
                nums[right] = tmp
            if nums[left] != val:
                left = left + 1
            if nums[right] == val:
                right = right - 1
        return left

    # 对撞+覆盖
    def removeElement3(self, nums, val):
        right = len(nums) - 1
        left = 0
        while left <= right:
            if nums[left] == val:
                nums[left] = nums[right]
                right = right - 1
            else:
                left = left + 1

        return left


if __name__ == '__main__':
    nums = [3, 2, 2, 3]
    deleteVal = DeleteVal()
    print deleteVal.removeElement2(nums, 3)
    print nums
