# coding=utf-8

class CanJump:
   def canJump(self, nums) :
        n, rightmost = len(nums), 0
        for i in range(n):
            if i <= rightmost:
                rightmost = max(rightmost, i + nums[i])
                if rightmost >= n - 1:
                    return True
        return False


if __name__ == '__main__':
    ratings = [1, 0, 2]
    canJump = CanJump()
    print canJump.canJump(ratings)
