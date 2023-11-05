#include <stdio.h>

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

 int countPrimes(int n) {
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            cnt++;
        }
    }
    return cnt;
}