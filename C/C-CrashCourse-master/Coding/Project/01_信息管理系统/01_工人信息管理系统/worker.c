#define _CRT_SECURE_NO_WARNINGS

#include"worker.h"

// ���������ַ�������
static void swap(char* str1, char* str2)
{
	char tmp[15];
	strcpy(tmp, str1);
	strcpy(str1, str2);
	strcpy(str2, tmp);
}

/*���뺯������ɽ����������ְ������д�����*/
void input_workers()
{
	int i;
	struct_worker worker;			
	FILE* fp;

	system("cls");/*����*/

	if ((fp = fopen("d:\\file1.txt", "wb")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\n\t������ְ������:");
	scanf("%d", &worker_cnt); /*����ְ������*/
	for (i = 0; i < worker_cnt; i++)		
	{
		printf("\n\t�������%d��ְ����Ϣ:\n", i + 1);
		printf("\tְ����:");
		scanf("%s", worker.jobNo);
		printf("\t����:");
		scanf("%s", worker.name);
		printf("\t�Ա�:");
		scanf("%s", worker.gender);
		printf("\tְ��:");
		scanf("%s", worker.position);
		printf("\t�绰:");
		scanf("%s", worker.tel);

		fwrite(&worker, sizeof(struct_worker), 1, fp);
	}
	fclose(fp);

	printf("\n\tpress any key to continue...");
	getchar();
	getchar();
}


/*��ʾ��������ɽ��ļ��е�ְ��������ʾ����Ļ��*/
void list_workers(){							
	struct_worker worker;			
	FILE* fp;
	int cnt = worker_cnt;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "rb")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\n\n\n\tְ����\t����\t�Ա�\tְ��\t�绰\n\n");
	
	while (cnt-- && (fread(&worker, sizeof(struct_worker), 1, fp) != 0))
		printf("\t%s  \t%s \t%s \t%s \t%s\n", worker.jobNo, worker.name, worker.gender, worker.position, worker.tel);
	
	fclose(fp);
	printf("\n\tpress any key to continue...");
	getchar(); // �������� 2 �����µĻس�
	getchar();
}


/*׷�Ӻ�������ɽ������������ְ������׷�ӵ��ļ���*/
void append_workers()			
{
	int i, cnt;
	struct_worker worker;
	FILE* fp;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "ab")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\t������׷������:");
	scanf("%d", &cnt);
	
	for (i = 0; i < cnt; i++)
	{
		printf("\n\tְ����:");
		scanf("%s", worker.jobNo);
		printf("\t����:");
		scanf("%s", worker.name);
		printf("\t�Ա�:");
		scanf("%s", worker.gender);
		printf("\tְ��:");
		scanf("%s", worker.position);
		printf("\t�绰:");
		scanf("%s", worker.tel);

		fwrite(&worker, sizeof(struct_worker), 1, fp);
	}
	
	worker_cnt += cnt;
	fclose(fp);

	printf("\n\tappend success! press any key to continue...");
	getchar(); 
	getchar();
}


/*����������ɶ��ļ��е�ְ�����ݰ�ְ����������ʾ����Ļ��*/
void sort_workers(){
	int i, j;
	struct_worker workers[WORKER_MAX];	
	struct_worker tmp;
	FILE* fp;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "rb+")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	if (fread(workers, sizeof(struct_worker), worker_cnt, fp) != worker_cnt)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < worker_cnt - 1; i++)
	{
		for (j = i; j < worker_cnt - 1 - i; j++)
		{
			
			if (strcmp(workers[j].jobNo, workers[j + 1].jobNo) > 0)
			{
				swap(workers[j].jobNo, workers[j + 1].jobNo);
				swap(workers[j].gender, workers[j + 1].gender);
				swap(workers[j].name, workers[j + 1].name);
				swap(workers[j].position, workers[j + 1].position);
				swap(workers[j].tel, workers[j + 1].tel);
			}
		}
	}
	
	
	fseek(fp, 0L, SEEK_SET); // ���ļ�ָ�������ļ�ͷ�����¿�ʼд
	fwrite(workers, sizeof(struct_worker), worker_cnt, fp);

	printf("\n\n\n\t��ְ������:\n");
	printf("\n\tְ����\t����\t�Ա�\tְ��\t�绰\n\n");
	for (i = 0; i < worker_cnt; i++)
		printf("\t%s\t%s\t%s\t%s\t%s\n", workers[i].jobNo, workers[i].name, workers[i].gender, workers[i].position, workers[i].tel);
	
	fclose(fp);
	printf("\n\tpress any key to continue...");
	getchar();		
	getchar();
}


