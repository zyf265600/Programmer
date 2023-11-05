#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkQueue {
    Node* front;
    Node* rear;
    int size;
} LinkQueue;

LinkQueue* createLinkQueue() {
    LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void push(LinkQueue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    queue->size++;
}

int pull(LinkQueue* queue) {
    if (queue->front == NULL) {
        printf("队列已空\n");
        return 0;
    }
    
    Node* firstNode = queue->front;
    int value = firstNode->data;
    queue->front = firstNode->next;
    free(firstNode);
    queue->size--;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    return value;
}

void traverse(LinkQueue* queue) {
    Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main() {
    LinkQueue* queue = createLinkQueue();
    
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    
    traverse(queue);  // 输出: 1 2 3
    
    int value = pull(queue);
    printf("\n出队的元素: %d\n", value); // 输出: 1
    
    traverse(queue);  // 输出: 2 3
    
    return 0;
}