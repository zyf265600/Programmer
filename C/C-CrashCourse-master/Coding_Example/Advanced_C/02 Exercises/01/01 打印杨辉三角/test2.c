#include<stdio.h>

#define HEIGHT 10 //���Ҫ�޸�������ǵĸ߶��޸������������

#define ARRLEN HEIGHT + 1 

void printYH(int arr[][ARRLEN]) {

	int row, col;

	//�������ȽϷ������˼ά��⣬������������в��ã��±�� 1 ��ʼ��
	for (row = 1; row <= HEIGHT; row++) {

		for (col = 1; col <= row; col++) {

			if (col == 1 || col == row)
				arr[row][col] = 1;
			else
				arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];

			//ֱ���������������Ҫ������һ��ѭ�����
			printf("%d	", arr[row][col]);
		}

		printf("\n");
	}
	//��Ȼ�������Ҳ��ȱ�㣬������ڳ�����ʹ��������飬����Ҫʱ�̼ǵ��±�Ϊ 0 �ǲ����κ�����������ݵ�
}

int main(void) {

	int YHtrangle[ARRLEN][ARRLEN] = { 0 };

	printYH(YHtrangle);

	return 0;
}