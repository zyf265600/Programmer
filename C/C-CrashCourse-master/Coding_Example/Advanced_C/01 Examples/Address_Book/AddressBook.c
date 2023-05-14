#include<stdio.h>
#include<string.h>

#define Max_SIZE 50 //����ͨѶ¼�Ĵ�С

typedef struct PersonInfo {
	char name[100];
	char phone[100];
}PersonInfo;

typedef struct AddressBook {
	PersonInfo all_address[Max_SIZE];
	int size;
}AddressBook;
//size �ĺ����ǣ�
//���� all_address �±귶Χ�� [0,size) �ڵ�Ԫ�����������
//                            [size, 200) ������û���õ���

//��ʼ��
void init(AddressBook* address_book) {
	
	address_book->size = 0;
	//�������� magic number(�������������)
	for (int i = 0; i < Max_SIZE; i++) {
		strcpy(address_book->all_address->name, " ");
		strcpy(address_book->all_address->phone, " ");
	}

}

int Menu(void) {
	
	printf("======================\n");
	printf("***     0.�˳�     ***\n");
	printf("***  1.������ϵ��  ***\n");
	printf("***  2.ɾ����ϵ��  ***\n");
	printf("***  3.������ϵ��  ***\n");
	printf("***  4.�޸���ϵ��  ***\n");
	printf("***  5.��ӡ��ϵ��  ***\n");
	printf("***  6.�����ϵ��  ***\n");
	printf("***  7.������ϵ��  ***\n");
	printf("======================\n");

	printf("���������ѡ��");
	int choice;
	scanf("%d", &choice);

	return choice;
}

void AddPersonInfo(AddressBook* address_book) {
	
	printf("������ϵ��\n");

	if (address_book->size >= Max_SIZE) {
		printf("ͨѶ¼���������������\n");
		return;
		//��Ȼ���������� void ����Ҳ�ǿ����� return ��
	}
	PersonInfo* info = &address_book->all_address[address_book->size];
	
	printf("��������ϵ��������");
	scanf("%s", info->name);
	printf("��������ϵ�˵绰��");
	scanf("%s", info->phone);

	address_book->size++;
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
		name_exist = FindName(address_book, search_name);
	}

	printf("ɾ���ɹ���\n");
	
}

int FindName(AddressBook* address_book, char search_name[100]) {
	
	for (int i = 0; i < address_book->size; i++) {
		//�ҵ����������±�
		if (strcmp(address_book->all_address->name, search_name) == 0) {
			return i;
		}
	}
	//û���ҵ������� -1
	return -1;
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
	

}

void ModifyPersonInfo(AddressBook* address_book) {
	
	char search_name[100] = { 0 };
	int isjump = 1;

	printf("ɾ����ϵ��\n");
	printf("��������ϵ��������");
	scanf("%s", search_name);

	int name_exist = FindName(address_book, search_name);

	if (name_exist == -1) {
		printf("����ϵ�˲����ڣ�\n");
		return;
	}
	
	//�Ż������û�������
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

}

void PrintPersonInfo(AddressBook* address_book) {
	
	PersonInfo* info;

	if (address_book->size == 0) {
		printf("��ǰû����ϵ�ˣ�\n");
		return;
	}

	printf("������ϵ����Ϣ���£�\n");
	
	for (int i = 0; i < address_book->size; i++) {
		info = &address_book->all_address[i];
		printf("[%2d]%4s  %s\n", i, info->name, info->phone);
	}
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
	}
	printf("�����ɣ�\n");
}

void SortPersonInfo(AddressBook* address_book) {

	printf("����ͨѶ¼\n");

	for (int i = 0; i < address_book->size - 1; i++) {
		for (int j = 0; j < address_book->size - 1 - i; j++) {
			PersonInfo* info = &address_book->all_address[j];
			PersonInfo* info_next = &address_book->all_address[j + 1];
			//�򵥵��� strcmp �������򣬲����������Ϊ�о��ǡ�δ���塱�ģ�
			//�����й��ɣ����ٶ����Իᷢ�ֺܶ������û�й��ɡ�
			//Ҳ���кܶ������Ѫ�ĺ��������磺strcoll,wcsscoll,wcscmp ��ЩֻҪ����Ū����������Ҳ�����á�
			//�������������õ�ʵ�ְ취�����Ⲣ����������������ص㡣
			if (strcmp(info->name, info_next) > 0) {
				PersonInfo tmp;
				tmp = *info;
				*info = *info_next;
				*info_next = tmp;
			}
		}
	}
	printf("����ɹ���\n");
}

int main(int argc, char* argv[]) {
	
	AddressBook address_book;
	
	//����һ������ָ������
	typedef void (*Func)(AddressBook*);
	Func func_table[] = {
		NULL,
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
	
	init(&address_book);

	
	while (1) {
		int choice = Menu();
		
		if (choice < 0 || choice > 7) {
			printf("�������\n");
			continue;
		}

		if (choice == 0) {
			printf("�ټ���\n");
			break;
		}
		
		func_table[choice](&address_book);

	}

	return 0;
}
