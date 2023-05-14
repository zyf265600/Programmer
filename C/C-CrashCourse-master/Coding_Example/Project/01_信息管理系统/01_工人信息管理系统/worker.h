#ifndef _WORKER_H_
#define _WORKER_H_

#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define WORKER_MAX 20

typedef struct workers
{
	char jobNo[15];			     //ְ����
	char name[15];				 //����
	char gender[15];			 //�Ա�
	char position[15];			 //ְ�� 
	char tel[15];				 //�绰 

}struct_worker;

int worker_cnt;

void input_workers();
void list_workers();
void append_workers();
void sort_workers();
void inquiry_worker();
void delete_worker();


#endif 