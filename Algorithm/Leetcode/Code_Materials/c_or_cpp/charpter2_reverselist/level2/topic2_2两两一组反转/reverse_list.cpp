#include<stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

  struct ListNode * swapPairs(struct ListNode * head)
{
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode *temp = dummyHead;

    while (temp->next != NULL && temp->next->next != NULL)
    {
        struct ListNode *node1 = temp->next;
        struct ListNode *node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }

    struct ListNode *newHead = dummyHead->next;
    free(dummyHead);
    return newHead;
}

int main()
{
    struct ListNode *p = NULL;
    printf("create list: \t\n");

    int a[] = {1, 2, 3, 4, 5};
    p = initLink(a, 5);
    struct ListNode *q = swapPairs(p);
    printList(q);

    return 0;
}