#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

struct ListNode *headA;
struct ListNode *headB;
void initLink()
{

    struct ListNode *node9 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node9->val = 9;
    struct ListNode *node8 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node8->val = 8;
    struct ListNode *node7 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node7->val = 7;
    struct ListNode *node6 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node6->val = 6;
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node5->val = 5;
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node4->val = 4;
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node3->val = 3;
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2->val = 2;
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 1;

    // headA : 1 2 3 7 8 9

    headA = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node7;
    node7->next = node8;
    node8->next = node9;

    // headB : 4 5 6 7 8 9
    headB = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
}

struct ListNode *getIntersectionNode(struct ListNode *pHead1, struct ListNode *pHead2)
{
    if (pHead1 == NULL || pHead2 == NULL)
    {
        return NULL;
    }

    struct ListNode *p1 = pHead1;
    struct ListNode *p2 = pHead2;

    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;

        if (p1 != p2)
        {
            // 一个链表访问完了就跳到另外一个链表继续访问
            if (p1 == NULL)
            {
                p1 = pHead2;
            }
            if (p2 == NULL)
            {
                p2 = pHead1;
            }
        }
    }

    return p1;
}

int main()
{
    struct ListNode *p = NULL;
    // headA : 1 2 3 7 8 9
    // headB : 4 5 6 7 8 9
    initLink();

    p = getIntersectionNode(headA, headB);
    printList(p);

    return 0;
}
