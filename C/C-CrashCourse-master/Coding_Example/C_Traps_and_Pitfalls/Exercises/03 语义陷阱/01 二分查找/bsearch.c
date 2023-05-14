#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ���鷨�����ԳƱ߽磩
int* bsearch(int* arr, int n, int key) {
	
	//���ڲ��ԳƱ߽���˵��mid ��ȡֵΪ lo <= mid < hi
	int lo = 0;
	int hi = n;

	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (arr[mid] > key)
			hi = mid;
		else if (arr[mid] < key)
			lo = mid + 1;
		else
			return arr + mid;
	}

	return NULL;
}

// ָ�뷨�����ԳƱ߽磩
int* bsearch(int* arr, int n, int key) {

	int* lo = arr;
	int* hi = arr + n;

	while (lo < hi) {
		int* mid = lo + ((hi - lo)>>2); //ָ��ļӷ���û�������
		if (*mid > key)
			hi = mid;
		else if (*mid < key)
			lo = mid + 1;
		else
			return mid;
	}

	return NULL;
}

// ���鷨���ԳƱ߽磩
int* bsearch(int* arr, int n, int key) {

	//���ڶԳƱ߽���˵��mid ��ȡֵΪ lo <= mid <= hi
	int lo = 0;
	int hi = n - 1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (arr[mid] > key)
			hi = mid + 1;
		else if (arr[mid] < key)
			lo = mid + 1;
		else
			return arr + mid;
	}

	return NULL;
}
