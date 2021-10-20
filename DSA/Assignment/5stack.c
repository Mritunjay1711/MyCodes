#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int isEmpty(stack *s)
{
    return s->top == -1;
}

int isFull(stack *s)
{
    return s->top == s->size - 1;
}

void push(stack *s, int data)
{
    if (!isFull(s))
    {
        s->top++;
        s->arr[s->top] = data;
        printf("%d pushed!\n", data);
    }
    else
        printf("Stack Overflow!, Cannot push %d in Stack.\n", data);
}

int pop(stack *s)
{
    if (!isEmpty(s))
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
    else
    {
        printf("Stack Underflow.\n");
        return -1;
    }
}

int peekHighestElement(stack *q)
{
    if(isEmpty(q))
        printf("Stack is empty!\n");
    return q->arr[q->top];
}

int peekLowestElement(stack *q)
{
    if(isEmpty(q))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return q->arr[0];
}

int peekMiddleElement(stack *q)
{
    if(isEmpty(q))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return q->arr[q->top/2];
}

void traversal(stack *q)
{
    for(int i = q->top; i >= 0; i--)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main()
{
    stack *q = (stack *)malloc(sizeof(stack));
    q->top = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    push(q, 10);
    push(q, 3);
    push(q, 6);
    push(q, 23);
    push(q, 32);
    printf("Highest in stack: %d\n", peekHighestElement(q));
    printf("Lowest in stack: %d\n", peekLowestElement(q));
    printf("Middle of stack: %d\n", peekMiddleElement(q));
    return 0;
}