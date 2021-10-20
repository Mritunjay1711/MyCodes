// Swap second last with last and first with second
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *createNode(int data)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;

    return p;
}

void traversal(node *head)
{
    node *curr = head;
    do{
        printf("%d->", curr->data);
        curr = curr->next;
    }while(curr != head);
    printf("\n");
}

void swapOperation(node **head)
{
    node *current = *head, *prev;
    while(current->next->next != *head)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    prev->next->next = current;
    current->next = *head;

    current->next = (*head)->next;
    (*head)->next = (*head)->next->next;
    current->next->next = *head;
    *head = current->next;
}

int main()
{
    node *t, *head;
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

    traversal(head);
    swapOperation(&head);
    traversal(head);
    
    return 0;
}