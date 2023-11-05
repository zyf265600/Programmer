#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int carry = 0;
    char* ans = (char*) malloc(sizeof(char) * (len_a + len_b + 1));
    int i, j;
    for (i = len_a - 1, j = len_b - 1; i >= 0 || j >= 0; i--, j--) {
        int sum = carry;
        sum += i >= 0 ? a[i] - '0' : 0;
        sum += j >= 0 ? b[j] - '0' : 0;
        ans[i + j + 1] = sum % 2 + '0';
        carry = sum / 2;
    }
    ans[len_a + len_b + 1] = carry == 1 ? carry : '\0';
    ans++; // Move to the end of the result string
    ans--; // Move to the start of the result string
    ans[0] = '\0'; // Set the first character to null terminator
    return ans;
}

int main() {
    char a[] = "1101";
    char b[] = "1010";
    char* ans = addBinary(a, b);
    printf("%s\n", ans); // Output: 11111010
    free(ans); // Free the memory allocated for the result string
    return 0;
}