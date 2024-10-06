#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummyHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = head;
    struct ListNode* cur = dummyHead;
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            struct ListNode* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
        } else {
            cur = cur->next;
        }
    }
    struct ListNode* newHead = dummyHead->next;
    free(dummyHead);
    return newHead;
}

int main()
{
    struct ListNode *list1 = NULL;

    int a[] = {1, 2, 6, 3, 4, 5, 6};

    list1 = initLink(a, 7);

   removeElements(list1, 6);

    printList(list1);
    return 0;
}