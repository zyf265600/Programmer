#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *newHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *res = newHead;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            newHead->next = list1;
            list1 = list1->next;
        }
        else if (list1->val > list2->val)
        {
            newHead->next = list2;
            list2 = list2->next;
        }
        else
        {
            newHead->next = list2;
            list2 = list2->next;
            newHead = newHead->next;
            newHead->next = list1;
            list1 = list1->next;
        }
        newHead = newHead->next;
    }

    while (list1 != NULL)
    {
        newHead->next = list1;
        list1 = list1->next;
        newHead = newHead->next;
    }
    while (list2 != NULL)
    {
        newHead->next = list2;
        list2 = list2->next;
        newHead = newHead->next;
    }

    return res->next;
}

// 第二种方法
struct ListNode *mergeTwoLists2(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *prehead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *prev = prehead;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            prev->next = list1;
            list1 = list1->next;
        }
        else
        {
            prev->next = list2;
            list2 = list2->next;
        }
        prev = prev->next;
    }

    prev->next = list1 == NULL ? list2 : list1;
    return prehead->next;
}

int main()
{
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    printf("create list: \t\n");

    int a[] = {1, 2, 4};
    int b[] = {1, 3, 4};
    list1 = initLink(a, 3);
    list2 = initLink(b, 3);

    struct ListNode *list3 = mergeTwoLists(list1, list2);

    printList(list3);
    return 0;
}