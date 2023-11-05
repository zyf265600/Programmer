# coding=utf-8

def reverseBits(n):
    reversed = 0
    power = 31
    while n != 0:
        reversed += (n & 1) << power
        n >>= 1
        power -= 1
    return reversed


if __name__ == '__main__':
    print(reverseBits(101))
