#include <stdio.h>
#include <string.h>
#include <ctype.h>
// 双指针实现
char* reverseOnlyLetters(char* S) {
    if (S == NULL || strlen(S) == 0) {
        return S;
    }
    int len = strlen(S);
    char* ans = (char*)malloc(sizeof(char) * (len + 1));
    int j = len - 1;
    for (int i = 0; i < len; ++i) {
        if (isalpha(S[i])) {
            while (!isalpha(S[j]))
                j--;
            ans[i] = S[j--];
        } else {
            ans[i] = S[i];
        }
    }
    ans[len] = '\0';
    return ans;
}

int main() {
    char S[] = "Hello World";
    printf("Original String: %s\n", S);
    char* reversed_str = reverseOnlyLetters(S);
    printf("Reversed String: %s\n", reversed_str);
    free(reversed_str);
    return 0;
}