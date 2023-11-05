# coding=utf-8
class FindOneNum:
    def findOneNum(arr):
        num_set = set()
        for num in arr:
            if num in num_set:
                num_set.remove(num)
            else:
                num_set.add(num)

        if len(num_set) == 0:
            return None
        return list(num_set)[0]

    def find_one_num(arr):
        flag = 0
        for i in arr:
            flag ^= i
        return flag
