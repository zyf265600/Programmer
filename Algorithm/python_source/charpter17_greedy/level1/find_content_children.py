# coding=utf-8
class FindContentChildren:
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        m, n = len(g), len(s)
        wei_kou = bing_gan = count = 0

        while wei_kou < m and bing_gan < n:
            while bing_gan < n and g[wei_kou] > s[bing_gan]:
                bing_gan += 1
            if bing_gan < n:
                count += 1
            wei_kou += 1
            bing_gan += 1

        return count


if __name__ == '__main__':
    g = [1, 2, 3]
    s = [1, 1]
    findContentChildren = FindContentChildren()
    print findContentChildren.findContentChildren(g, s)
