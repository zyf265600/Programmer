#include <stdio.h>
#include <stdlib.h>

int getSum(int a, int b) {
    while (b != 0) {
        int sign = (a & b) << 1;
        a = a ^ b;
        b = sign;
    }
    return a;
}


int main() {
   
 
    int test=getSum(12,13);
    
    
    return 0;
}