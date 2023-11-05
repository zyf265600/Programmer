# coding=utf-8

class CanCompleteCircuit:
    def canCompleteCircuit(self, gas, cost):
        n = len(gas)
        for i in range(n):
            j = i
            remain = gas[i]
            while remain - cost[i] >= 0:
                remain = remain - cost[j] + gas[(j + 1) % n]
                j = (j + 1) % n
                if (j == i):
                    return i
        return -1

    def canCompleteCircuit2(self, gas, cost):
        cur_sum = 0
        total_sum = 0
        start = 0
        for i in range(len(gas)):
            cur_sum += gas[i] - cost[i]
            total_sum += gas[i] - cost[i]
            if cur_sum < 0:
                start = i + 1
                cur_sum = 0
        if total_sum < 0:
            return -1
        return start


if __name__ == '__main__':
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]
    canCompleteCircuit = CanCompleteCircuit()
    print canCompleteCircuit.canCompleteCircuit2(gas, cost)
