#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int isEmpty(node *f)
{
    return f == NULL;
}

int isFull(node *f)
{
    node *n = (node *)malloc(sizeof(node));
    return (n == NULL);
}

void enqueue_rear(node **f, node **r, int data)
{
    node *n = (node *)malloc(sizeof(node));
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
            n->next = n;
        }
        else
        {
            (*r)->next = n;
            *r = n;
            n->next = *f;
        }
    }
}

void enqueue_front(node **f, node **r, int data)
{
    node *n = (node *)malloc(sizeof(node));
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
            n->next = n;
        }
        else
        {
            n->next = *f;
            (*r)->next = n;
            *f = n;
        }
    }
}

void enqueue_position(node **f, node **r, int pos, int data)
{
    node *n = (node *)malloc(sizeof(node));
    node *temp = *f;
    if (n == NULL)
    {
        printf("Queue is full!\n");
    }
    else if (pos == 1)
    {
        n->data = data;
        n->next = NULL;

        if (*f == NULL)
        {
            *f = *r = n;
            n->next = n;
        }
        else
        {
            n->next = *f;
            (*r)->next = n;
            *f = n;
        }
    }
    else
    {
        n->data = data;
        n->next = NULL;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
        if (temp == *r)
            *r = temp;
    }
}

int dequeue_front(node **f, node **r)
{
    int val = -1;
    node *ptr = *f;
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
        (*r)->next = *f;
        val = ptr->data;
        free(ptr);
        return val;
    }
}

int dequeue_rear(node **f, node **r)
{
    int val = -1;
    node *ptr = *r;
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
        node *temp = *f;
        while (temp->next != *r)
        {
            temp = temp->next;
        }
        temp->next = *f;
        val = (*r)->data;
        free(*r);
        *r = temp;
        return val;
    }
}

int dequeue_position(node **f, node **r, int pos)
{
    int val = -1;
    node *ptr = *f, *temp;
    if (isEmpty(*f))
    {
        printf("Queue underflow!\n");
    }
    if (pos == 1)
    {
        if (*f == *r)
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
            (*r)->next = *f;
            val = ptr->data;
            free(ptr);
            return val;
        }
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}

void traversal(node *f, node *r)
{
    while (f != r)
    {
        printf("%d-->", f->data);
        f = f->next;
    }
    printf("%d-->front\n", r->data);
}

int main()
{
    node *f = NULL, *r = NULL;
    int a;
    do
    {
        printf("Enter\n1 for Enqueue_front\n2 for Equeue_rear\n3 for Enqueue at position\n4 for Dequeue_front\n5 for Dequeue_rear\n6 for Dequeue at position\n7 to display\n0 to exit\n");
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
            int data, i;
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            printf("Enter the position to enqueue: ");
            scanf("%d", &i);
            enqueue_position(&f, &r, i, data);
            break;
        }
        case 4:
        {
            printf("%d dequeued!\n", dequeue_front(&f, &r));
            break;
        }
        case 5:
        {
            printf("%d dequeued!\n", dequeue_rear(&f, &r));
            break;
        }
        case 6:
        {
            int i;
            printf("Enter the position: ");
            scanf("%d", &i);
            printf("%d dequeued!\n", dequeue_position(&f, &r, i));
            break;
        }
        case 7:
        {
            traversal(f, r);
            break;
        }
        }
    } while (a);
    return 0;
}