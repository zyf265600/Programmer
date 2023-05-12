#include<stdio.h>
#include<string.h>
#include<assert.h>

int strJudge(const char* str1, const char* str2) {

	char* str2_start = (char*)str2;

	//str1 �� str2 �����ǿ�ָ��
	assert(str1 != NULL && str2 != NULL);

	//����ַ��������� 1 ������жϾ�û��������
	assert(strlen(str1) != 1);
	
	//��������ַ������ȶ���һ�����϶�����
	if (!(strlen(str1) == strlen(str2)))
		return 0;

	//�� str2 ��Ѱ�� str1 �ĵ�һ��Ԫ��
	while (*str2) {
		if (*str2 == *str1) {
			++str1;// str1 �еĵ�һ��Ԫ���Ѿ��ҵ�������һ��ѭ��Ѱ�� str1 �е���һ��
			break;
		}

		++str2;
	}
	//û���ҵ���ֱ�ӷ��� 0
	if (*str2 == '\0')
		return 0;

	while (*str1) {
		
		++str2;

		if (*str2 == '\0')
			str2 = str2_start;
		
		if (!(*str2 == *str1))
			return 0;

		++str1;
	
	}

	return 1;
}

int main(void) {

	char str1[100];
	char str2[100];

	printf("Enter two strings: ");
	scanf("%s %s", str1, str2);

	if (strJudge(str1, str2))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
