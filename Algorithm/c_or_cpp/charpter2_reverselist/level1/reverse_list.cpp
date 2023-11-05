#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../list_node.cpp"

/**
 * 带虚拟头结点的链表反转
*/
struct ListNode *reverseList(struct ListNode *head)
{

    struct ListNode *ans = (struct ListNode *)malloc(sizeof(struct ListNode));
    ans->next = NULL;
    struct ListNode *cur = head;

    while (cur != NULL)
    {
        struct ListNode *next = cur->next;
        cur->next = ans->next;
        ans->next = cur;
        cur = next;
    }

    return ans->next;
}

/**
 * 不带虚拟头结点的链表反转
*/
struct ListNode* reverseList(struct ListNode* head){
    struct  ListNode* prev = NULL;
    struct  ListNode* curr = head;

    while (curr != NULL) {
       struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

/**
 * 通过递归方式实现链表反转
*/
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

   struct ListNode* newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    struct ListNode *p = NULL;
    printf("create list: \t\n");

    int a[] = {1, 2, 3, 4};
    p = initLink(a, 4);
    struct ListNode *q = reverseList(p);
    printList(q);

    return 0;
}