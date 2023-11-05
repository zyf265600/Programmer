def check_duplicates(array):
    bitset = [0] * (320000 // 32)

    for num in array:
        num0 = num - 1
        if (bitset[num0 // 32] >> (num0 % 32)) & 1:
            print(num)
        else:
            bitset[num0 // 32] |= 1 << (num0 % 32)
