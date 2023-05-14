#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_REMIND 50
#define MSG_LEN 100


int read_line(char str[], int read_num);

int main(void) {
	
	char* reminders[MAX_REMIND]; // �����ʾ������ // change
	char day_str[3];//��ǰ����ת��Ϊ�ַ���
	char msg_str[MSG_LEN + 1]; //��ǰ�������ʾ��Ϣ
	int day, num_remind = 0; // ���ں͵�ǰ��ʾ��
	int i, j;


	for (;;) {

		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder:");

		scanf("%2d", &day); //ÿ�µ�����ֻ����������ʾ���ɣ�ֻ�� 2 ���ֶ�

		if (day == 0)
			break;

		sprintf(day_str, "%2d", day); // �� day �� "%2d" �ĸ�ʽд�� day_str �ַ������С�"%2d" ��֤С��10����ռ��λ�Ҷ���
		read_line(msg_str, MSG_LEN);
		

		// Ѱ�ҵ�ǰ�������ʾӦ�÷ŵ���ʾ������Ǹ�λ��
		for (i = 0; i < num_remind; i++) {
			// ˵����ǰ���������Ӧ�����ڴ���ǰ
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		}
		
		// ����ǰ�������ʾ���뵽��ȷ��λ��
		for (j = num_remind; j > i; j--) {
			reminders[j] = reminders[j - 1]; // change
		}

		reminders[i] = (char*)malloc(sizeof(msg_str) + sizeof(day_str) + 1); // change
		
		// change																	 
		if (reminders[i] == NULL) {
			printf("-- No space left --\n");
			break;
		}
	
		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);// �պý� day_str ���ƽ�ȥ�Ŀ��ַ����ǵ���

		num_remind++;
	}

	printf("Day Reminder: \n");
	for (i = 0; i < num_remind; i++)
		printf("%s\n", reminders[i]);


	return 0;
}


int read_line(char str[], int read_num) {

	int ch, count = 0;

	while ((ch = getchar()) != '\n') {
		if (count < read_num) {
			str[count++] = ch;
		}
	}

	str[count] = '\0';

	return count;
}
