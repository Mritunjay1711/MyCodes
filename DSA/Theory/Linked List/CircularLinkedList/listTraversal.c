#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

node *createNode(int data)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;

    return p;
}

void traversal(node *head)
{
    node *p = head;
    do
    {
        printf("%d-->", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void insertAtHead(int data)
{
    node *p = createNode(data);
    node *w = head;
    while (w->next != head)
    {
        w = w->next;
    }
    w->next = p;
    p->next = head;
    head = p;
}

void insertAtTail(int data)
{
    node *p = createNode(data);
    node *w = head;
    while (w->next != head)
    {
        w = w->next;
    }
    w->next = p;
    p->next = head;
}

void insertAtIndex(int data, int index)
{
    node *p = createNode(data);
    if (head == NULL)
    {
        head = p;
        p->next = head;
    }
    if (index == 1)
    {
        node *w = head;
        while (w->next != head)
        {
            w = w->next;
        }
        w->next = p;
        p->next = head;
        head = p;
    }
    else
    {
        node *q, *w = head;
        for(int i = 1; i < index; i++)
        {
            q = w;
            w = w->next;
        }
        p->next = w;
        q->next = p;
    }
}

void deleteHead()
{
    node *p = head;
    node *w = head;
    while (p->next != head)
    {
        p = p->next;
    }
    head = head->next;
    p->next = head;
    free(w);
}

void deleteTail()
{
    node *p, *w = head;
    while (w->next != head)
    {
        p = w;
        w = w->next;
    }
    p->next = head;
    free(w);
}

void deleteIndex(int index)
{
    node *p, *w = head;
    if (head == NULL)
    {
        printf("Empty list!\n");
        return;
    }
    if (index == 1)
    {
        p = head, w = head;
        while (p->next != head)
        {
            p = p->next;
        }
        head = head->next;
        p->next = head;
        free(w);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = w;
            w = w->next;
        }
        p->next = w->next;
        free(w);
    }
}

int main()
{
    node *t;
    int a, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &a);
    printf("Enter the first element: ");
    scanf("%d", &data);
    t = createNode(data);
    head = t;
    while (a - 1)
    {
        printf("Enter the next element: ");
        scanf("%d", &data);
        t = createNode(data);
        node *w = head;
        while (w->next)
        {
            w = w->next;
        }
        w->next = t;
        a--;
    }
    node *w = head;
    while (w->next)
    {
        w = w->next;
    }
    w->next = head;

    int i;
    do
    {
        printf("Enter\n1 for Display\n2 for delete head\n3 for delete tail\n4 for delete index\n5 for inserting at head\n6 for inserting at tail\n7 for inserting at an index\n0 to exit\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
        {
            traversal(head);
            break;
        }
        case 2:
        {
            deleteHead();
            break;
        }
        case 3:
        {
            deleteTail();
            break;
        }
        case 4:
        {
            int x;
            printf("Enter the index: ");
            scanf("%d", &x);
            deleteIndex(x);
            break;
        }
        case 5:
        {
            int x;
            printf("Enter the data to insert: ");
            scanf("%d", &x);
            insertAtHead(x);
            break;
        }
        case 6:
        {
            int x;
            printf("Enter the data to insert: ");
            scanf("%d", &x);
            insertAtTail(x);
            break;
        }
        case 7:
        {
            int x, i;
            printf("Enter the data to insert: ");
            scanf("%d", &x);
            printf("Enter the index: ");
            scanf("%d", &i);
            insertAtIndex(x, i);
            break;
        }
        }
    } while (i);
    return 0;
}