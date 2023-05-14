#include<stdio.h>

int main(void) {

	printf("%+09d\n", 123);
	printf("%-+09d\n", -123);
	return 0;
}

int main(void) {

	printf("%+09.2f\n", 12.3);
	printf("%-8.3f\n", -12.3);
	return 0;
}

int main(void) {

	int len = 5;
	int dec = 2;
	printf("%*.*f\n",5, 2, 12.3);
	printf("%*.*f\n",len, dec, 12.3);
	return 0;
}

int main(void) {

	printf("%hhd\n", (char)12345);//���� 1 ���ֽ����
	printf("%hd\n", 12345);//���� short ���
	return 0;
}

int main() {

	int num;
	printf("%d%n\n", 123, &num);
	printf("%d\n", num);

	return 0;
}

int main() {

	int num;
	scanf("%*d %d", &num);
	printf("%d\n", num);

	return 0;
}

int main(void) {
	
	float x;
	scanf("%g", &x);
	printf("%F", x);
	
	return 0;
}

int main(void) {

	int num = 0;
	int return_scanf = 0;
	int return_printf = 0;

	return_scanf = scanf("%d", &num);
	return_printf = printf("%d\n", num);

	printf("%d:%d\n", return_scanf, return_printf);
	return 0;
}


FILE* fp = fopen("file", "r");

if (fp) {
	fscanf(fp, ...);
	fclose(fp);
}
else {
	...
}

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
	FILE* fp = fopen("student.data", "w");
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