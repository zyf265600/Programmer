# coding=utf-8

def getSum(a, b):
    while b != 0:
        sign = (a & b) << 1
        a = a ^ b
        b = sign
    return a


if __name__ == '__main__':
    print(getSum(1, -1))  # 输出: 2
