# coding=utf-8

def multiply(A, B):
    min_num = min(A, B)
    max_num = max(A, B)
    ans = 0
    for i in range(min_num.bit_length()):
        if min_num & 1:
            ans += max_num
        min_num >>= 1
        max_num += max_num
    return ans


if __name__ == '__main__':
    print(multiply(7, 3))  # 输出: 3
