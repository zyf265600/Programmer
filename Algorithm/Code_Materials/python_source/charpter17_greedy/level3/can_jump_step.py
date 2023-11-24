# coding=utf-8

class CanjumpStep:
    def canjump_step(self, nums):
        max_pos = 0
        start, end, step = 0, 0, 0  # 三参数初始化简化写法
        n = len(nums) - 1  # 因为len()不包含0，和index有冲突，因此-1
        while end < n:  # 跳到最后一位可忽略，不用增加次数
            for index, jump in enumerate(nums):  # 增加一个条件
                if index in range(start, end + 1) and \
                        index <= max_pos and \
                        index + jump > max_pos:
                    max_pos = index + jump
            start, end, step = end, max_pos, step + 1  # 参数变化简化写法
        return step


if __name__ == '__main__':
    ratings = [2, 3, 1, 1, 4]
    canjump_step = CanjumpStep()
    print canjump_step.canjump_step(ratings)
