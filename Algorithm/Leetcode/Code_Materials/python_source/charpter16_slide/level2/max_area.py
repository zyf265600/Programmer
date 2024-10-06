# coding=utf-8
class MaxArea:
    def maxArea(self, height):
        i, j, res = 0, len(height) - 1, 0
        while i < j:
            if height[i] < height[j]:
                res = max(res, height[i] * (j - i))
                i += 1
            else:
                res = max(res, height[j] * (j - i))
                j -= 1
        return res


if __name__ == '__main__':
    nums = [1, 8, 6, 2, 5, 4, 8, 3, 7]

    maxArea = MaxArea()
    print maxArea.maxArea(nums)
