#define _CRT_SECURE_NO_WARNINGS 1

// �ַ�������������������㣺
// 1. �����ַ���
// 2. �ж��ַ����Ƿ�����һ���ַ��������õ���
// �������һ�������������⡣

#include<stdio.h>
#include<string.h>

// ���ַ������������ǿ�����ʵ��һ����������һ���ַ���Ȼ������һ������ȥ�������������ʵ����ת����ַ�

void LeftRotateOne(char str[], int size) {

	char tmp;
	int i;

	if (str == NULL)
		return;

	if (size == 1)
		return;

	// �ȱ����ַ�����һ��Ԫ��
	tmp = str[0];
	
	// ���ַ����ӵڶ���Ԫ�ؿ�ʼ������ǰ�ƶ�һλ
	for (i = 1; i < size; i++) {
		str[i - 1] = str[i];
	} 

	str[size - 1] = tmp;

}

// �������㷨����� size �Ƚϴ�Ч���Ǻܵ͵ģ���Ϊ����ÿ���ƶ����Ӷȶ��� O(n)
void LeftRotateN(char str[], int size, int n) {
	
	if (str == NULL)
		return;

	// ��ģ����Ϊ������ ��ABCD�� ���� 4 �� ����û����
	for (int i = 0; i < n % size; i++) {
		LeftRotateOne(str, size);
	}
}
// �ж� str1 str2 �Ƿ�Ϊ����
int LeftRotateCmp(char str1[], char str2[]) {

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return -1;

	if (len1 != len2)
		return 0;

	// �� str1 �� for ѭ������ len1 �Σ�ÿ���������� str2 �Ƚ�
	// ��ʵ���ֻ��ѭ�� len1 - 1 �μ��ɣ�������� д�� i < len1 - 1
	// ���������ת�Ľ�����ᱻ�Ƚϣ������Ҽ�ʹ����ת��һ�Σ��൱���жϽ����� str1 ��λ�ˣ�һ�����ã�
	for (int i = 0; i < len1; i++) {
		if (strcmp(str1, str2) == 0) {
			return 1;
		}
		LeftRotateOne(str1, len1);
	}

	return 0;
}

int main(void) {

	char str[] = "ABCD";
	char str1[] = "DABC";

	//LeftRotateOne(str, strlen(str));
	//LeftRotateN(str, strlen(str), 4);
	int a = LeftRotateCmp(str, str1);

	printf("%d", a);

	return 0;
}

