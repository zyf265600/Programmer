def find_by_element(arr, size, key):
    for i in range(0, size):
        if arr[i] == key:
            return i
    return -1


if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5, 6, 7, 8]
    index = find_by_element(arr, 8, 3)
    print index
