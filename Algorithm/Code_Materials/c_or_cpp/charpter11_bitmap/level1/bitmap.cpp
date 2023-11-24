
#include <stdio.h>

bool getBit(int num, int i) {
return ((num & (1 << i)) != 0);
}

int setBit(int num, int i) {
    return num | (1 << i);
}

int clearBit(int num, int i) {
    int mask = ~(1 << i);
    return num & mask;
}

int updateBit(int num, int i, int v) {
    int mask = ~(1 << i);
    return (num & mask) | (v << i);
}

int main() {
    int num = 10101010; // 二进制表示为 1010 1010
    int i = 1; // 测试第 2 位
    
    if (getBit(num, i)) {
        printf("%dth bit is set\n", i);
    } else {
        printf("%dth bit is not set\n", i);
    }
    
    return 0;
}