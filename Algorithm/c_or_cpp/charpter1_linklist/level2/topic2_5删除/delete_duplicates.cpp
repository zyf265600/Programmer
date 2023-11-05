#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head == NULL || k == 0)
    {
        return head;
    }
    struct ListNode *temp = head;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    if (k % len == 0)
    {
        return temp;
    }
    while ((k % len) > 0)
    {
        k--;
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode *res = slow->next;
    slow->next = NULL;
    fast->next = temp;
    return res;
}

int main()
{
    struct ListNode *list1 = NULL;

    int a[] = {1, 2, 3, 4, 5};

    list1 = initLink(a, 5);

    struct ListNode *list3 = rotateRight(list1, 2);

    // 输出的是4 5,我们主要看第一个是4就可以了，不必纠结后面的结果，想一下为什么
    printList(list3);
    return 0;
}