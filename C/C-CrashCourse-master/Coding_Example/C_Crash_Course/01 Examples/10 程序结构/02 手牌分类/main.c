/*
 * �����ѵ�˼·��
 *				1��Ϊ���ж����е����Ƿ��ظ���������Ҫһ��������������洢�����ƣ���ʼ����������Ϊ false�����һ�����Ѿ����������ϣ���ô���ǽ������Ӧ��Ԫ����Ϊ true
 *				2���������ֱ��������洢ÿ�������ͻ�ɫ�ĸ����������������Ǻ����ж��Ƶ�����
 *				3��8 ���Ƶ����ͣ����ǿɲ�� ͬ����˳�ӣ�4�ţ�3�ţ����ӣ�ֵΪ 0��1��2�������ֻ������͵���ϡ�
 *
 * ����ṹ��
 *			ͨ������ķ��������Ƿ��֣����������Ҫ 3 ������� 5 ���������������Ϊ�����������Σ��Ե���Щ����
 *			���ң�ǰ������˵��������ֻ�ܷ���һ��ֵ�������Ҫ���������룬 5 �ֻ������;͵÷Ž����飻����ʹ��ָ�룬��ָ������û��ѧϰ������ָ�뻹���Ӳ�������
 *			����һ������ò��ʹ��ȫ�ֱ�������õ������ˡ����ڳ�ѧ����˵����������ȷʵ����õġ�
 *			���ǣ�ʹ�ô�����ȫ�ֱ����Ǻܲ��õ�ϰ�ߣ��Ҳ������Լ�ȥд�����Ĵ��롣����Ϊ����������ⲻ����Ҳ�����л��Ĵ�����ȥд��
 *			�������ǻ�ѧϰ�Զ������ͣ��ṹ�壬������������������õĽ��������
 *			
 *			�������������� 4 �ֽ��������
 *			1)Ӧ��ȫ�ֱ���
 *			2��Ӧ��ָ����Ϊ��������
 *			3�����жϿ������͵ĺ������ӡ�����ϲ�
 *			4��ʹ�ýṹ��
 *
 *			������Ҽ��ʹ�ýṹ��������������⡣ȫ�ֱ������ֻҪ֪������ɣ������������˵�����𷽷���������Ƴ����ģ�黯˼·��ֵ��ѧϰ��
 *			��ʹʹ�ýṹ�壬�������Ҫ�߼�Ҳ����䡣������Ҫ��ȫ�ֱ���д��������Ը�дһ�¡�
 */

#include<stdio.h>
#include<stdbool.h>

#define RANK 13
#define SUIT 4
#define CARD 5

typedef struct CardType {
	bool flush; //ͬ��
	bool straight; //˳��
	bool four; //����
	bool three; //����
	int pair; // ����
	// 0 ��ʾ���� 1 ��ʾ 1������ 2 ��ʾ��������
	bool cardInHand[SUIT][RANK]; // �жϴ����Ƿ���������
	int numRank[RANK]; // ÿ�������ĸ���
	int numSuit[SUIT]; // ÿ����ɫ�ĸ���
}CardType;


void initCardType(CardType* card); // ��ʼ��
void readCard(CardType* card); // ��ȡ����
void analyseCard(CardType* card); // ��������
void printResult(CardType* card); //��ӡ���

int main(void) {

	CardType card;
	
	for (; ;) {
		initCardType(&card);
		readCard(&card);
		analyseCard(&card);
		printResult(&card);
	}

	return 0;
}


void initCardType(CardType* card) {

	card->flush = false;
	card->straight = false;
	card->four = false;
	card->three = false;
	card->pair = 0;

	int i, j;

	for (i = 0; i < SUIT; i++) {
		card->numSuit[i] = 0;
		for (j = 0; j < RANK; j++) {
			card->cardInHand[i][j] = false;
		}
	}

	for (i = 0; i < RANK; i++) {
		card->numRank[i] = 0;
	}

}


void readCard(CardType* card) {

	int card_read = CARD, rank, suit;
	bool bad_card;
	char ch;

	while (card_read) {
		
		bad_card = false; // ��Ҫ�������û��Ƶı��

		printf("Enter a card : ");
		
		// �жϵ���
		ch = getchar();
		switch (ch) {
			case '0':			exit(0); break;
			case '2':		   rank = 0; break;
			case '3':		   rank = 1; break;
			case '4':		   rank = 2; break;
			case '5':		   rank = 3; break;
			case '6':		   rank = 4; break;
			case '7':		   rank = 5; break;
			case '8':		   rank = 6; break;
			case '9':		   rank = 7; break;
			case 't':case 'T': rank = 8; break;
			case 'j':case 'J': rank = 9; break;
			case 'q':case 'Q': rank = 10; break;
			case 'k':case 'K': rank = 11; break;
			case 'a':case 'A': rank = 12; break;
			default:bad_card = true; break;
		}

		ch = getchar();
		switch (ch) {
			case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default: bad_card = true; break;
		}
		
		// ������ ���� 1 
		// ��������Ƿ���������ַ�
		while ((ch = getchar()) != '\n') {
			if (ch != ' ')
				bad_card = true;
		}

		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (card->cardInHand[suit][rank])
			printf("Duplicated card; ignored.\n");
		else {
			++card->numRank[rank];
			++card->numSuit[suit];
			card->cardInHand[suit][rank] = true;
			card_read--;
		}
	}
}

void analyseCard(CardType* card) {

	int i, count;

	// ͬ������������ͬ��ɫ
	for (i = 0; i < SUIT; i++) {
		if (card->numSuit[i] == 5)
			card->flush = true;
	}
	
	// ������ ���� 2 
	// ˳���������������ƣ��м䲻�ܸ���
	
	i = 0;
	// �ҵ������ֵ�һ�Ŵ��ڵ���
	while (card->numRank[i] == 0)
		i++;
	count = 0;
	for (; i < RANK && card->numRank[i] != 0; i++) {
		count++;
	}
	// ˳�ӱ���������
	if (count == CARD) {
		card->straight = true;
		return; // ˳�ӿ϶����Ƕ���
	}

	for (i = 0; i < RANK; i++) {
		if (card->numRank[i] == 4)
			card->four = true;
		if (card->numRank[i] == 3)
			card->three = true;
		if (card->numRank[i] == 2)
			++card->pair;
	}
	
}

void printResult(CardType* card) {

	if (card->flush && card->straight)
		printf("Stright flush\n");
	else if (card->four)
		printf("Four of a kind\n");
	else if (card->three && card->pair == 1)
		printf("Full house\n");
	else if (card->flush)
		printf("flush\n");
	else if (card->straight)
		printf("straight\n");
	else if (card->three)
		printf("Three of a kind\n");
	else if (card->pair == 2)
		printf("Two pairs\n");
	else if (card->pair == 1)
		printf("pair\n");
	else
		printf("High card\n");
	
	printf("\n\n");
}
