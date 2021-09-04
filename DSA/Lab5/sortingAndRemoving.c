#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

node *head = NULL;

void createNode(node *s, int data)
{
    node *r = s, *w;
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

void sort(node *s)
{
    
    int swapped, i;
    node *w;
  
    if (s == NULL)
        return;
  
    do
    {
        swapped = 0;
        w = s;
  
        while (w->next != NULL)
        {
            if (w->data > w->next->data)
            {
                int temp = w->data;
                w->data = w->next->data;
                w->next->data = temp;
                swapped = 1;
            }
            w = w->next;
        }
    }
    while (swapped);
}

void removeDuplicate(node *q)
{
    node *w;
    while(q)
    {
        if(q->next != NULL && q->data == q->next->data)
        {
            w = q->next;
            q->next = w->next;
            w->next->prev = q;
            free(w);
        }
        q = q->next;
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
    sort(head);
    traversal(head);
    removeDuplicate(head);
    traversal(head);
    return 0;
}