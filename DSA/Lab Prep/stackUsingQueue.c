// Making stack using queue
#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int rear;
    int front;
    int size;
    int *arr;
}queue;

int isFull(queue q)
{
    return (q.rear == q.size - 1);
}

int isEmpty(queue q)
{
    return (q.front == -1 && q.rear == -1);
}

void enqueue(queue *q, int data)
{
    if(isFull(*q))
    {
        printf("Queue is full\n");
    }
    else if(isEmpty(*q))
    {
        q->rear = q->front = 0;
        q->arr[q->rear] = data;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = data;
    }
}

int dequeue(queue *q)
{
    int val = -1;
    if(isEmpty(*q))
    {
        printf("Queue is empty\n");
    }
    else if(q->rear == q->front)
    {
        val = q->arr[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        val = q->arr[q->front];
        q->front++;
    }
    return val;
}

void push(queue *q1, queue *q2, int data)
{
    enqueue(q2, data);
    while (!isEmpty(*q1))
    {
        int val = dequeue(q1);
        enqueue(q2, val);
    }

    queue temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}

int pop(queue *q1)
{
    return dequeue(q1);
}

void display(queue q1)
{
    for(int i = q1.front; i <= q1.rear; i++)
    {
        printf("%d ", q1.arr[i]);
    }
    printf("\n");
}

int main()
{
    queue q1, q2;
    int n;
    printf("Enter the size of stack: ");
    scanf("%d", &n);
    q1.size = q2.size = n;
    q1.arr = (int*)malloc(n * sizeof(int));
    q2.arr = (int*)malloc(n * sizeof(int));
    q1.front = q1.rear = q2.front = q2.rear = -1;

    int a, data;
    do
    {
        printf("Enter\n1 to push\n2 to pop\n3 to display\n0 to exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the data to push: ");
            scanf("%d", &data);
            push(&q1, &q2, data);
            break;
        case 2:
            data = pop(&q1);
            printf("%d popped!\n", data);
            break;
        case 3:
            display(q1);
            break;
        default:
            break;
        }
    } while (a);
    
    return 0;
}