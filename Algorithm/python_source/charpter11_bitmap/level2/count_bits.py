# coding=utf-8

#  方法1
def countBits1(num):
    bits = [0] * (num + 1)
    for i in range(num + 1):
        for j in range(32):
            bits[i] += (i >> j) & 1
    return bits


# 方法2
def countOnes(x):
    ones = 0
    while x > 0:
        x &= (x - 1)
        ones += 1
    return ones


def countBits(num):
    bits = []
    for i in range(num + 1):
        bits.append(countOnes(i))
    return bits


if __name__ == '__main__':
    print(countBits1(3))
