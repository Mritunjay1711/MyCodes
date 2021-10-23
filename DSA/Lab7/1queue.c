#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int f;
    int r;
    int size;
    int *arr;
}Queue;

int isFull(Queue *q)
{
    return (q->r == q->size -1);
}

int isEmpty(Queue *q)
{
    return (q->f == -1 && q->r == -1);
}

void enqueue(Queue *q, int element)
{
    if(isFull(q))
    {
        printf("Queue Overflow!\n");
    }
    else if(isEmpty(q))
    {
        q->f = q->r = 0;
        q->arr[q->r] = element;
        printf("%d enqueued!\n", element);
    }
    else
    {
        q->r++;
        q->arr[q->r] = element;
        printf("%d enqueued!\n", element);
    }
}

void dequeue(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty!\n");
    }
    else if(q->f == q->r)
    {
        printf("%d dequeued!\n", q->arr[q->f]);
        q->f = q->r = -1;

    }
    else
    {
        printf("%d dequeued!\n", q->arr[q->f++]);
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

int peek(Queue *q)
{
    return q->arr[q->f];
}

int main()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->f = q->r = -1;
    printf("Enter the size of queue: ");
    scanf("%d", &q->size);
    q->arr = (int*)malloc(q->size * sizeof(int));
    int a;
    do
    {
        printf("Enter\n1 for checking empty or not\n2 for checking full or not\n3 for Display the elements\n4 for Enqueue\n5 for Dequeue\n6 to peek\n0 to exit\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
        {
            if(isEmpty(q))
                printf("Queue is empty!\n");
            else
                printf("Queue is not empty!\n");
            break;
        }
        case 2:
        {
            if(isFull(q))
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
        case 6:
        {
            printf("%d is first element!\n", peek(q));
            break;
        }

        }
    }while(a); 
    return 0;
}