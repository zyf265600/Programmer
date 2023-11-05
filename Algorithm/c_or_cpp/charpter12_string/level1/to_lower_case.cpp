#include <stdio.h>

char* toLowerCase(char* s) {
    int i = 0;
    while (s[i] != '\0') {  // 遍历字符串直到遇到结束符 \0
        if (s[i] >= 'A' && s[i] <= 'Z') {  // 判断字符是否是大写字母
            s[i] += 32;  // 转换为小写字母
        }
        i++;
    }
    return s;
}

int main() {
    char s[] = "Hello World";
    printf("%s\n", toLowerCase(s));
    return 0;
}