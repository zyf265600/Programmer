#include<stdio.h>

int main(void) {

	double balance = 0; // ���
	double credit, debit;

	// �˵�����ʽ�����Լ���ƣ���������һ����������þ������ֽ��棬��Ҫ�᱾��ĩ��

	printf("**** ACME checkbook-balancing program ****\n");
	printf("     Comands:                             \n");
	printf("             0 = clear                    \n");
	printf("             1 = credit                   \n");
	printf("             2 = debit                    \n");
	printf("             3 = balance                  \n");
	printf("             4 = exit                     \n");

	// ��Ŀ���Ѿ��涨����Щ������ 0��1��2��3��4 ���棬��ʵ������������ switch
	// ��������� if else Ҳ��ȫ ok

	// ��ѭ�����û������ظ�ѡ��
	while (1) {
		int choice;
		printf("Enter command: ");
		scanf("%d", &choice);
		
		switch (choice) {
					
					// ����˻���һ�ֺܡ�Σ�ա��ľٶ����������û�ȷ��һ��

			case 0:	printf("Are you sure to clear your balance?\n");
					printf("1 = yes, 0 = no\n");
					int isClear;
					scanf("%d", &isClear);
					if (isClear == 1) {
						balance = 0;
						printf("clear successfully!\n");
					}					
					break;
			
			case 1: printf("Enter amount of credit: ");
					scanf("%lf", &credit);
					balance += credit;
					break;
			
			case 2: printf("Enter amount of debit : ");
					scanf("%lf", &debit);
					balance -= debit;
					break;

			case 3: printf("Current balance: %.2f\n", balance);
					break;
					
			case 4: printf("Are you sure to quit?\n");
					printf("1 = yes, 0 = no\n");
					int isQuit;
					scanf("%d", &isQuit);
					if (isQuit == 1) {
						printf("Goodbye~\n");
						return 0;
					}
					else {
						break;
					}
			default: printf("Illeagl option!\n");
					 break;
		}
	}
}

