//#### 4. ���Ͼ���
//
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//
//
//
//Ҫ��ʱ�临�Ӷ�С��O(N);
//
//*�����Ȳ�ȥ�ܸ��Ӷ����⣬�������һ�ַ��������㷨��[�ο�����](https://blog.csdn.net/sgbfblog/article/details/7745450?depth_1-utm_source=distribute.pc_relevant_right.none-task&utm_source=distribute.pc_relevant_right.none-task)*


#include<stdio.h>
#include<assert.h>

#define ROW 3
#define COL 3

void printArr(int arr[ROW][COL]);
int searchYangMatri(int arr[ROW][COL], int row, int col, int target, int position[2]);

int main(void) {

	int target;
	int position[2] = {-1, -1};//Ŀ�����ھ����е�λ��

	//ע�⣺���Ͼ��󲢲�����������
	int arr[ROW][COL] = {
		{1, 3, 5},
		{2, 4, 6},
		{7, 8, 9},
	};

	printArr(arr);

	printf("Enter a target: ");
	scanf("%d", &target);

	if (searchYangMatrix(arr, ROW, COL, target, position))
		printf("%d is found!The position in the matrix is as follow:(%d, %d)\n", target, position[0], position[1]);
	else
		printf("Not Found!\n");


	return 0;
}

void printArr(int arr[ROW][COL]) {

	int i, j;

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++)
			printf("%d	", arr[i][j]);
		printf("\n");
	}

}

int searchYangMatrix(int arr[ROW][COL], int row, int col, int target, int position[2]) {

	assert(arr != NULL);

	//�Ӿ�������Ͻǿ�ʼ��Ѱ
	int i = 0;
	int j = col - 1;

	while (i < ROW && j >= 0) {

		//���Ŀ���������Ͻǵ�������ȥ����һ�У���Ϊ���Ͻǵ�������һ�������ģ�
		if (target > arr[i][j])
			i++;
		//���Ŀ���������Ͻǵ�С����ȥ����һ�У���Ϊ���Ͻǵ�������һ������С�ģ�
		else if (target < arr[i][j])
			j--;
		else {
			position[0] = j;//������������½ǵ�Ԫ�ط��ڶ�λ����ϵ��ԭ���ϣ� x ������� ���Ƕ�Ӧ�ģ�x = col��Ԫ������λ�õ� col��
			position[1] = row - 1 - i;// y �� �����еĹ�ϵ�� y = ROW - 1 - row��Ԫ������λ�õ� row��
			return 1;
		}

	}

	return 0;
	
}
