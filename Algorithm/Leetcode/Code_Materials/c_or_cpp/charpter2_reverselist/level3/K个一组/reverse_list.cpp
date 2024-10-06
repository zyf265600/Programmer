#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    struct ListNode *dummyNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummyNode->next = head;
    struct ListNode *cur = head;
    int len = 0;
    while (cur != NULL)
    {
        len++;
        cur = cur->next;
    }
    int n = len / k;
    struct ListNode *pre = dummyNode;
    cur = head;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            struct ListNode *next = cur->next;
            cur->next = cur->next->next;
            next->next = pre->next;
            pre->next = next;
        }
        pre = cur;
        cur = cur->next;
    }
    return dummyNode->next;
}

int main()
{
    struct ListNode *list1 = NULL;
    int a[] = {1, 2, 3, 4, 5};
    list1 = initLink(a, 5);

    struct ListNode *q = reverseKGroup(list1, 2);
    printList(q);

    return 0;
}