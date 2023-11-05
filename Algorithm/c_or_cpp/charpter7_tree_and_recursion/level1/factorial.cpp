
#include <stdio.h>

int factorial(int n){
// 1.先写递归结束条件
if(n <= 2){
return 1;
}
// 2.接着写等价关系式
return factorial(n-1)*n;
}

int main() {
    int n;
    printf("请输入一个正整数n：");
    scanf("%d", &n);
    printf("阶乘第 %d 项为：%d\n", n, factorial(n));
    return 0;
}


