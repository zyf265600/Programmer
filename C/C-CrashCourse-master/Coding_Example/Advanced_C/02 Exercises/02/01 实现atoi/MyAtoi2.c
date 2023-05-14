#define _CRT_SECURE_NO_WARNINGS 1

// ���� atoi ʵ�ֵ���һ���汾
// ��һ���汾��ʵ�Ϳ������ atoi ʵ���еĵط�����һ�µ�
// ����⺯�� atoi �����ַ��� "abc123", ���صĽ���� 0 ������һ����ʵ�ֵ� MyAtoi �᷵�� 123
//                            "+-123", ���صĽ���� 0�� ��MyAtoi �᷵�� -123
// ��ʵ�Ҿ����Ҷ� atoi ������ǿ�����
// ��������ҲӦ�ù淶һ�㣬�Ͼ��ǿ⺯��

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int MyAtoi_2(const char* str) {
	
	int flg = 1;
	int ret = 0;

	if (str == NULL || str == '\0') {
		return 0;
	}

	// �ж��Ƿ�Ϊ�հ��ַ����ո񣬻��У��Ʊ���ҳ ...��
	while (isspace(*str)) {
		str++;
	}

	// �ж��Ƿ�Ϊ������
	// �ÿ⺯�� atoi ��һ�¾�֪�� "+-123" �����ַ������޷�ת�����ֵģ���������һ��Ҫ�������� 
	// �������λ����һ���������֣��򷵻� 0 
	if (*str == '+' || *str == '-' ) {
		
		if (*(str + 1) == NULL) {
			return 0;
		}

		if (!isdigit(*(str + 1))) {
			return 0;
		}

		if (*str == '-') {
			flg = -1;
		}
		str++;
	}

	// ���������ַ�
	while (*str != '\0') {
		if (isdigit(*str)) {
			
			// �ж�һ�»᲻�ᳬ�� int �ķ�Χ
			if (((unsigned long)ret * 10 + (*str - '0')) > INT_MAX) {
				return INT_MAX;
			}
			ret = ret * 10 + (*str - '0');
			
			// �� MyAtoi �У���ѡ��������洢ÿһλ��Ȼ��Ӻ���ǰ���γ���ÿһλ��Ȩ��
			// ��������ֱ�Ӽ�һ����֮ǰ�ȳ��� 10 ��������Ϊ���
		}
		else {
			return 0;
		}
		str++;
	}

	return ret * flg;
}

int main(void) {

	char str[100];
	int ret;

	scanf("%s", str);

	ret = MyAtoi_2(str);
	
	printf("%d\n", ret);

	return 0;
}

