#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *createNode(int data)
{
    node *p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

void traversal(node *head)
{
    while(head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int product(node *head)
{
    int prod = 1;
    while(head)
    {
        prod *= head->data;
        head = head->next;
    }
    return prod;
}

int productRecursion(node *head)
{
    static int prod = 1;
    if(head)
    {
        prod *= head->data;
        productRecursion(head->next);
    }
    return prod;
}

int main()
{
    node* head = NULL, *t;
    int a, data;

    printf("Enter the data for the node: ");
    scanf("%d", &data);
    t = createNode(data);
    head = t;
    do{
        printf("Enter the data for next node: ");
        scanf("%d", &data);
        t = createNode(data);
        node *w = head;
        while(w->next)
        {
            w = w->next; 
        }
        w->next = t;
        printf("Enter 1 to product node or 0 to stop: ");
        scanf("%d", &a);
    }while(a);

    traversal(head);
    printf("%d\n", product(head));
    printf("%d\n", productRecursion(head));
    return 0;
}