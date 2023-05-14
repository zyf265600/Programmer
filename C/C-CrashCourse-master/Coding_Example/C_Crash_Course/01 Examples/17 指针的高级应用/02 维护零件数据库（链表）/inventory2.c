#include<stdio.h>
#include<stdlib.h>
#include"readline.h"

#define NAME_LEN 20

typedef struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	struct part* next;
}part;


void menu();
part* find_part(part* head, int number);
void insert(part* head);
void search(part* head);
void update(part* head);
void print(part* head);


int main(void) {

	char code = 'a';
	part* head = (part*)malloc(sizeof(part));
	head->next = NULL;

	if (head == NULL) {
		printf("Database establish failed\n");
		exit(EXIT_SUCCESS);
	}

	menu();

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n') // skips to end of line
			;
		switch (code) {
		case 'i': insert(head); break;
		case 's': search(head); break;
		case 'u': update(head); break;
		case 'p': print(head); break;
		case 'q': return 0;
		default: printf("Illegal code.\n"); break;
		}
	}




	return 0;
}

void menu() {

	printf("                        ==================================\n");
	printf("                        *                                *\n");
	printf("                        *            i:  insert          *\n");
	printf("                        *            s:  search          *\n");
	printf("                        *            u:  undate          *\n");
	printf("                        *            p:  print           *\n");
	printf("                        *            q:  quit            *\n");
	printf("                        *                                *\n");
	printf("                        ==================================\n");
}


/**********************************************************
*
*	find_part: Looks up a part number in the inventory
*			   array.Returns the array index if the part
*			   number is found;otherwise,return -1
*
***********************************************************/
part* find_part(part* head, int number) {

	part* cur;

	// �����ǰ��ձ�����������
	for (cur = head->next; cur != NULL && cur->number > number;
		cur = cur->next)
		;
	
	if (cur == NULL)
		return NULL;

	if (cur->number == number)
		return cur;

}


/**********************************************************
*
*	insert: Inserts the part into the database.Prints
*		    an error message and returns prematurely
*			if the part already exists or the database
*			is full.
*
***********************************************************/
void insert(part* head) {

	int part_number;
	part* cur, * prev, *new_part;
	

	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	// Ѱ�� part_number ��Ӧ�����λ�ã�������Ҫ cur ������������Ӧ�ñ��� cur ǰ��Ľ�� prev 
	// �˳�ѭ��������cur == NULL ˵����ͷ���β��
	//				 cur->number > part_number ˵�� ����ı���ظ�
	//												Ӧ���� cur �� prev ֮������µ���� �� ͷ��
	for (cur = head->next, prev = NULL;cur != NULL && cur->number < part_number ;
		prev = cur, cur = cur->next)
		;
	
	// �ж�����ı���Ƿ������ݿ��е������ظ�
	if (cur != NULL && cur->number == part_number) {
		printf("Part already exists.\n");
		return;
	}

	// �����½��
	new_part = (part*)malloc(sizeof(part));

	// �ж������Ƿ�ɹ�
	if (new_part == NULL) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	
	new_part->number = part_number;
	printf("Enter part name: ");
	read_line(new_part->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_part->on_hand);
	
	// ����ķ�ʽ��
	// ����Ϊ��ʱ���� head ���в�����prev == NULL, cur == NULL��
	// ����Ϊ�գ�
	//			  ͷ�壺�� head ���� (prev == NULL, cur != NULL)
	//			  β�壺�� prev ���� (prev != NULL, cur == NULL)
	//			  ��ͨλ�ò��룺�� prev ����(prev,cur ����Ϊ NULL)
	new_part->next = cur;

	if (prev == NULL)
		head->next = new_part;
	else
		prev->next = new_part;

}


/************************************************************
*
*	search: Look up a part by the number user enters.
*			If the part exists, prints the name and quantity
*			on hand;if not, print an error message.
*
************************************************************/
void search(part* head) {

	int number;
	part* trg;

	printf("Enter part number: ");
	scanf("%d", &number);

	trg = find_part(head, number);

	if (trg == NULL) {
		printf("Part not found.\n");
		return;
	}

	printf("Part name: %s\n", trg->name);
	printf("Quantity on hand: %d\n", trg->on_hand);

}


/************************************************************
*
*	update: Prompts user to enter a number.
*			Print an error message if the part doesn't exist;
*			otherwise,prompts the user to enter change in
*			quantity on hand and updates the database.
*
************************************************************/

void update(part* head) {

	int number, change;
	part* trg;

	printf("Enter part number: ");
	scanf("%d", &number);

	trg = find_part(head, number);

	if (trg == NULL) {
		printf("Part not found.\n");
		return;
	}

	printf("Enter change in quantity on hand(- means minus): ");
	scanf("%d", &change);
	trg->on_hand += change;

}


/************************************************************
*
*	print: Print a listing of all parts in the database,
*		   showing the part number,part name and quantity
*		   on hand.Parts are printed in the order in which
*		   they were entered into the database.
*
************************************************************/

void print(part* head) {


	printf("Part Number      Part Name      Quantity on Hand\n");
	for (part* cur = head->next; cur != NULL; cur = cur->next) {
		printf("%6d%20s%15d\n", cur->number, cur->name, cur->on_hand);
	}
}
