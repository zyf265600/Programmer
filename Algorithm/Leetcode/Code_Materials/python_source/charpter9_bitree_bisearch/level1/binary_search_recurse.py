# coding=utf-8
# 二分，递归法

def binarySearch(arr, left, right, x):
    # 基本判断
    if right >= left:

        mid = int(left + (right - left) / 2)

        # 元素整好的中间位置
        if arr[mid] == x:
            return mid

            # 元素小于中间位置的元素，只需要再比较左边的元素
        elif arr[mid] > x:
            return binarySearch(arr, left, mid - 1, x)

            # 元素大于中间位置的元素，只需要再比较右边的元素
        else:
            return binarySearch(arr, mid + 1, right, x)

    else:
        # 不存在
        return -1


if __name__ == '__main__':
    arr = [2, 3, 4, 10, 40]
    x = 10
    # 函数调用
    result = binarySearch(arr, 0, len(arr) - 1, x)
    if result != -1:
        print ("元素在数组中的索引为 %d" % result)
    else:
        print ("元素不在数组中")
