#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* arr, int left, int right) {
    while (left < right) {
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

char* reverseStr(char* s, int k) {
    if (s == NULL || strlen(s) == 0) {
        return s;
    }
    int n = strlen(s);
    for (int i = 0; i < n; i += 2 * k) {
        reverse(s, i, (i + k < n) ? i + k - 1 : n - 1);
    }
    return s;
}

int main() {
    char s[] = "Hello World";
    int k = 3;
    printf("Original String: %s\n", s);
    reverseStr(s, k);
    printf("Reversed String: %s\n", s);
    return 0;
}