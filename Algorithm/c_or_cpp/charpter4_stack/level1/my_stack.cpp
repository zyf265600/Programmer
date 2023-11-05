#include <stdio.h>
#include <stdlib.h>

// 定义栈结构体
typedef struct {
    int* items;
    int top;
    int capacity;
} Stack;

// 初始化栈
Stack* create_stack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->items = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// 判断栈是否为空
int is_empty(Stack* stack)
{
    return stack->top == -1;
}

// 判断栈是否已满
int is_full(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

// 入栈
void push(Stack* stack, int item)
{
    if(is_full(stack))
    {
        printf("栈已满，无法入栈\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// 出栈
int pop(Stack* stack)
{
    if(is_empty(stack))
    {
        printf("栈为空，无法出栈\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// 返回栈顶元素
int peek(Stack* stack)
{
    if(is_empty(stack))
    {
        printf("栈为空\n");
        return -1;
    }
    return stack->items[stack->top];
}

// 返回栈的大小
int size(Stack* stack)
{
    return stack->top + 1;
}

// 测试
int main()
{
    // 创建一个容量为5的栈
    Stack* stack = create_stack(5);

    // 入栈
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // 打印栈顶元素
    printf("peek: %d\n", peek(stack));
    
    // 出栈
    printf("pop: %d\n", pop(stack));
    
    // 打印栈的大小
    printf("size: %d\n", size(stack));
    
    return 0;
}