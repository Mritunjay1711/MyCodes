#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int row, col, data;
    struct node *next;
}node;

void createNode(node **head, int r, int c, int data)
{
    node *t = (*head)->next, *s;
    if(t == NULL)
    {
        t = (node*)malloc(sizeof(node));
        t->data = data;
        t->row = r;
        t->col = c;
        t->next = NULL;
        (*head)->next = t;
    }
    else
    {
        while(t->next)
            t = t->next;
        s = (node*)malloc(sizeof(node));
        s->data = data;
        s->row = r;
        s->col = c;
        s->next = NULL;
        t->next = s;
    }
}

void display(node *head)
{
    node *p = head->next, *q = head->next, *r = head->next;
    
    printf("Row indices: ");
    while(p)
    {
        printf("%d ", p->row);
        p = p->next;
    }

    printf("\nColumn indices: ");
    while(q)
    {
        printf("%d ", q->col);
        q = q->next;
    }

    printf("\nData: ");
    while(r)
    {
        printf("%d ", r->data);
        r = r->next;
    }
}

int main()
{
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    int a, r, c, data;

    printf("Enter the number of row: ");
    scanf("%d", &head->row);
    printf("Enter the number of column: ");
    scanf("%d", &head->col);
    printf("Ente the number of non-zero elements: ");
    scanf("%d", &head->data);
    for(int i = 0; i < head->data; i++)
    {
        printf("Enter the row: ");
        scanf("%d", &r);
        printf("Enter the column: ");
        scanf("%d", &c);
        printf("Enter the data: ");
        scanf("%d", &data);
        createNode(&head, r, c, data);
    }
    
    
    display(head);
    return 0;
}