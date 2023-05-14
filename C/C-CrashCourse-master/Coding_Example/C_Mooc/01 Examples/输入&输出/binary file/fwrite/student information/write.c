#include<stdio.h>
#include<stdlib.h>
#include "student.h"

void getList(Student* Stu, int num);
int save(Student* Stu, int num);

int main(void) {

	int num = 0;

	printf("������ѧ��������\n");
	scanf("%d", &num);
	Student* Stu = (Student*)malloc(sizeof(Student) * num);

	getList(Stu, num);

	if (save(Stu, num)) {
		printf("����ɹ�\n");
	}
	else
		printf("����ʧ��\n");

	return 0;
}

void getList(Student* Stu, int num) {

	char format[STR_LEN];
	sprintf(format, "%%%ds", STR_LEN - 1);
	//�� format ��д�� %19s
	//%%%ds ǰ����%��������д��% 
	//%d �������Ĳ���������19 
	//����д��ľ��� %19s

	int i = 0;

	for (i = 0; i < num; i++) {

		printf("�� %d ��ѧ�� \n", i + 1);
		printf("\t������");
		scanf(format, Stu[i].name);
		printf("\t�Ա�0-�� 1-Ů 2-������:");
		scanf("%d", &Stu[i].gender);
		printf("\t����:");
		scanf("%d", &Stu[i].age);
		//�ǵ���scanfʱ����ʱ�� & 
	}

}

int save(Student* Stu, int num) {

	int ret = -1;
	FILE* fp = fopen("student.data", "wx");//���Ҫ��student.data����д�����ݣ��� wx ��Ϊ x
	if (fp) {
		ret = fwrite(Stu, sizeof(Student), num, fp);
		//��¼ fwrite �ķ���ֵ��д���ļ���ѧ������
		fclose(fp);
	}
	else
		printf("�ļ���ʧ�ܣ�");

	return (ret == num);
	//���д��ĸ���������������������0
}