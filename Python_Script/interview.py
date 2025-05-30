



#  2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26
#  What is the sum of the digits of the number 2^31 ?
if __name__ == "__main__":
    power = 31
    base = 2
    counter = 0
    res = [0]

    for _ in range(power-1):
        for i, d in enumerate(res):
            # print('ok')
            cal_num = d * 2 # base
            if cal_num >9:
                ten_dig = 1
                dig = cal_num % 10
                res[i] += dig
                if i+1 >= len(res):
                    res.append(0)
                res[i+1] += ten_dig

            if res[i] > 9:
                ten_dig = 1
                dig = cal_num % 10
                res[i] += dig
                res[i + 1] += ten_dig

    print(res)



                # ten_digit = [int]
    #
    # count = power // limit
    #
    # count += 1
    #
    # input_num = 2**1000
    # print(input_num)
    #
    # res = 0
    # for c in str(input_num):
    #     res += int(c)
    #
    # print(res)
