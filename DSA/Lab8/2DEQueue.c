#include <stdio.h>
#include <stdlib.h>

typedef struct DEQueue
{
    int data;
    struct DEQueue *next;
} DEQueue;

int isEmpty(DEQueue *f)
{
    return f == NULL;
}

int isFull(DEQueue *f)
{
    DEQueue *n = (DEQueue *)malloc(sizeof(DEQueue));
    return (n == NULL);
}

void enqueue_rear(DEQueue **f, DEQueue **r, int data)
{
    DEQueue *n = (DEQueue *)malloc(sizeof(DEQueue));
    if (n == NULL)
    {
        printf("Queue is full!\n");
    }
    else
    {
        n->data = data;
        n->next = NULL;

        if (*f == NULL)
        {
            *f = *r = n;
        }
        else
        {
            (*r)->next = n;
            *r = n;
        }
    }
}

void enqueue_front(DEQueue **f, DEQueue **r, int data)
{
    DEQueue *n = (DEQueue *)malloc(sizeof(DEQueue));
    if (n == NULL)
    {
        printf("Queue is full!\n");
    }
    else
    {
        n->data = data;
        n->next = NULL;

        if (*f == NULL)
        {
            *f = *r = n;
        }
        else
        {
            n->next = *f;
            *f = n;
        }
    }
}


int dequeue_front(DEQueue **f, DEQueue **r)
{
    int val = -1;
    DEQueue *ptr = *f;
    if (isEmpty(*f))
    {
        printf("Queue Underflow!\n");
        return val;
    }
    else if (*f == *r)
    {
        val = ptr->data;
        free(ptr);
        *f = NULL;
        *r = NULL;
        return val;
    }
    else
    {
        *f = (*f)->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}

int dequeue_rear(DEQueue **f, DEQueue **r)
{
    int val = -1;
    DEQueue *ptr = *r;
    if (isEmpty(*f))
    {
        printf("Queue Underflow!\n");
        return val;
    }
    else if (*f == *r)
    {
        val = ptr->data;
        free(ptr);
        *f = NULL;
        *r = NULL;
        return val;
    }
    else
    {
        DEQueue *temp = *f;
        while (temp->next != *r)
        {
            temp = temp->next;
        }
        val = (*r)->data;
        free(*r);
        *r = temp;
        return val;
    }
}

void traversal(DEQueue *f)
{
    while (f)
    {
        printf("%d-->", f->data);
        f = f->next;
    }
    printf("NULL\n");
}

int main()
{
    DEQueue *f = NULL, *r = NULL;
    int a, b;
    printf("1 for input restricted\n2 for output restricted\n");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
    {
        do
    {
        printf("Enter\n1 for Equeue_rear\n2 for Dequeue_front\n3 for Dequeue_rear\n4 to display\n0 to exit\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
        {
            int data;
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            enqueue_rear(&f, &r, data);
            break;
        }
        case 2:
        {
            printf("%d dequeued!\n", dequeue_front(&f, &r));
            break;
        }
        case 3:
        {
            printf("%d dequeued!\n", dequeue_rear(&f, &r));
            break;
        }
        case 4:
        {
            traversal(f);
            break;
        }
        }
    } while (a);
    break;
    }
    case 2:
    {
        do
    {
        printf("Enter\n1 for Enqueue_front\n2 for Equeue_rear\n3 for Dequeue_front\n4 to display\n0 to exit\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
        {
            int data;
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            enqueue_front(&f, &r, data);
            break;
        }
        case 2:
        {
            int data;
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            enqueue_rear(&f, &r, data);
            break;
        }
        case 3:
        {
            printf("%d dequeued!\n", dequeue_front(&f, &r));
            break;
        }
        case 4:
        {
            traversal(f);
            break;
        }
        }
    } while (a);
        break;
    }
    
    default:
        break;
    }
    
    return 0;
}