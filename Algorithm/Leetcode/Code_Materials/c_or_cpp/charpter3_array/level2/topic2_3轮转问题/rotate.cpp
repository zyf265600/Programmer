class Rotate:
    def rotate(self, nums, k):
        length = len(nums)
        k %= length
        nums[:] = nums[::-1]
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]


if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5, 6, 7]
    rotater = Rotate()
    rotater.rotate(nums, 3)
    print nums
