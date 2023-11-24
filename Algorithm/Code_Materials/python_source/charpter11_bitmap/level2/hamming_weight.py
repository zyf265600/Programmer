# coding=utf-8
def hammingWeight(n):
    count = 0
    while n != 0:
        n = n & (n - 1)
        count += 1
    return count


if __name__ == '__main__':
    print(hammingWeight(7))  # 输出: 3
    print(hammingWeight(15))  # 输出: 3
