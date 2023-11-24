# coding=utf-8
from collections import defaultdict


class LemonadeChange:
    def lemonadeChange(self, bills):
        count = defaultdict(int)
        for bill in bills:
            if bill == 5:
                count[5] += 1
            elif bill == 10:
                # 10块的收入只能用5块的找
                count[10] += 1
                if not count[5]:
                    return False
                count[5] -= 1
            else:
                count[20] += 1
                # 由于两个5块可以组成一个10块因此优先找10块的
                if count[10] >= 1:
                    count[10] -= 1
                    if not count[5]:
                        return False
                    count[5] -= 1
                else:
                    if count[5] < 3:
                        return False
                    count[5] -= 3
        return True


if __name__ == '__main__':
    bills = [5, 5, 5, 10, 20]
    lemonadeChange = LemonadeChange()
    print lemonadeChange.lemonadeChange(bills)
