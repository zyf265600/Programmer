def remove_by_element(arr, size, key):
    index = -1
    for i in range(0, size):
        if arr[i] == key:
            index = i
            break
    if index != -1:
        for i in range(index + 1, size):
            arr[i - 1] = arr[i]
        size = size - 1
    return size


if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5, 6, 7, 8]
    index = remove_by_element(arr, 8, 3)
    print arr

    myList = [1, 2, 3, 4]
    A = [myList] * 3
    print(A)

