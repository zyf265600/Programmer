# coding=utf-8
# 二分，迭代法
def binary_search(list, item):
    """二分查找方法"""
    low = 0  # 定义最小下标
    high = len(list) - 1  # 定义最大下标
    while low <= high:  # while循环，保证可以遍历到指定区域的元素，直到被被寻找的值和中间值相等
        mid = int((low + high) / 2)  # 寻找数组的中间值
        guess = list[mid]  # 获取列表最中间的元素
        if guess == item:
            return mid  # 进行条件判断，将中间值和被寻找的值进行比较，相等则返回该值
        if guess > item:
            high = mid - 1  # 如果被寻找的值小于中间值，则最大下标变化为中间值的前一个元素下标
        else:
            low = mid + 1  # 如果被寻找的值大于中间值，则最小下标变化为中间值的后一个元素下标
    return None


if __name__ == '__main__':
    my_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14]
    print(binary_search(my_list, 7))  # 输入一个有序列表和一个被寻找的值
