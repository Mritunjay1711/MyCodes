#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int f;
    int r;
    int size;
    int *arr;
}Queue;

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int isEmptyS(stack *s)
{
    return s->top == -1;
}

int isFullS(stack *s)
{
    return s->top == s->size - 1;
}

void push(stack *s, int data)
{
    if (!isFullS(s))
    {
        s->top++;
        s->arr[s->top] = data;
    }
    else
        printf("Stack Overflow!, Cannot push %d in Stack.\n", data);
}

int pop(stack *s)
{
    if (!isEmptyS(s))
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

int isFullQ(Queue *q)
{
    return (q->r == q->size -1);
}

int isEmptyQ(Queue *q)
{
    return (q->r == -1 && q->f == -1);
}

void enqueue(Queue *q, int element)
{
    if(isFullQ(q))
    {
        printf("Queue Overflow!\n");
    }
    else if(isEmptyQ(q))
    {
        q->f = q->r = 0;
        q->arr[q->r] = element;
    }
    else
    {
        q->r++;
        q->arr[q->r] = element;
    }
}

int dequeue(Queue *q)
{
    int val = -1;
    if(isEmptyQ(q))
    {
        printf("Queue is empty!\n");
        return val;
    }
    else if(q->f == q->r)
    {
        val = q->arr[q->f];
        q->f = q->r = -1;
        return val;

    }
    else
    {
        val = q->arr[q->f++];
        return val;
    }
}

void traversal(Queue *q)
{
    for(int i = q->f; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void reverse(Queue *q)
{
    stack s;
    s.top = -1;
    s.size = q->size;
    s.arr = (int*)malloc(s.size * sizeof(int));
    while(!isEmptyQ(q))
    {
        push(&s, dequeue(q));
    }
    while(!isEmptyS(&s))
    {
        enqueue(q, pop(&s));
    }
}

int main()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->f = q->r = -1;
    q->size = 5;
    q->arr = (int*)malloc(q->size * sizeof(int));
    enqueue(q, 6);
    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 2);
    traversal(q);
    reverse(q);
    traversal(q);
}