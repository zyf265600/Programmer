



#  2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26
#  What is the sum of the digits of the number 2^31 ?
# if __name__ == "__main__":
#     power = 31
#     base = 2
#     counter = 0
#     res = [0]
#
#     for _ in range(power-1):
#         for i, d in enumerate(res):
#             # print('ok')
#             cal_num = d * 2 # base
#             if cal_num >9:
#                 ten_dig = 1
#                 dig = cal_num % 10
#                 res[i] += dig
#                 if i+1 >= len(res):
#                     res.append(0)
#                 res[i+1] += ten_dig
#
#             if res[i] > 9:
#                 ten_dig = 1
#                 dig = cal_num % 10
#                 res[i] += dig
#                 res[i + 1] += ten_dig
#
#     print(res)

if __name__ == "__main__":
    power = 31
    base = 2
    res = [1]  # 初始值改为1，表示2^0=1

    for _ in range(power):
        carry = 0
        for i in range(len(res)):
            cal = res[i] * base + carry
            res[i] = cal % 10
            carry = cal // 10

        if carry > 0:
            res.append(carry)

        # 处理最高位进位
        # while carry > 0:
        #     res.append(carry % 10)
        #     carry //= 10

    print(res)
    # 输出结果（res存的是低位到高位）
    print(''.join(map(str, reversed(res))))
