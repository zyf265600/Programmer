# coding=utf-8

def get_bit(num, i):
    return (num & (1 << i)) != 0


def set_bit(num, i):
    return num | (1 << i)


def clear_bit(num, i):
    mask = ~(1 << i)
    return num & mask


def update_bit(num, i, v):
    mask = ~(1 << i)
    return (num & mask) | (v << i)


if __name__ == '__main__':
    print(get_bit(3, 1));
