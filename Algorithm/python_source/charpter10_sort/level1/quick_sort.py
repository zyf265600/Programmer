# coding=utf-8
def quick_sort(arr, left, right):
    if left < right:
        pivot = arr[right]
        i = left - 1
        for j in range(left, right):
            if arr[j] < pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i+1], arr[right] = arr[right], arr[i+1]
        quick_sort(arr, left, i)
        quick_sort(arr, i+1, right)

arr = [5, 2, 9, 3, 7, 6, 1, 8, 4]
quick_sort(arr, 0, len(arr)-1)
print(arr)
