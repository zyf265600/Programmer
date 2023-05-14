#include<stdio.h>
#include"student.h"

void read(FILE* fp, int index);

int main(void) {

	FILE* fp = fopen("student.data", "r");
	if (fp) {
		fseek(fp, 0L, SEEK_END);//���ļ���/д��ʼ��λ�ö�����β
		long size = ftell(fp);//��ô��ļ���ʼ���ļ���β���ֽ���
		int index = 0;
		int number = size / sizeof(Student);
		printf("�� %d ��ѧ�����ݣ���Ҫ���ڼ���\n", number);
		scanf("%d", &index);
		read(fp, index - 1);
	}
	else
		printf("�ļ���ʧ�ܣ�\n");
}

void read(FILE* fp, int index) {

	fseek(fp, index * sizeof(Student), SEEK_SET);

	Student stu;

	if (fread(&stu, sizeof(Student), 1, fp) == 1) {
		printf("�� %d ��ѧ����\n", index + 1);
		printf("\t������%s\n", stu.name);
		printf("\t�Ա�");
		switch (stu.gender) {
		case 0:
			printf("��\n");
			break;
		case 1:
			printf("Ů\n");
			break;
		default:
			printf("����\n");
			break;
		}
		printf("\t���䣺%d\n", stu.age);
	}
}