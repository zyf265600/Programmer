# coding=utf-8
def quick_sort(array, start, end):
  if start >= end:
    return
  
  left, right = start, end
  pivot = array[(start + end) // 2]
  
  while left <= right:
      while left <= right and array[left] < pivot:
          left += 1
      while left <= right and array[right] > pivot:
          right -= 1
      if left <= right:
          array[left], array[right] = array[right], array[left]
          left += 1
          right -= 1
  
  quick_sort(array, start, right)
  quick_sort(array, left, end)

arr = [5, 2, 9, 3, 7, 6, 1, 8, 4]
quick_sort(arr, 0, len(arr)-1)
print(arr)