#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include"word.h"
#include"line.h"

#define MAX_WORD_LEN 20  //ÿ�����ʵ���󳤶�

int main(void) {

	char word[MAX_WORD_LEN + 2];
	int word_len;

	clear_line();
	for (;;) {
		// ���� read_word ������� 1 ���ַ������������ʳ��ȳ��� 20����Ҫ�ض�
		read_word(word, MAX_WORD_LEN + 1);
		word_len = strlen(word);
		if (word_len == 0) {
			flush_line();
			return 0;
		}
		// �ضϳ��� 20 ���ַ��ĵ���
		if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
		// + 1 ����Ϊ��Ҫ����һ�����ʺ���ӿո�
		// �����������������Ҫ�����ǰ�в���յ�ǰ��
		if (word_len + 1 > space_remaining()) {
			write_line();
			clear_line();
		}
		add_word(word);
	}

	return 0;
}
