#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include"line.h"

#define MAX_LINE_LEN 60 // ÿ�е�����ַ���

char line[MAX_LINE_LEN + 1]; 
int line_len = 0; // ��ǰ�г���
int num_words = 0; // ��ǰ�еĵ�����

void clear_line() {
	
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char* word) {

	// ���׸�����,��Ҫ����һ�����ʺ���ӿո�
	if (num_words > 0) {
		line[line_len] = ' ';
		line[line_len + 1] = '\0';
		line_len++;
	}

	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining() {
	
	return MAX_LINE_LEN - line_len;
}


void write_line() {

	int extra_space, spaces_to_insert, i, j;

	extra_space = MAX_LINE_LEN - line_len; // ��ǰ��δ���������ַ���
	for (i = 0; i < line_len; i++) {
		if (line[i] != ' ')
			putchar(line[i]);
		else {
			spaces_to_insert = extra_space / num_words; // ��ѭ�����ʽ�����ӿո�
			for (j = 0; j <= spaces_to_insert; j++) // ʹ�� = ȷ�����ٴ�ӡһ��
				putchar(' ');
			extra_space -= spaces_to_insert;
			num_words--;
		}
	}
	putchar('\n');
}

void flush_line(void) {

	if (line_len > 0)
		puts(line);
}
