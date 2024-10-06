#include <stdio.h>
#include <stdlib.h>

// 方法1
int* countBits1(int num) {
    int* bits = (int*)malloc((num+1) * sizeof(int));
    for (int i = 0; i <= num; i++) {
        bits[i] = 0;
        for (int j = 0; j < 32; j++) {
            bits[i] += (i >> j) & 1;
        }
    }
    return bits;
}

// 方法2
int countOnes(int x) {
    int ones = 0;
    while (x > 0) {
        x &= (x - 1);
        ones++;
    }
    return ones;
}

int* countBits(int num) {
    int* bits = (int*)malloc((num+1) * sizeof(int));
    for (int i = 0; i <= num; i++) {
        bits[i] = countOnes(i);
    }
    return bits;
}


int main() {
    int num = 33;  
 
    int* array=countBits(num);
    
    
    return 0;
}