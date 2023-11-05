# coding=utf-8
class SearchInsert:
    def searchInsert(self, nums, target):
        left, right = 0, len(nums) - 1

        while left <= right:
            # 中点
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1
        return left


if __name__ == '__main__':
    nums = [1, 3, 5, 6]
    target = 6
    searchInsert = SearchInsert()
    print searchInsert.searchInsert(nums, target)
