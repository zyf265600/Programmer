# coding=utf-8
def trailingZeroes(n):
    cnt = 0
    for i in range(1, n + 1):
        while n % 5 == 0:
            n //= 5
            cnt += 1
    return cnt


if __name__ == '__main__':
    print(trailingZeroes(24))
