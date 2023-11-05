class IsValid:
    def isValid(s):
        if len(s) <= 1:
            return False

        smap = {
            '(': ')',
            '{': '}',
            '[': ']'
        }
        stack = []

        for i in range(len(s)):
            item = s[i]
            if item in smap:
                stack.append(item)
            else:
                if stack:
                    left = stack.pop()
                    if smap[left] != item:
                        return False
                else:
                    return False

        return len(stack) == 0
