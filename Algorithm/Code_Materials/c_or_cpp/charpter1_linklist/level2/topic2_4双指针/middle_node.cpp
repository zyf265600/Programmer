#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    struct ListNode *list1 = NULL;

    int a[] = {1, 2, 3, 4, 5};

    list1 = initLink(a, 5);

    struct ListNode *list3 = middleNode(list1);

    // 输出的是3 4 5,我们主要看第一个是3就可以了，不必纠结后面的结果，想一下为什么
    printList(list3);
    return 0;
}