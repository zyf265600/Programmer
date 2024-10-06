#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *st1 = NULL;
    struct ListNode *st2 = NULL;
    struct ListNode *curr1 = l1;
    struct ListNode *curr2 = l2;
    while (curr1 != NULL)
    {
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = curr1->val;
        new_node->next = st1;
        st1 = new_node;
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = curr2->val;
        new_node->next = st2;
        st2 = new_node;
        curr2 = curr2->next;
    }

    struct ListNode *new_head = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->val = -1;
    new_head->next = NULL;
    int carry = 0;

    while (st1 != NULL || st2 != NULL || carry != 0)
    {
        struct ListNode *a = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *b = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (st1 != NULL)
        {
            a = st1;
            st1 = st1->next;
        }
        else
        {
            a->val = 0;
            a->next = NULL;
        }
        if (st2 != NULL)
        {
            b = st2;
            st2 = st2->next;
        }
        else
        {
            b->val = 0;
            b->next = NULL;
        }

        int get_sum = a->val + b->val + carry;
        int ans = get_sum % 10;
        carry = get_sum / 10;

        struct ListNode *cur = (struct ListNode *)malloc(sizeof(struct ListNode));
        cur->val = ans;
        cur->next = new_head->next;
        new_head->next = cur;
    }

    struct ListNode *result = new_head->next;
    free(new_head);
    return result;
}

int main()
{
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;

    int a[] = {6, 1, 7};
    list1 = initLink(a, 3);

    int b[] = {2,9,5};
    list2 = initLink(b, 3);

    struct ListNode *q = addTwoNumbers(list1,list2);
    printList(q);

    return 0;
}