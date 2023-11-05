#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

/**
 *
 *  头插法
 */
struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    struct ListNode *dummyNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummyNode->next = head;
    struct ListNode *pre = dummyNode;

    for (int i = 0; i < left - 1; i++)
    {
        pre = pre->next;
    }

    struct ListNode *cur = pre->next;
    struct ListNode *next;

    for (int i = 0; i < right - left; i++)
    {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }

    struct ListNode *newHead = dummyNode->next;
    free(dummyNode);

    return newHead;
}

/**
 * 穿针引线法
 */

void reverseLinkedList(struct ListNode *head)
{
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    while (cur != NULL)
    {
        struct ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
}

struct ListNode *reverseBetween2(struct ListNode *head, int left, int right)
{
    struct ListNode *dummyNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummyNode->next = head;
    struct ListNode *pre = dummyNode;

    for (int i = 0; i < left - 1; i++)
    {
        pre = pre->next;
    }

    struct ListNode *rightNode = pre;
    for (int i = 0; i < right - left + 1; i++)
    {
        rightNode = rightNode->next;
    }

    struct ListNode *leftNode = pre->next;
    struct ListNode *succ = rightNode->next;

    pre->next = NULL;
    rightNode->next = NULL;

    reverseLinkedList(leftNode);

    pre->next = rightNode;
    leftNode->next = succ;

    return dummyNode->next;
}



int main()
{
    struct ListNode *p = NULL;
    printf("create list: \t\n");

    int a[] = {1, 2, 3, 4, 5};
    p = initLink(a, 5);
    struct ListNode *q = reverseBetween(p, 2, 4);
    printList(q);

    return 0;
}