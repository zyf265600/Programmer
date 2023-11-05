#include <stdio.h>
#include <stdlib.h>

char* convertToBase7(int num) {
    char* result = (char*) malloc(sizeof(char) * 100); // 分配足够的空间存储结果字符串
    int i = 0;
    while (num > 0) {
        int remainder = num % 7;
        if (remainder < 10) {
            result[i++] = remainder + '0';
        } else {
            result[i++] = remainder - 10 + 'A';
        }
        num /= 7;
    }
    result[i] = '\0'; // 添加字符串结束符
    return result;
}

int main() {
    int num = 12345;
    char* result = convertToBase7(num);
    printf("%s\n", result); // 输出结果字符串
    free(result); // 释放内存空间
    return 0;
}