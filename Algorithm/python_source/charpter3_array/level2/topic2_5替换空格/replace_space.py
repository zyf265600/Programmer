# coding=utf-8
class ReplaceSpace:
    def replaceSpace(self, s):
        res = []
        for c in s:
            if c == ' ':
                res.append("%20")
            else:
                res.append(c)
        return "".join(res)

    def replaceSpace2(self, s):
        counter = s.count(' ')

        res = list(s)
        # 每碰到一个空格就多拓展两个格子，1 + 2 = 3个位置存’%20‘
        res.extend([' '] * counter * 2)

        # 原始字符串的末尾，拓展后的末尾
        left, right = len(s) - 1, len(res) - 1

        while left >= 0:
            if res[left] != ' ':
                res[right] = res[left]
                right -= 1
            else:
                # [right - 2, right), 左闭右开
                res[right - 2: right + 1] = '%20'
                right -= 3
            left -= 1
        return ''.join(res)


if __name__ == '__main__':
    replaceSpace = ReplaceSpace()
    s = "hello python!"
    print replaceSpace.replaceSpace2(s)
