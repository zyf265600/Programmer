#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int top;
} MyStack;

void initStack(MyStack *stack)
{
    stack->top = -1;
}

void push(MyStack *stack, int x)
{
    if (stack->top >= MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = x;
}

int pop(MyStack *stack)
{
    if (stack->top < 0)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int top(MyStack *stack)
{
    if (stack->top < 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

bool empty(MyStack *stack)
{
    return stack->top < 0;
}

int main()
{
    MyStack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("%d\n", pop(&stack));   // 输出3
    printf("%d\n", top(&stack));   // 输出2
    printf("%d\n", empty(&stack)); // 输出0（false）

    return 0;
}