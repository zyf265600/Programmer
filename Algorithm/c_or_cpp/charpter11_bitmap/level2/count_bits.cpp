#include <stdio.h>
#include <stdlib.h>

int reverseBits(int n) {
    int reversed = 0, power = 31;
    while (n != 0) {
        reversed += (n & 1) << power;
        n >>= 1;
        power--;
    }
    return reversed;
}


int main() {
    int num = 011100;  
 
    int test=reverseBits(num);
    
    
    return 0;
}