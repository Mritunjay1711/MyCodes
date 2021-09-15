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

void reverseTraversal(node *s)
{
    while(s->next)
        s = s->next;
    
    printf("NULL<--");
    while(s)
    {
        printf("%d<-->", s->data);
        s = s->prev;
    }
    printf("NULL\n");
}

void recurTraversal(node *s)
{
    if (s)
    {
        printf("%d<-->", s->data);
        recurTraversal(s->next);
    }
}

void reverseRecur(node *s)
{
    if (s)
    {
        reverseRecur(s->next);
        printf("%d<-->", s->data);
    }
}

// Function to delete previous node without traversal
void delete(node *top)
{
    top->prev = top->prev->prev;
    free(top->prev->next);
    top->prev->next = top;
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
    node *ptr = head->next->next; // 3rd node
    delete(ptr);  // Delete ptr->prev
    traversal(head);
    int j;
    do
    {
        printf("Enter\n1 to print forward\n2 to print backward\n0 to exit\n");
        scanf("%d", &j);
        switch (j)
        {
        case 1:
        {
            traversal(head);
            break;
        }
        case 2:
        {
            printf("NULL<--");
            reverseRecur(head);
            printf("NULL\n");
            reverseTraversal(head);
            break;
        }
        }
    } while (j);
    return 0;
}