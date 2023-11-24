# coding=utf-8


class FindAnagrams:
    def findAnagrams(self, s, p):
        s_len, p_len = len(s), len(p)

        if s_len < p_len:
            return []

        ans = []
        s_count = [0] * 26
        p_count = [0] * 26
        for i in range(p_len):
            s_count[ord(s[i]) - 97] += 1
            p_count[ord(p[i]) - 97] += 1

        if s_count == p_count:
            ans.append(0)

        for i in range(s_len - p_len):
            s_count[ord(s[i]) - 97] -= 1
            s_count[ord(s[i + p_len]) - 97] += 1

            if s_count == p_count:
                ans.append(i + 1)

        return ans


if __name__ == '__main__':
    s = "cbaebabacd"
    p = "abc"
    findAnagrams = FindAnagrams()
    findAnagrams.findAnagrams(s, p)
    print nums
