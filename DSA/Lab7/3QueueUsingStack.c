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

void traversal(stack *q)
{
    for(int i = q->top; i >= 0; i--)
        printf("%d ", q->arr[i]);
    printf("\n");
}

void enqueue(stack *s1, stack *s2, int data)
{
    if(isFull(s1))
    {
        printf("Overflow!\n");
        return;
    }
    while(!isEmpty(s1))
    {
        push(s2, pop(s1));
    }
    push(s1, data);
    while(!isEmpty(s2))
    {
        push(s1, pop(s2));
    }
}

int dequeue(stack *s1)
{
    int val = -1;
    if(isEmpty(s1))
    {
        printf("Underflow!\n");
        return val;
    }
    val = pop(s1);
    return val;
}

int main()
{
    int size;
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    stack s1, s2;
    s1.top = s2.top = -1;
    s1.size = s2.size = size;
    s1.arr = (int*)malloc(size * sizeof(int));
    s2.arr = (int*)malloc(size * sizeof(int));

    enqueue(&s1, &s2, 5);
    enqueue(&s1, &s2, 6);
    enqueue(&s1, &s2, 23);
    enqueue(&s1, &s2, 87);
    enqueue(&s1, &s2, 12);
    traversal(&s1);
    dequeue(&s1);
    dequeue(&s1);
    traversal(&s1);
    return 0;
}