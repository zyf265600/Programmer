#include<stdio.h>

#define HEIGHT 10 //����������ǵĸ߶���10

int main(void) {

	int YHtrangle[HEIGHT][HEIGHT] = { 0 };
	int i, j;

	//�����������
	for (i = 0; i < HEIGHT; i++) {

		YHtrangle[i][0] = 1;//ÿ�е�һ��Ԫ��Ϊ 1
		YHtrangle[i][i] = 1;//ÿ�����һ��Ԫ��Ϊ 1
		//��Ҫ������Ǵӵ����п�ʼ��i == 2
		for (j = 1; j < i; j++)
			YHtrangle[i][j] = YHtrangle[i - 1][j - 1] + YHtrangle[i - 1][j];// ��������е� 2 �� �ڶ��� 1 + 1�ĺͣ�����������ǵĹ���
	}

	//����������
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j <= i; j++) {
			printf("%d	", YHtrangle[i][j]);
		}
		printf("\n");
	}

	return 0;
}