#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* inStack;
    Node* outStack;
} Queue;

void initQueue(Queue* queue) {
    queue->inStack = NULL;
    queue->outStack = NULL;
}

void push(Queue* queue, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = NULL;

    if (queue->inStack == NULL) {
        queue->inStack = newNode;
    }
    else {
        Node* curr = queue->inStack;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

int pop(Queue* queue) {
    if (queue->outStack == NULL) {
        while (queue->inStack != NULL) {
            Node* curr = queue->inStack;
            queue->inStack = queue->inStack->next;

            curr->next = queue->outStack;
            queue->outStack = curr;
        }
    }

    if (queue->outStack == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    int val = queue->outStack->val;
    Node* curr = queue->outStack;
    queue->outStack = queue->outStack->next;
    free(curr);

    return val;
}

int peek(Queue* queue) {
    if (queue->outStack == NULL) {
        while (queue->inStack != NULL) {
            Node* curr = queue->inStack;
            queue->inStack = queue->inStack->next;

            curr->next = queue->outStack;
            queue->outStack = curr;
        }
    }

    if (queue->outStack == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->outStack->val;
}

int empty(Queue* queue) {
    return queue->inStack == NULL && queue->outStack == NULL;
}

int main() {
    Queue queue;
    initQueue(&queue);

    push(&queue, 1);
    push(&queue, 2);
    push(&queue, 3);

    printf("%d\n", pop(&queue));
    printf("%d\n", peek(&queue));
    printf("%d\n", empty(&queue));

    return 0;
}