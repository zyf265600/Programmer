#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

struct ListNode *mergeInBetween(struct ListNode *list1, int a, int b, struct ListNode *list2)
{
    struct ListNode *pre1 = list1;
    struct ListNode *post1 = list1;
    struct ListNode *post2 = list2;
    int i = 0, j = 0;

    // 寻找list1中的节点pre1和post1
    while (pre1 != NULL && post1 != NULL && j < b)
    {
        if (i != a - 1)
        {
            pre1 = pre1->next;
            i++;
        }
        if (j != b)
        {
            post1 = post1->next;
            j++;
        }
    }

    post1 = post1->next;

    // 寻找list2的尾节点
    while (post2->next != NULL)
    {
        post2 = post2->next;
    }

    // 链1尾接链2头，链2尾接链1后半部分的头
    pre1->next = list2;
    post2->next = post1;

    return list1;
}

int main()
{
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    printf("create list: \t\n");

    int AA[] = {0, 1, 2, 3, 4, 5};
    int BB[] = {100, 101, 102};
    list1 = initLink(AA, 6);
    list2 = initLink(BB, 3);

    struct ListNode *list3 = mergeInBetween(list1, 3, 4, list2);

    printList(list3);
    return 0;
}