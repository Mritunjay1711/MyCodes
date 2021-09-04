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
    node *r;
    if (s == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r->data = data;
        head = r;
        r->next = head;
        r->prev = head;
    }
    else
    {
        if (s->next != head)
        {
            do
            {
                s = s->next;
            } while (s->next != head);
        }

        r = (node *)malloc(sizeof(node));
        r->data = data;
        r->next = head;
        s->next = r;
        r->prev = s;
        head->prev = r;
    }
}

void traversal(node *s)
{
    do
    {
        printf("%d-->", s->data);
        s = s->next;
    } while (s->next != head);
}

int main()
{
    int x, data;
    printf("Enter the number of elements: ");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &head);
        createNode(head, data);
    }

    traversal(head);
    return 0;
}