#include <stdio.h>

void reverseString(char* s, int n) {
    if (s == NULL || n == 0) {
        return;
    }

    for (int left = 0, right = n - 1; left < right; ++left, --right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
    }
}

int main() {
    char s[] = "Hello World";
    int n = sizeof(s) - 1; // 计算字符串的长度，不包含最后的'\0'字符
    reverseString(s, n);
    printf("%s\n", s); // 输出：dlroW olleH
    return 0;
}