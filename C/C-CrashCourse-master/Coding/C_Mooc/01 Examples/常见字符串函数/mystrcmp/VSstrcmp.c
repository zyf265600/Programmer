//�����������ĸ�ʽ
int mystrcmp(char* str1, char* str2) {

	int ret = 0;

	while ((ret = ((unsigned char)*str1 - (unsigned char)*str2)) == 0 && *str1) {
		++str1, ++str2;
	}

	return ret;
}


//ԭ��������
int __cdecl strcmp(
	const char* src,
	const char* dst
)
{
	int ret = 0;

	while ((ret = *(unsigned char*)src - *(unsigned char*)dst) == 0 && *dst)
	{
		++src, ++dst;
	}
	
	//���ﲻ̫��⣬�Ǹ���������˿��Ը��ҽ�һ�£�лл
	return ((-ret) < 0) - (ret < 0); // (if positive) - (if negative) generates branchless code
}