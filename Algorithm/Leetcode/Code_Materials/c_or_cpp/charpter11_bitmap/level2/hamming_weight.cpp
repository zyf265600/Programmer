
#include <stdio.h>

int hammingWeight(int n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        count += (n >> i) & 1;
    }
    return count;
}

int main() {
    int num = 10101010; // 二进制表示为 1010 1010
    int i = 1; // 测试第 2 位
    int result=hammingWeight(num);
    
    
    return 0;
}