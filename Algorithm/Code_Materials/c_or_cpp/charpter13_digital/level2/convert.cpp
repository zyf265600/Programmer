 
#include <iostream>
#define MAX_N 16 // 进制数最大位数

  
// 将十进制数M转化为N进制数
char* convert(int M, int N) {
   char F[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    char* result = (char*) malloc(MAX_N + 1); // 分配内存空间
    int flag = 0; // 判断正负
    if (M < 0) {
        flag = 1;
        M = -M;
    }
    int i = 0; // 当前位数指针
    while (M != 0) {
        int temp = M % N; // 取余数
        M /= N; // 整除N
        if (temp < 0) { // 如果余数为负数，则将其转化为正数
            temp += N;
            M += N;
        }
        result[i++] = F[temp]; // 将余数转换为字符并添加到结果中
    }
    result[i] = '\0'; // 添加字符串结束符
    if (flag) { // 如果为负数，则在结果前面添加负号
        result[0] = '-';
    }
    // result里的数字需要反转一下
    return result;
}

int main() {
    int M = 1234; // 要转换的十进制数
    int N = 16; // 要转换的进制数（假设为16进制）
    char* result = convert(M, N); // 调用函数进行转换并返回结果字符串指针

    printf("%s\n", result); // 输出结果字符串指针指向的字符串内容，即16进制数对应的字符数组形式
    
    return 0;
}