#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast != NULL && k > 0) {
        fast = fast->next;
        k--;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    struct ListNode *list1 = NULL;

    int a[] = {1, 2, 3, 4, 5};

    list1 = initLink(a, 5);

    struct ListNode *list3 = getKthFromEnd(list1,2);

    // 输出的是4 5,我们主要看第一个是4就可以了，不必纠结后面的结果，想一下为什么
    printList(list3);
    return 0;
}