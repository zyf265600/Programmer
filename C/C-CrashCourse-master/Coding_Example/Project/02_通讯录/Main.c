#define _CRT_SECURE_NO_WARNINGS

#include"AddressBook.h"

int main(int argc, char* argv[]) {

	AddressBook address_book;

	//����һ������ָ������
	typedef void (*Func)(AddressBook*);
	Func func_table[] = {
		DestoryBook,
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		ModifyPersonInfo,
		PrintPersonInfo,
		ClearPersonInfo,
		SortPersonInfo,
	};
	//������Ҳ������ô����
	//����һ���������ͣ�
	//typedef void (Func)(AddressBook*);
	//�����õ���ָ�����飬�������ͱ�����ָ�����ͣ�����Ӧ�ü��� * 
	//Func* func_table[] = {
	//NULL,
	//AddPersonInfo,
	//DelPersonInfo,
	//FindPersonInfo,
	//ModifyPersonInfo,
	//PrintPersonInfo,
	//ClearPersonInfo,
	//SortPersonInfo,
	//}; 

	InitBook(&address_book);
	

	while (1) {
		system("cls");
		int choice = Menu();

		if (choice < 0 || choice > 7) {
			printf("�������\n");
			continue;
		}

		func_table[choice](&address_book);

		if (choice == 0) {
			printf("\n �ټ���\n");
			break;
		}
	}

	return 0;
}
