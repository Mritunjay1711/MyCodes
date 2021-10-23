#include<stdio.h>
#include<stdlib.h>

typedef struct DEQueue
{
    int f, r, size, *arr;
}DEQueue;

int isEmpty(DEQueue q)
{
    if(q.r == -1 && q.f == -1)
        return 1;
    else
        return 0;
}

int isFull(DEQueue q)
{
    if((q.f == 0 && q.r == q.size - 1) || (q.f - 1 == q.r))
    {
        return 1;
    }
    else
        return 0;
}

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
        printf("%d enqueued!\n", data);
    }
    else if((q->f == 0 && q->r == q->size - 1) || (q->f - 1 == q->r))
    {
        printf("Queue Overflow!\n");
    }
    else if(q->f == 0)
    {
        q->f = (q->size - 1);
        q->arr[q->f] = data;
        printf("%d enqueued!\n", data);
    }
    else
    {
        --q->f;
        q->arr[q->f] = data;
        printf("%d enqueued!\n", data);
    }
}

void enqueue_rear(DEQueue *q, int data)
{
    if(q->r == -1 && q->f == -1)
    {
        q->r = q->f = 0;
        q->arr[q->r] = data;
        printf("%d enqueued!\n", data);
    }
    else if((q->r == q->size - 1 && q->f == 0) || q->r + 1 == q->f)
    {
        printf("Queue Overflow!\n");
    }
    else if(q->r == q->size - 1)
    {
        q->r = 0;
        q->arr[q->r] = data;
        printf("%d enqueued!\n", data);
    }
    else
    {
        q->r++;
        q->arr[q->r] = data;
        printf("%d enqueued!\n", data);
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

    q.arr = (int*)malloc(q.size * sizeof(int));
    int a;
    do
    {
        printf("Enter\n1 for checking empty or not\n2 for checking full or not\n3 for Display the elements\n4 for Enqueue_front\n5 for Equeue_rear\n6 for Dequeue_front\n7 for Dequeue_rear\n0 to exit\n");
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
            enqueue_front(&q, data);
            break;
        }
        case 5:
        {
            int data;
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            enqueue_rear(&q, data);
            break;
        }
        case 6:
        {
            dequeue_front(&q);
            break;
        }
        case 7:
        {
            dequeue_rear(&q);
            break;
        }

        }
    }while(a);
    return 0;
}