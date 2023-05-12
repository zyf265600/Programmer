#define _CRT_SECURE_NO_WARNINGS 1

// strncat ʵ��

#include<stdio.h>
#include<assert.h>

char* MyStrncat(char* dest, const char* src, int count);

int main(void) {

	char dest[100];
	char src[50];
	int count = 0;

	printf("Enter string dest: ");
	scanf("%s", dest);
	printf("Enter string src: ");
	scanf("%s", src);
	printf("Enter number of character(s) copy  from src to dest: ");
	scanf("%d", &count);

	MyStrncat(dest, src, count);
	
	printf("%s\n", dest);

	return 0;
}

// ��ʵ�Ҿ�����ȡʵ�ֳ����粻д������д��������һ�鶼��һ��Ƭһ��Ƭ�ģ�
// էһ���о��ǶԵģ������Լ���һ�룬���Ǻ�Σ�յ�д����������Ҳ���Թ����
// C���Ա�����﷨���ã�������ʵ�����ǵ�ˮƷ��û�����ˣ������벻�����õ�д����
// ���Ǹ���ûѧ�� C�����������ĺ����� C �Ĵ�ʼ��д�����İ����ƺ�����Ϊ������һЩ�ӿڡ�

// ����������˵һ��������д����ʲô©�������ȣ����ǿ�һ�� cppreference �ϸ��Ķ��壺

//������ src ��ָ����ַ���������� count ���ַ����� dest ��ָ��Ŀ���ֹ�ֽ��ַ�����ĩβ��
//���ҵ����ַ���ֹͣ���ַ� src[0] �滻λ�� dest ĩβ�Ŀ���ֹ����
//ʼ�պ���ֹ���ַ���ĩβ���ʺ�����д�������ֽ����� count + 1 ����

//��Ŀ������û�ж��� dest �� src ���� count ���ַ�������ֹ���ַ����㹻�ռ䣬
//����Ϊδ���塣��Դ��Ŀ������ص�������Ϊδ���塣�� dest ����ָ�����ֹ�ֽ��ַ�����ָ�룬
//�� src ����ָ���ַ������ָ�룬����Ϊδ���塣

// ��������˵һ������Ϊ���������ܴ��ڵ�����:
// 1.dest ����������� count ���ַ��Ƿ���������Խ�磿
// 2.dest ������û�� '\0' ��û�м�⡣���û�У�����п������Խ�磬���ҽ���ɷǷ��ڴ���ʺ͸�д��
// 3.��� src û�� '\0' �� count �ִ��� src�ַ��������������ݵĴ�С������ src�ַ����鱾��Ĵ�С��
//   ��ʱҲ����ɷǷ��ڴ���ʡ�
// 4.src �ǲ���ָ���ַ������ָ�룿

// ����������⻶ӭ���䣬������и��õĽⷨ��C���ԣ���ӭ�����ң��һ���������֪�Ƽ�����˽���Ҽ��ɣ� 

char* MyStrncat(char* dest, const char* src, int count) {

	assert(dest && src);
	
	char* NewStr = dest;

	// ѭ������ NewStr ָ�� dest �ַ��� '\0' ����λ�� 
	while (*NewStr != '\0') {
		++NewStr;
	}
	while (count-- && (*NewStr++ = *src++));

	*NewStr = '\0';

	return dest;
}

