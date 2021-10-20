#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;


void createNode(node **head, int data)
{
    node *r = *head, *w;
    if (r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r->data = data;
        r->prev = NULL;
        r->next = NULL;
        *head = r;
    }
    else
    {
        w = (node *)malloc(sizeof(node));
        w->data = data;
        w->next = NULL;
        w->prev = NULL;
        while (r->next)
            r = r->next;
        r->next = w;
        w->prev = r;
    }
}

void traversal(node *s)
{
    printf("NULL<--");
    while (s)
    {
        printf("%d<-->", s->data);
        s = s->next;
    }
    printf("NULL\n");
}

node *rotateKnodes(node *head, int k)
{
    node *current = head;
    node *tail = head;
    node *prev = NULL;
    while(k > 0)
    {
        prev = current;
        current = current->next;
        k--;
    }
    while(tail->next)
    {
        tail = tail->next;
    }
    current->prev = NULL;
    prev->next = NULL;
    tail->next = head;
    head->prev = tail;
    return current;
}

int main()
{
    node* head = NULL;
    int a, data, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &a);

    for(int i = 1; i <= a; i++)
    {
        printf("Enter the data for the node: ");
        scanf("%d", &data);
        createNode(&head, data);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    traversal(head);
    head = rotateKnodes(head, k);
    traversal(head);
    return 0;
}