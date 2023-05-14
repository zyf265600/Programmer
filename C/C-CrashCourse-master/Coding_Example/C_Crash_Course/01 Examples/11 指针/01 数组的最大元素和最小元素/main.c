#include<stdio.h>

#define SIZE 5

void max_min(int a[], int len, int* max, int* min);

int main(void) {

	int a[SIZE];
	int max, min, i;

	printf("Enter 5 numbers: ");
	for (i = 0; i < SIZE; i++)
		scanf("%d", &a[i]);

	max_min(a, SIZE, &max, &min);

	printf("Largest: %d\n", max);
	printf("Smallest: %d\n", min);

	return 0;
}

void max_min(int a[], int len, int* max, int* min) {

	int i;

	*max = *min = a[0];
	for (i = 1; i < len; i++) {
		// a[i] ����� *max �� �ǿ϶������ *min С����֮Ҳ���� 
		if (a[i] > * max)
			*max = a[i];
		else if (a[i] < *min)
			*min = a[i];
	}

	// ���Լ�д�ģ���Ϊ������㷨ÿһ��ѭ����Ҫ�ж����� if��Ч�ʿ϶���������ĸ�
	//for (i = 1; i < len; i++) {
	//	if (*max < a[i])
	//		*max = a[i];

	//	if (*min > a[i])
	//		*min = a[i];
	//}
}
