# coding=utf-8
class CheckInclusion:
    def checkInclusion(self, s1, s2):
        n = len(s1)
        n2 = len(s2)
        dic1 = {}
        for i in s1:
            if i not in dic1:
                dic1[i] = 1
            else:
                dic1[i] += 1
        for i in range(n2 - n + 1):
            dic2 = {}
            for j in s2[i:i + n]:
                if j not in dic2:
                    dic2[j] = 1
                else:
                    dic2[j] += 1
            if dic2 == dic1:
                return True
        return False


if __name__ == '__main__':
    s1 = "ab"
    s2 = "eidbaooo"

    checkInclusion = CheckInclusion()
    print checkInclusion.checkInclusion(s1, s2)
