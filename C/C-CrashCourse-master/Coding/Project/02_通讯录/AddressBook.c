#define _CRT_SECURE_NO_WARNINGS

#include"AddressBook.h"

#define PRIVATE static

PRIVATE int FindName(AddressBook* address_book, char search_name[100]) {

	for (int i = 0; i < address_book->size; i++) {
		// �ҵ����������±�
		// ע�� all_address[i] �ĳ�Ա���ʷ�ʽΪ . ������ ->
		if (strcmp(address_book->all_address[i].name, search_name) == 0) {
			return i;
		}
	}
	//û���ҵ������� -1
	return -1;
}

// ����
PRIVATE void ReallocBook(AddressBook* address_book){
	// ��ʼ capacity Ϊ 1����������
	int newSize = address_book->capacity == 0 ? 1 : 2 * address_book->capacity;
	
	PersonInfo* newAddress = realloc(address_book->all_address, newSize * sizeof(PersonInfo));
	if (!newAddress){
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	// ����
	address_book->all_address = newAddress;
	address_book->capacity = newSize;
}

// ���ļ���ȡ���ݵ���������
PRIVATE void LoadBook(AddressBook* address_book){
	FILE* fp = fopen("address_book.txt", "r");
	
	if (fp == NULL){
		strerror(errno);
		exit(EXIT_FAILURE);
	}

	// �򻺳�����ȡ����Ϊ��֪���ļ����ж���ѧ����Ϣ���������ǲ���һ���Զ���
	// ʹ�� while ѭ�������ظ���ȡ����ѧ����Ϣ
	while (1) {
		if (address_book->size == address_book->capacity) {
			ReallocBook(address_book);
		}
		PersonInfo tmp = {0};
		int n = fread(&tmp, sizeof(PersonInfo), 1, fp);
		// ��ȡ���
		if (n < 1) {
			break;
		}
		// �� tmp ���뻺���������ҽ� size �� 1
		address_book->all_address[address_book->size++] = tmp;
	}
	printf("�ļ������룡\n");
	fclose(fp);
}

// ���滺���������ݵ��ļ���
PRIVATE void SaveBook(AddressBook* address_book) {
	FILE* fp = fopen("address_book.txt", "w");
	
	if (fp == NULL) {
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	// ���������ڵ���������д���ļ�
	int n = fwrite(address_book->all_address, sizeof(PersonInfo), address_book->size, fp);
	if (n != address_book->size) {
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	printf("�ļ��ѱ��棡\n");
	fclose(fp);
}


int Menu(void) {
	printf("\n\n\n\n\n\t\t\t\t\t\t AddressBook Management System\n");
	printf("\t\t\t\t\t\t     @author��Shepard Wang \n");
	printf("\t\t\t\t\t\033[0;42m ������ϸע���Լ���������ںţ������̵ĳ���Բ \033[0m \n");
	printf("\t\t\t\t\t\t    ======================\n");
	printf("\t\t\t\t\t\t    ***     0.�˳�     ***\n");
	printf("\t\t\t\t\t\t    ***  1.������ϵ��  ***\n");
	printf("\t\t\t\t\t\t    ***  2.ɾ����ϵ��  ***\n");
	printf("\t\t\t\t\t\t    ***  3.������ϵ��  ***\n");
	printf("\t\t\t\t\t\t    ***  4.�޸���ϵ��  ***\n");
	printf("\t\t\t\t\t\t    ***  5.��ӡ��ϵ��  ***\n");
	printf("\t\t\t\t\t\t    ***  6.�����ϵ��  ***\n");
	printf("\t\t\t\t\t\t    ***  7.������ϵ��  ***\n");
	printf("\t\t\t\t\t\t    ======================\n");

	printf("���������ѡ��");
	int choice;
	scanf("%d", &choice);

	return choice;
}

//��ʼ��
void InitBook(AddressBook* address_book) {

	address_book->size = 0;
	//�������� magic number(�������������)
	address_book->all_address = NULL;
	address_book->capacity = 0;

	// ��ʼ���û���������ļ���ȡ����
	LoadBook(address_book);
}

void AddPersonInfo(AddressBook* address_book) {
	
	printf("������ϵ��\n");

	if (address_book->size >= address_book->capacity) {
		ReallocBook(address_book);
	}

	PersonInfo* info = &address_book->all_address[address_book->size];
	
	printf("��������ϵ��������");
	scanf("%s", info->name);
	printf("��������ϵ�˵绰��");
	scanf("%s", info->phone);

	address_book->size++;

	system("pause");
}

void DelPersonInfo(AddressBook* address_book) {
	
	//ɾ���ķ����ܶ࣬���Ը����������绰����ŵȵ���ɾ����
	//�������Ǿ����Ҹ��˱Ƚϳ��õ� �������ֵ�ɾ������

	char search_name[100] = { 0 };

	printf("ɾ����ϵ��\n");
	printf("��������ϵ��������");
	scanf("%s", search_name);

	int name_exist = FindName(address_book, search_name);
	
	//����ע�� FindName ����ֵ�趨��Ҫ��ɾ����Ԫ���±������ 0����������»᷵�� 0 
	if (name_exist == -1) {
		printf("����ϵ�˲����ڣ�\n");
		system("pause");
		return;
	}

	//ɾ������ͬ�����ĵ�һ���󣬼���Ѱ�Ҹ����֣�����ҵ��ˣ��ظ�����Ĳ��������û�ҵ����˳�ѭ��
	//��ͬ������������Ƚϸ��ӣ����޸ģ����ң�����ȵȳ�����������鷳��
	//����ƽʱ���ͨѶ¼���ѵ��Ὣ������ͬ�������˵ı�עд��һ������
	//���ԣ��ҽ�����ɾ��������ʵ��һ�������ͬ��������������˼·���������������Ĭ��û���ظ������������
	while (name_exist != -1) {
		
		//�� all_address ��������һ��Ԫ�ظ�ֵ��Ҫɾ����Ԫ�أ����ɾ��
		//�ṹ�������ǿ���ֱ�Ӹ�ֵ��
		address_book->all_address[name_exist] = address_book->all_address[address_book->size - 1];
		address_book->size--;
		// ����Ѱ��ͬ����
		name_exist = FindName(address_book, search_name);
	}

	printf("ɾ���ɹ���\n");
	
	system("pause");
}


void FindPersonInfo(AddressBook* address_book) {

	char search_name[100] = { 0 };

	//�����˵ķ�ʽҲ�ܶ࣬�����������������ֵķ���
	printf("������ϵ��\n");
	printf("������������");
	scanf("%s", search_name);

	for (int i = 0; i < address_book->size; i++) {
		PersonInfo* info = &address_book->all_address[i];// ����һ�� PersonInfo ���͵ı����򻯳��򣬲�Ȼ������������ʾ�̫����
		if (strcmp(info->name, search_name) == 0) {
			printf("[%d] %s  %s\n", i, info->name, info->phone);
		}
	}
	
	system("pause");
}

void ModifyPersonInfo(AddressBook* address_book) {
	
	char search_name[100] = { 0 };
	int isjump = 1;

	printf("�޸���ϵ��\n");
	printf("��������ϵ��������");
	scanf("%s", search_name);

	int name_exist = FindName(address_book, search_name);

	if (name_exist == -1) {
		printf("����ϵ�˲����ڣ�\n");
		system("pause");
		return;
	}
	
	//�Ż��û�������
	printf("�������µ����������� 0 ������");
	scanf("%d", &isjump);
	if (isjump) {
		scanf("%s", address_book->all_address[name_exist].name);
	}
	printf("�������µĵ绰������ 0 ������");
	scanf("%d", &isjump);
	if (isjump) {
		scanf("%s", address_book->all_address[name_exist].phone);
	}

	printf("���³ɹ���\n");
	system("pause");
}

void PrintPersonInfo(AddressBook* address_book) {
	
	PersonInfo* info;

	if (address_book->size == 0) {
		printf("��ǰû����ϵ�ˣ�\n");
		system("pause");
		return;
	}

	printf("������ϵ����Ϣ���£�\n");
	
	for (int i = 0; i < address_book->size; i++) {
		info = &address_book->all_address[i];
		printf("[%03d]%4s  %s\n", i, info->name, info->phone);
	}

	system("pause");
}

void ClearPersonInfo(AddressBook* address_book) {
	
	//���������Ϣ��һ�� Σ�յ���Ϊ������������û�ȷ��һ��
	//�����Ӧ�����Լ����ֻ��ϻظ����������ã�ϵͳӦ�û�����ȷ�ϲ�ֹһ�Σ�
	int is_continue = 0;

	printf("���������ϵ�ˣ���ȷ�������� 0 ����: ");
	scanf("%d", &is_continue);
	if(is_continue == 0) {
		//�� size ��Ϊ 0 ���ɣ�������Ҳ���Խ������ÿ��Ԫ�ض���������
		address_book->size = 0;
		printf("�����ɣ�\n");
	}
	printf("��ȡ����\n");
	
	system("pause");
}

void SortPersonInfo(AddressBook* address_book) {

	printf("����ͨѶ¼\n");

	for (int i = 0; i < address_book->size - 1; i++) {
		for (int j = 0; j < address_book->size - 1 - i; j++) {
			PersonInfo* info = &address_book->all_address[j];
			PersonInfo* info_next = &address_book->all_address[j + 1];
			//�򵥵��� strcmp �������򣬲����������Ϊ�о��ǡ�δ���塱�ģ�
			//�����й��ɣ����ٶ����Իᷢ�ֺܶ������û�й��ɡ�
			//Ҳ���кܶ��������ĺ��������磺strcoll,wcsscoll,wcscmp ��ЩֻҪ����Ū����������Ҳ�����á�
			//�������������õ�ʵ�ְ취�����Ⲣ����������������ص㡣
			if (strcmp(info->name, info_next->name) > 0) {
				PersonInfo tmp;
				tmp = *info;
				*info = *info_next;
				*info_next = tmp;
			}
		}
	}
	printf("����ɹ���\n");

	system("pause");
}

void DestoryBook(AddressBook* address_book) {

	// ��Ҫ�˳�����ʱ���������ڵ�����д���ļ���
	SaveBook(address_book);

	free(address_book->all_address);
	address_book->all_address = NULL;
	address_book->capacity = address_book->size = 0;
}

