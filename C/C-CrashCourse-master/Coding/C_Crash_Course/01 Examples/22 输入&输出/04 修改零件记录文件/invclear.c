#include<stdio.h>
#include<stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
}inventory[MAX_PARTS];

int num_part;

int main() {

	FILE* fp;
	int i;

	if ((fp = fopen("inventory.dat", "rb+")) == NULL) {
		fprintf(stderr, "Can't open inventory file.\n");
		exit(EXIT_FAILURE);
	}

	num_part = fread(inventory, sizeof(struct part), MAX_PARTS, fp);

	for (i = 0; i < num_part; i++)
		inventory[i].on_hand = 0;

	rewind(fp);
	// ������� rewind �����Ǻܹؼ��ġ��ڵ����� fread ����֮���ļ�λ�������ļ���ĩβ����������� rewind �͵��� fwrite ����ô fwrite �������ļ�ĩβ��������ݣ������Ḳ�Ǿ����ݡ�
	fwrite(inventory, sizeof(struct part), num_part, fp);

	fclose(fp);
	
	return 0;
}
