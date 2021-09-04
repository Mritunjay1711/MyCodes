#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int row, col, data;
    struct node *next;
} node;

void createNode(node **head, int r, int c, int data)
{
    node *t = (*head)->next, *s;
    if (t == NULL)
    {
        t = (node *)malloc(sizeof(node));
        t->data = data;
        t->row = r;
        t->col = c;
        t->next = NULL;
        (*head)->next = t;
    }
    else
    {
        while (t->next)
            t = t->next;
        s = (node *)malloc(sizeof(node));
        s->data = data;
        s->row = r;
        s->col = c;
        s->next = NULL;
        t->next = s;
    }
}

void addSparse(node *head1, node *head2, node **addHead)
{
    (*addHead)->row = 0;
    (*addHead)->col = 0;
    (*addHead)->data = 0;
    if (head1->row != head2->row || head1->col != head2->col)
    {
        printf("Invalid addition!\n");
        return;
    }
    (*addHead)->row = head1->row;
    (*addHead)->col = head1->col;

    node *r = (node *)malloc(sizeof(node));
    r->next = NULL;
    (*addHead)->next = r;
    head1 = head1->next;
    head2 = head2->next;
    while (head1 && head2)
    {
        if (head1->row < head2->row)
        {
            r->row = head1->row;
            r->col = head1->col;
            r->data = head1->data;
            (*addHead)->data++;
            r->next = (node *)malloc(sizeof(node));
            r = r->next;
            r->next = NULL;
            head1 = head1->next;
        }
        else if (head2->row < head1->row)
        {
            r->row = head2->row;
            r->col = head2->col;
            r->data = head2->data;
            (*addHead)->data++;
            r->next = (node *)malloc(sizeof(node));
            r = r->next;
            r->next = NULL;
            head2 = head2->next;
        }
        else 
        {
            if (head1->col < head2->col)
            {
                r->row = head1->row;
                r->col = head1->col;
                r->data = head1->data;
                (*addHead)->data++;
                r->next = (node *)malloc(sizeof(node));
                r = r->next;
                r->next = NULL;
                head1 = head1->next;
            }
            else if (head2->col < head1->col)
            {
                r->row = head2->row;
                r->col = head2->col;
                r->data = head2->data;
                (*addHead)->data++;
                r->next = (node *)malloc(sizeof(node));
                r = r->next;
                r->next = NULL;
                head2 = head2->next;
            }
            else
            {
                r->row = head1->row;
                r->col = head1->row;
                r->data = head1->data + head2->data;
                (*addHead)->data++;
                r->next = (node *)malloc(sizeof(node));
                r = r->next;
                r->next = NULL;
                head1 = head1->next;
                head2 = head2->next;
            }
        }
    }

    while (head1 || head2)
    {
        if (head1)
        {
            r->row = head1->row;
            r->col = head1->col;
            r->data = head1->data;
            (*addHead)->data++;
            head1 = head1->next;
        }
        if(head2)
        {
            r->row = head2->row;
            r->col = head2->col;
            r->data = head2->data;
            (*addHead)->data++;
            head2 = head2->next;
        }
        r->next = (node *)malloc(sizeof(node));
        r = r->next;
        r->next = NULL;
    }
}

void display(node *head)
{
    node *p = head->next;
    for (int i = 0; i < head->row; i++)
    {
        for (int j = 0; j < head->col; j++)
        {
            if (p != NULL && p->row == i && p->col == j)
            {
                printf("%2d ", p->data);
                p = p->next;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
    printf("-------------\n");
}

int main()
{
    node *head1 = (node *)malloc(sizeof(node));
    head1->next = NULL;
    int a, r, c, data;

    printf("Enter the data for first matrix: \n");
    printf("Enter the number of row: ");
    scanf("%d", &head1->row);
    printf("Enter the number of column: ");
    scanf("%d", &head1->col);
    printf("Ente the number of non-zero elements: ");
    scanf("%d", &head1->data);
    for (int i = 0; i < head1->data; i++)
    {
        printf("Enter the row: ");
        scanf("%d", &r);
        printf("Enter the column: ");
        scanf("%d", &c);
        printf("Enter the data: ");
        scanf("%d", &data);
        createNode(&head1, r, c, data);
    }

    node *head2 = (node *)malloc(sizeof(node));
    head2->next = NULL;
    printf("Enter the data for second matrix: \n");
    printf("Enter the number of row: ");
    scanf("%d", &head2->row);
    printf("Enter the number of column: ");
    scanf("%d", &head2->col);
    printf("Ente the number of non-zero elements: ");
    scanf("%d", &head2->data);
    for (int i = 0; i < head2->data; i++)
    {
        printf("Enter the row: ");
        scanf("%d", &r);
        printf("Enter the column: ");
        scanf("%d", &c);
        printf("Enter the data: ");
        scanf("%d", &data);
        createNode(&head2, r, c, data);
    }
    display(head1);
    display(head2);

    node *addHead = (node *)malloc(sizeof(node));
    addHead->next = NULL;
    addSparse(head1, head2, &addHead);
    display(addHead);
    return 0;
}