/*��ѯְ�� */
void inquiry_worker()         
{	
	int flg = 0;
	struct_worker worker[WORKER_MAX];
	char tar_name[15];
	FILE* fp;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "rb")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\n\t������ְ����ְ����:");
	scanf("%s", tar_name);

	if (fread(worker, sizeof(struct_worker), worker_cnt, fp) != worker_cnt)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < worker_cnt; i++) {

		if (strcmp(tar_name, worker[i].name) == 0)
		{
			printf("\n\n\n\tְ����\t����\t�Ա�\tְ��\t�绰\n\n");
			printf("\t%s\t%s\t%s\t%s\t%s\n", worker[i].jobNo, worker[i].name, worker[i].gender, worker[i].position, worker[i].tel);
			flg = 1;
			break;
		}
	}

	if (flg == 0)
		printf("��ְ�������ڣ�");

	fclose(fp);

	printf("\n\tpress any key to continue...");
	getchar();
	getchar();
}


/*ɾ����������ɽ��ļ��е�ְ������ɾ��*/
void delete_worker()            
{
	int i, j, flg = 0;
	struct_worker workers[WORKER_MAX], del_jobNo[15];
	FILE* fp;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "rb+")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\n\n ������Ҫɾ��ְ����ְ����:  ");
	scanf("%s", del_jobNo);
	
	if (fread(workers, sizeof(struct_worker), worker_cnt, fp) != worker_cnt)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	
	for (i = 0; i < worker_cnt; i++)
		if (strcmp(workers[i].jobNo, del_jobNo) == 0)
		{
			flg = 1;
			break;
		}
			

	if (flg == 0)
		printf("��ְ�������ڣ�");
	else
	{
		for (j = i; j < worker_cnt - 1; j++) 
		{
			strcpy(workers[j].jobNo, workers[j + 1].jobNo);
			strcpy(workers[j].gender, workers[j + 1].gender);
			strcpy(workers[j].name, workers[j + 1].name);
			strcpy(workers[j].position, workers[j + 1].position);
			strcpy(workers[j].tel, workers[j + 1].tel);
		}
		worker_cnt--;

		fseek(fp, 0L, SEEK_SET);
		fwrite(workers, sizeof(struct_worker), worker_cnt, fp);

		printf("ɾ���ɹ���");
	}

	fclose(fp);
	getchar();
	getchar();
}


int main(void)			/*����������ɳ���˵�����ʾ���������ϸ�����*/
{
	int choice;
	do
	{
		system("cls");	/*����*/
		printf("\n\n\n\n\n\t\t\t\t\t Personnel File Management System\n");	/*��ʾ����˵�*/
		printf("\n\n\t\t\t\t\t*********************************\n\n");
		printf("\t\t\t\t\t\t1----����ְ����Ϣ\n");
		printf("\t\t\t\t\t\t2----��ʾְ����Ϣ\n");
		printf("\t\t\t\t\t\t3----׷��ְ����Ϣ\n");
		printf("\t\t\t\t\t\t4----����ְ����Ϣ\n");
		printf("\t\t\t\t\t\t5----��ѯְ����Ϣ\n");
		printf("\t\t\t\t\t\t6----ɾ��ְ����Ϣ\n");
		printf("\t\t\t\t\t\t0----�˳�\n");
		printf("\n\t\t\t\t\t*********************************\n");
		printf("\n\t\t\t��ѡ��:");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:	input_workers();    break;		/*�������뺯��*/
			case 2:	list_workers();		break;		/*������ʾ����*/
			case 3:	append_workers();   break;		/*����׷�Ӻ���*/
			case 4:	sort_workers();		break;		/*����������*/
			case 5:	inquiry_worker();	break;		/*���ò�ѯ����*/
			case 6:	delete_worker();	break;		/*����ɾ������*/
			case 0:	exit(0);						/*�������������*/
		}
	} while (choice != 0);
}


