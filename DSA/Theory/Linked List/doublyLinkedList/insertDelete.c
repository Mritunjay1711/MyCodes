#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *head = NULL;

node *createNode(int data)
{
    node *p = (node*)malloc(sizeof(node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void traversal(node *s)
{
    while(s)
    {
        printf("%d<-->", s->data);
        s = s->next;
    }
    printf("NULL\n");    
}

void insertAtHead(int data)
{
    node *p = createNode(data);
    p->next = head;
    head->prev = p;
    head = p;
}

void insertAtTail(node *s, int data)
{
    node *p = createNode(data);
    while(s->next)
    {
        s = s->next;
    }
    s->next = p;
    p->prev = s;
}

int main()
{
    node *t;
    int a, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &a);
    
    printf("Enter the first element: ");
    scanf("%d", &data);
    t = createNode(data);
    head = t;
    while(a - 1)
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
        t->prev = w;
        a--;
    }
    traversal(head);
    insertAtHead(23);
    insertAtTail(head, 43);
    traversal(head);
    return 0;
}