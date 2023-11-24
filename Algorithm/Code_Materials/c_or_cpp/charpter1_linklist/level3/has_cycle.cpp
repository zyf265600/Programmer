#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>

struct ListNode
{
    int val;               // 代表数据
    struct ListNode *next; // 代表指针
};

struct ListNode *initLink(int a[], int size)
{
    int i;
    // 1、创建头指针
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = a[0];
    head->next = NULL;
    // 头指针指向头结点
    struct ListNode *c = nullptr;
    c = head;

    struct ListNode *entrance = nullptr;
    // 3、每创建一个结点，都令其直接前驱结点的指针指向它
    for (i = 1; i < size; i++)
    {
        // 创建一个结点
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = a[i];
        newNode->next = NULL;
        c->next = newNode;
        c = c->next;
        if (i == 1)
        {
            entrance = c;
        }
        if (i == size - 1)
        {
            c->next = entrance;
        }
    }

    return head;
}

void printList(struct ListNode *p)
{
    struct ListNode *temp = p; // temp指针用来遍历链表
    // 只要temp指向结点的next值不是NULL，就执行输出语句。
    while (temp)
    {
        // struct ListNode* f = temp;//准备释放链表中的结点
        printf("%d ", temp->val);
        temp = temp->next;
        // free(f);
    }
    printf("\n");
}

bool hasCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    
   struct ListNode* slow = head;
   struct ListNode* fast = head;
    
    while (fast != NULL) {
        slow = slow->next;
        
        if (fast->next != NULL) {
            fast = fast->next->next;
        } else {
            return NULL;
        }
        
        if (fast == slow) {
           struct ListNode* ptr = head;
            
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            
            return ptr;
        }
    }
    
    return NULL;
}

int main()
{
    struct ListNode *list1 = NULL;

    int a[] = {3, 2, 0, -4};

    list1 = initLink(a, 4);

    bool result = hasCycle(list1);

    return 0;
}