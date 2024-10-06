#include <stdio.h>
#include <string.h>

char* addStrings(char* num1, char* num2) {
    int i = num1 - "0";
    int j = num2 - "0";
    int add = 0;
    char* ans = (char*) malloc(strlen(num1) + strlen(num2) + 1);
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? '0' : 0;
        int y = j >= 0 ? '0' : 0;
        int result = x + y + add;
        ans[strlen(ans)] = result % 10 + '0';
        add = result / 10;
        i--;
        j--;
    }
    ans[strlen(ans)] = '\0';
    return ans;
}

int main() {
    char num1[] = "123";
    char num2[] = "456";
    char* ans = addStrings(num1, num2);
    printf("%s\n", ans); // 输出：579
    free(ans); // 释放内存空间
    return 0;
}