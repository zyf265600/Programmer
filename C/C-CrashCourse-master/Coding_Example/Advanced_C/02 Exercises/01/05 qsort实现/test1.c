#include<stdio.h>

//����һ�� Cmp ���͵ĺ���ָ�룬����ָ�뷵��ֵ�� int,������(int, int)
typedef int(*Cmp)(int, int);

void bubbleSort(int arr[], int size, Cmp cmp);
int Asc(int x, int y);
int Desc(int x, int y);

int main(void) {

	int arr[] = { 9, 5, 2, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	bubbleSort(arr, size, Desc);

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

void bubbleSort(int arr[], int size, Cmp cmp) {
	
	int i, j;
	int tmp;

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			//���� cmp �����Ĺ���������� 1������ if ����е�λ�û���
			if (cmp(arr[j], arr[j + 1]) == 1) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
				
		}
	}

}
//����
int Asc(int x, int y) {
	//�����һ�������ȵڶ��������󷵻� 1
	return (x > y ? 1 : 0);
}

//����
int Desc(int x, int y) {
	return (x < y ? 1 : 0);
}
