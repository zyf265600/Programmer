#include <stdlib.h>
#include <stdio.h>

 struct ListNode {
      int val; //代表数据
      struct ListNode *next; //代表指针
 };


struct ListNode* initLink() {
    int i;
    //1、创建头指针
   struct ListNode* p = NULL;
    //2、创建头结点
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = 0;
    temp->next = NULL;
    //头指针指向头结点
    p = temp;
    //3、每创建一个结点，都令其直接前驱结点的指针指向它
    for (i = 1; i < 10; i++) {
        //创建一个结点
        struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
        a->val = i;
        a->next = NULL;
        //每次 temp 指向的结点就是 a 的直接前驱结点
        temp->next = a;
        //temp指向下一个结点（也就是a),为下次添加结点做准备
        temp = temp->next;
    }
    return p;
}

void printList(struct ListNode* p) {
    struct ListNode* temp = p;//temp指针用来遍历链表
    //只要temp指向结点的next值不是NULL，就执行输出语句。
    while (temp) {
        // struct ListNode* f = temp;//准备释放链表中的结点
        printf("%d ", temp->val);
        temp = temp->next;
        // free(f);
    }
    printf("\n");
}


int32_t getLength(struct ListNode* p) {
    struct ListNode* temp = p;//temp指针用来遍历链表
    int length=0;
    //只要temp指向结点的next值不是NULL，就执行输出语句。
    while (temp) {
        // struct ListNode* f = temp;//准备释放链表中的结点
        length++;
        temp = temp->next;
        // free(f);
    }
    return length;
}

struct ListNode* insertNode(struct ListNode* head, struct ListNode* nodeInsert, int position) {
    if (head == NULL) {
        // 这里可以认为待插入的节点就是链表的头节点，也可以抛出不能插入的异常
        return nodeInsert;
    }
    int size = getLength(head);
    if (position > size + 1 || position < 1) {
        printf("位置参数越界");
        return head;
    }

    // 插入节点到头部
    if (position == 1) {
        nodeInsert->next = head;
        head = nodeInsert;
        return head;
    }

    struct ListNode* pNode = head;
    int count = 1;
    // 遍历链表，找到插入位置的前一个节点
    while (count < position - 1) {
        pNode = pNode->next;
        count++;
    }
    nodeInsert->next = pNode->next;
    pNode->next = nodeInsert;

    return head;
}



struct ListNode* deleteNode(struct ListNode*head, int position) {
    if (head == NULL) {
        return NULL;
    }
    int size = getLength(head);
    if (position > size || position < 1) {
        printf("输入的参数有误\n");
        return head;
    }
    if (position == 1) {
        struct ListNode*curNode=head;
       head= head->next;
        free(curNode);
        return head;
    } else {
        struct ListNode* cur = head;
        int count = 1;
        while (count < position - 1) {
            cur = cur->next;
            count++;
        }
        struct ListNode*tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
        return head;
    }
}

void testInsert(){

    struct ListNode* head = NULL;
   struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
   node->val=1;
//    插入第一个元素
     head=insertNode(head,node,1);
   printList(head);
 
 //    插入第二个元素，因为前面至于一个元素，这里就是在尾部插入了
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val=3;
    head=insertNode(head,node,2);
    printList(head);


 //    插入第二个元素，后面有个三，所以这里就是中间位置插入了
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val=2;
    head=insertNode(head,node,2);
    printList(head);
}


void testDelete(){

    struct ListNode* p = NULL;
    printf("create list: \t\n");
    //创建链表0~9
    p = initLink();
    printList(p);

    // 删除第一个元素0
   p= deleteNode(p,1);
    printList(p);

   //删除中间元素
       p= deleteNode(p,5);
    printList(p);

   //删除末尾元素9
       p= deleteNode(p,8);
    printList(p);
  
}
int main() {

    // testInsert();

    testDelete();

    return 0;
}





