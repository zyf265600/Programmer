# coding=utf-8
# size 表示元素个数，从1开始，key是要插入的元素
def add_by_element_sequence(arr, size, key):
    index = size
    for i in range(0, size):
        if key < arr[i]:
            index = i
            break

    for j in range(size, index, -1):
        arr[j] = arr[j - 1]
    arr[index] = key
    return index


if __name__ == '__main__':
    arr = [1, 2, 3, 6, 7, 8, 0, 0]
    index = add_by_element_sequence(arr, 6, 4)
    print arr
