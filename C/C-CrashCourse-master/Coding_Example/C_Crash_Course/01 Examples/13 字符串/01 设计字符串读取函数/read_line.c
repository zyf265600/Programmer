int read_line(char str[], int read_num) {
	
	int ch, i = 0;

	while ((ch = getchar()) != '\n' && ch != EOF) {
		// i ���� read_num ��ִ�в���������������ַ� 
		if (i < read_num)
			str[i++] = ch;
	}
    
	str[i] = '\0';
	
	return i;
}

// ch �������� int ������ char ��ֻ����Ϊ getchar ����������ַ���Ϊ int ���͵�ֵ���ء� 
