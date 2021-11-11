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


void traversal(Queue *q)
{
    for(int i = q->f; i != q->r; i = (i+1)%q->size)
    {
        printf("%d ", q->arr[i]);
    }
    printf("%d\n", q->arr[q->r]);
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
        printf("%d enqueued!\n", data);
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
        printf("%d enqueued!\n", data);
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
    int a;
    do
    {
        printf("Enter\n1 for checking empty or not\n2 for checking full or not\n3 for Display the elements\n4 for Enqueue\n5 for Dequeue\n0 to exit\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
        {
            if(isEmpty(*q))
                printf("Queue is empty!\n");
            else
                printf("Queue is not empty!\n");
            break;
        }
        case 2:
        {
            if(isFull(*q))
                printf("Queue is Full!\n");
            else
                printf("Queue is not Full!\n");
            break;
        }
        case 3:
        {
            traversal(q);
            break;
        }
        case 4:
        {
            int data;
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        }
        case 5:
        {
            dequeue(q);
            break;
        }

        }
    }while(a);
    return 0;
}