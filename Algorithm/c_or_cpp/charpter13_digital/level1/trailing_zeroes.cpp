#include <stdio.h>

int trailingZeroes(int n) {
    int ans = 0;
    while (n) {
        n /= 5;
        ans += n;
    }
    return ans;
}
 
 
int main() {
    
    int result = trailingZeroes(3);
    printf("The result of arraySign is %d\n", result);
    return 0;
}