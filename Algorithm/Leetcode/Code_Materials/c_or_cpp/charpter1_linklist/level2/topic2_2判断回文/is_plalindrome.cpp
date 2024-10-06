#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include "../../list_node.cpp"

bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *pre = head;
    struct ListNode *prepre = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
        // 将前半部分链表反转
        pre->next = prepre;
        prepre = pre;
    }

    if (fast != NULL)
    {
        slow = slow->next;
    }

    while (pre != NULL && slow != NULL)
    {
        if (pre->val != slow->val)
        {
            return false;
        }
        pre = pre->next;
        slow = slow->next;
    }

    return true;
}

int main()
{
    struct ListNode *p = NULL;
    printf("create list: \t\n");
    // 创建链表0~9
    int a[] = {1, 2, 2, 1};
    p = initLink(a, 4);
    bool result = isPalindrome(p);
    printf("result=%d\n", result);

    return 0;
}