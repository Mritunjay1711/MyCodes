#include<stdio.h>
#include<stdlib.h>

typedef struct circularQueue
{
    int f;
    int r;
    int size;
    int *arr;
}Queue;

int isEmpty(Queue q)
{
    if(q.r == -1 && q.f == -1)
        return 1;
    else
        return 0;
}

int isFull(Queue q)
{
    if((q.r + 1) % q.size == q.f)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int data)
{
    if(isFull(*q))
    {
        printf("Queue is full!\n");
    }
    else if (isEmpty(*q))
    {
        q->r = q->f = 0;
        q->arr[q->r] = data;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
    }
}

void dequeue(Queue *q)
{
    if(isEmpty(*q))
    {
        printf("Queue is empty\n");
    }
    else if(q->r == 0 && q->f == 0)
    {
        printf("Dequeued element %d\n", q->arr[q->f]);
        q->r = q->f = -1;
    }
    else
    {
        printf("Dequeued element %d\n", q->arr[q->f]);
        q->f = (q->f + 1) % q->size;
    }
    
}

int main()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->r = q->f = -1;
    q->size = 5;
    q->arr = (int*)malloc(q->size * sizeof(int));
    enqueue(q, 10);
    enqueue(q, 5);
    enqueue(q, 9);
    dequeue(q);
    dequeue(q);
    return 0;
}