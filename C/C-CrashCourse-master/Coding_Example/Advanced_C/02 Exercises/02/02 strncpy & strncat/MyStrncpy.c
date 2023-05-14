#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

char* MyStrncpy(char* dest, char* src, int count);

int main(void) {

		char dest[100];
		char src[50];
		int count = 0;
	
		printf("Enter string dest: ");
		scanf("%s", dest);
		printf("Enter string src: ");
		scanf("%s", src);
		printf("Enter number of character(s) copy  from src to dest: ");
		scanf("%d", &count);

		MyStrncpy(dest, src, count);

		printf("%s\n", dest);

	return 0;
}

// �������ͬ���ǿ��ǲ���ȫ�ģ�
// 1. count ������� �ַ�����dest ��ô�죿
// 2. count ���� src �� src û�п��ַ���ô�죿

char* MyStrncpy(char* dest,const char* src, int count) {

	assert(dest && src);
	char* begin = dest;
	
	while (count-- && (*begin++ = *src++));
	
	// count ���С�� src �ĳ��ȣ���ô�õ����ַ����ǲ������ַ��ġ�
	// ���� \0 �Ǳ��յġ�
	if (count + 1 == 0) {
		*begin = '\0';
	}
	else {
		while (count--) {
			*begin++ = *src++;
		}
	}
	
	return dest;
}

