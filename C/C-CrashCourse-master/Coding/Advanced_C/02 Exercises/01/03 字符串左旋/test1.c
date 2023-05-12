//ʵ��һ�����������������ַ����е�k���ַ���
//
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

#include<stdio.h>
#include<string.h>
#include<assert.h>

char* strRightReverse(char* str, int num) {

	char strAfterReverse[100] = {0};
	char* strReverse = str;
	char* strNotReverse = str;
	int i;
	int length = strlen(str);

	if (num < 0 || num > strlen(str)) {
		printf("Illegal input!\n");
		return str;
	}

	//�����Ƚ������������Ž� strReverse ������
	strNotReverse += num;

	for (i = 0; i < length - num; i++)
		strAfterReverse[i] = *strNotReverse++;

	//�ٽ�Ҫ�����������η�������β
	for (i = length - num; i < length; i++) {
		strAfterReverse[i] = *strReverse++;
	}
	strAfterReverse[length] = '\0';
	
	strcpy(str, strAfterReverse);

	return str;
}

int main(void) {

	char str[100];
	int num = 0;

	printf("Enter a string: ");
	scanf("%s", str);
	printf("Enter a number: ");
	scanf("%d", &num);

	strRightReverse(str, num);

	printf("output: %s\n", str);

	return 0;
}
