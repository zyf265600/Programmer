#define _CRT_SECURE_NO_WARNINGS 1

// atoi ʵ��
// ElementType atoi( const char *str );
//ת�� str ��ָ���ֽ��ַ����е�����ֵ��

//�����κοհ׷���ֱ���ҵ��׸��ǿհ׷���Ȼ����վ����ܶ���ַ�����ɺϷ���������ʾ����ת��֮Ϊ����ֵ���Ϸ�������ֵ�����в��֣�

//(��ѡ) ���򸺺�
//��λ

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef long long ElementType;

ElementType MyAtoi(const char* str);
ElementType StrToNum(int numbers[], int size);

int main(void) {

	char str[MAXSIZE];
	ElementType NumInStr;

	scanf("%s", str);
	
	NumInStr = MyAtoi(str);
	
	printf("%lld\n", NumInStr);// ת���ɴ��������Ҫ�ı� printf ��ת��˵��

	return 0;
}

ElementType MyAtoi(const char* str) {

	ElementType ret = 0;
	int isFirstNumber = 1;
	int flg = 1;
	int numbers[MAXSIZE];
	int size = 0;

	while (*str != '\0') {
		
		if (*str >= '0' && *str <= '9') {
			// �ж�������Ƿ�Ϊ��һ�����ֵ����֣�����ǣ�����Ҫ�ж�ǰһ���ַ��Ƿ��� - ��
			if (isFirstNumber) {
				if (*(str - 1) == '-')
					flg = -1;
				isFirstNumber = 0;
			}
			// ֱ�ӽ��ַ�ת��Ϊ���ַ��������ڣ�������õ���Ŀ�����ֵ�ÿһλ������Ȩ�أ���
			numbers[size++] = *str - '0';// ���ֶ�Ӧ�� ACSII ��ֵ��ȥ ��0����Ӧ�� ASCII ֵ����ʵ���������ʾ��ֵ
		}
		++str;
	}

	ret = StrToNum(numbers, size);

	return (flg * ret);
}

ElementType StrToNum(int numbers[], int size) {

	ElementType ret = 0;
	ElementType weight = 1;
	int i;

	for (i = size - 1; i >= 0; i--) {
		ret += numbers[i] * weight;
		weight *= 10;
	}

	return ret;
}

