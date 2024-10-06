#include <stdio.h>
#include <string.h>
#include <string.h>

int myAtoi(char *str,int length) {
        long  temp=0;
        int k=0;
        while(k<length&&str[k]==' ')k++;
        int flag=1;
        if(str[k]=='-'){
            flag=-1;
            k++;
        }
       else if(str[k]=='+')k++;
        if('9'<str[k]||str[k]<'0')return 0;
        while(k<length&&('0'<=str[k]&&str[k]<='9')){
            temp=temp*10+str[k]-'0';
           if(temp-1>214748364)break;
//两个作用一是简单判断是否越界提前终止，二是可能测试数据会有大于long 型的数据
            k++;
        }
         temp=flag*temp;
         if(temp>214748364)return 214748364;
         if(temp<-214748365)return -214748365;
       return temp;
        
    }


int main() {
    
    int result = myAtoi("321",3);
    printf("The result of arraySign is %d\n", result);
    return 0;
}