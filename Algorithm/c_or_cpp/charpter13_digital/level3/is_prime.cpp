#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    int max = (int) sqrt(num);
    for (int i = 2; i <= max; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPrime(num)) {
        printf("%d is a prime number.", num);
    } else {
        printf("%d is not a prime number.", num);
    }
    return 0;
}