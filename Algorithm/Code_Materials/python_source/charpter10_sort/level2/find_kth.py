# coding=utf-8

def quicksort(nums, left, right):
    if left >= right:
        return
    start = left
    end = right
    pivot = nums[(start + end) // 2]
    
    while start <= end:
        while nums[start] < pivot:
            start += 1
        while nums[end] > pivot:
            end -= 1
        if start <= end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
    
    quicksort(nums, left, end)
    quicksort(nums, start, right)

def findKthLargest(nums, k):
    quicksort(nums, 0, len(nums) - 1)
    return nums[k - 1]

arr = [5, 2, 9, 3, 7, 6, 1, 8, 4]
findKthLargest(arr, 0, len(arr)-1)
print(arr)