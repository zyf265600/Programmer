class Merge2Array:
    def merge(self, nums1, m, nums2, n):
        nums1[m:] = nums2
        nums1.sort()

    def merge2(self, nums1, m, nums2, n):
        sorted = []
        p1, p2 = 0, 0
        while p1 < m or p2 < n:
            if p1 == m:
                sorted.append(nums2[p2])
                p2 += 1
            elif p2 == n:
                sorted.append(nums1[p1])
                p1 += 1
            elif nums1[p1] < nums2[p2]:
                sorted.append(nums1[p1])
                p1 += 1
            else:
                sorted.append(nums2[p2])
                p2 += 1
        nums1[:] = sorted


if __name__ == '__main__':
    nums1 = [1, 2, 3]
    nums2 = [2, 5, 6]
    merge = Merge2Array()
    merge.merge2(nums1, 3, nums2, 3)
    print nums1
