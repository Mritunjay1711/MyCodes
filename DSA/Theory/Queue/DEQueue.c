#include<stdio.h>
#include<stdlib.h>

typedef struct DEQueue
{
    int f, r, size, *arr;
}DEQueue;

void traversal(DEQueue q)
{
    for(int i = q.f; i != q.r; i = (i + 1)%q.size)
    {
        printf("%d ", q.arr[i]);
    }
    printf("%d\n", q.arr[q.r]);
}

void enqueue_front(DEQueue *q, int data)
{
    if(q->f == -1 && q->r == -1)
    {
        q->f = q->r = 0;
        q->arr[q->f] = data;
    }
    else if((q->f == 0 && q->r == q->size - 1) || (q->f - 1 == q->r))
    {
        printf("Queue Overflow!\n");
    }
    else if(q->f == 0)
    {
        q->f = (q->size - 1);
        q->arr[q->f] = data;
    }
    else
    {
        --q->f;
        q->arr[q->f] = data;
    }
}

void enqueue_rear(DEQueue *q, int data)
{
    if(q->r == -1 && q->f == -1)
    {
        q->r = q->f = 0;
        q->arr[q->r] = data;
    }
    else if((q->r == q->size - 1 && q->f == 0) || q->r + 1 == q->f)
    {
        printf("Queue Overflow!\n");
    }
    else if(q->r == q->size - 1)
    {
        q->r = 0;
        q->arr[q->r] = data;
    }
    else
    {
        q->r++;
        q->arr[q->r] = data;
    }
}

void dequeue_rear(DEQueue *q)
{
    if(q->f == -1 && q->r == -1)
    {
        printf("Queue Underflow!\n");
    }
    else if(q->f == q->r)
    {
        printf("%d dequeued!\n", q->arr[q->r]);
        q->f = q->r = -1;
    }
    else if(q->r == 0)
    {
        printf("%d dequeued!\n", q->arr[q->r]);
        q->r = q->size - 1;
    }
    else
    {
        printf("%d dequeued!\n", q->arr[q->r]);
        q->r--;
    }
}

void dequeue_front(DEQueue *q)
{
    if(q->f == -1 && q->r == -1)
    {
        printf("Queue Underflow!\n");
    }
    else if(q->f == q->r)
    {
        printf("%d dequeued!\n", q->arr[q->f]);
        q->f = q->r = -1;
    }
    else if(q->f == q->size - 1)
    {
        printf("%d dequeued!\n", q->arr[q->f]);
        q->f = 0;
    }
    else
    {
        printf("%d dequeued!\n", q->arr[q->f]);
        q->f++;
    }
}

int main()
{
    DEQueue q;
    q.f = q.r = -1;
    q.size = 5;
    
    printf("%d %d\n", q.f, q.r);
    q.arr = (int*)malloc(q.size * sizeof(int));
    enqueue_front(&q, 3);
    enqueue_front(&q, 6);
    enqueue_front(&q, 8);
    printf("%d %d\n", q.f, q.r);
    enqueue_rear(&q, 10);
    enqueue_rear(&q, 19);
    traversal(q);
    printf("%d %d\n", q.f, q.r);

    dequeue_rear(&q);
    dequeue_rear(&q);
    dequeue_rear(&q);
    dequeue_front(&q);
    dequeue_front(&q);
    dequeue_front(&q);
    return 0;
}