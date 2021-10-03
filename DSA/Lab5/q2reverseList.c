#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

node *head = NULL;

void createNode(node *start, int data)
{
    node *r = start, *w;
    if (r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r->data = data;
        r->prev = NULL;
        r->next = NULL;
        head = r;
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

void reverse()
{
    node *temp = NULL;
    node *curr = head;

    while(curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    if(temp != NULL)
    {
        head = temp->prev;
    }
}

int main()
{
    node *t;
    int a, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &a);

    for (int i = 0; i < a; i++)
    {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        createNode(head, data);
    }
    traversal(head);
    reverse();
    traversal(head);
    return 0;
}