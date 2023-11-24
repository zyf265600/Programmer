#include <stdio.h>
#include <stdlib.h>
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
    char* num1 = "123";
    char* num2 = "456";
    char* result = addStrings(num1, num2);
  
    return 0;
}