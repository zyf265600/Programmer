#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct PersonInfo {
	char name[100];
	char phone[100];
}PersonInfo;

typedef struct AddressBook {
	PersonInfo* all_address;
	int size;
	int capacity;
}AddressBook;
// size �ĺ����ǣ�
// ���� all_address �±귶Χ�� [0,size) �ڵ�Ԫ�����������
//                            [size, 200) ������û���õ���
// capacity ���õĿռ��С 


int Menu(void);

void InitBook(AddressBook* address_book);

void AddPersonInfo(AddressBook* address_book);

void DelPersonInfo(AddressBook* address_book);

void FindPersonInfo(AddressBook* address_book);

void ModifyPersonInfo(AddressBook* address_book);

void PrintPersonInfo(AddressBook* address_book);

void ClearPersonInfo(AddressBook* address_book);

void SortPersonInfo(AddressBook* address_book);

void DestoryBook(AddressBook* address_book);
