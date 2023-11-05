
#include <stdio.h>

int fibonacci(int n){
// 1.先写递归结束条件
if(n <= 2){
return 1;
}
// 2.接着写等价关系式
return fibonacci(n-1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("请输入一个正整数n：");
    scanf("%d", &n);
    printf("斐波那契数列的第 %d 项为：%d\n", n, fibonacci(n));
    return 0;
}


