#include <stdio.h>
#include <stdlib.h>

int multiply(int A, int B) {
    int min = A < B ? A : B;
    int max = A > B ? A : B;
    int ans = 0;
    for (int i = 0; min != 0; i++) {
        if ((min & 1) == 1) {
            ans += max;
        }
        min >>= 1;
        max += max;
    }
    return ans;
}


int main() {
   
 
    int test=multiply(12,13);
    
    return 0;
}