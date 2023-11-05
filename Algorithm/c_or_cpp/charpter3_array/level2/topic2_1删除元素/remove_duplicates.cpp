class RemoveDuplicates:
    def removeDuplicates(self, nums):
        j = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[j - 1]:
                nums[j] = nums[i]
                j += 1
        return j


if __name__ == '__main__':
    nums = [3, 2, 2, 1]
    deleteVal = RemoveDuplicates()
    print deleteVal.removeDuplicates(nums)
    print nums
