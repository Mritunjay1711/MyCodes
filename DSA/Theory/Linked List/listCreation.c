#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;

    return p;
}

void traversal(struct node *head)
{
    while(head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void display(struct node *head)
{
    if(head)
    {
        printf("%d-->", head->data);
        display(head->next);
    }
}

void displayReverse(struct node *head)
{
    if(head)
    {
        displayReverse(head->next);
        printf("%d-->", head->data);
    }
}

void func(struct node *head)
{
    if(head == NULL)
        return;
    func(head->next);
    printf("%d ", head->data);
    func(head->next);
}

int main()
{
    int a, data;
    struct node *head = NULL, *t;
    printf("Enter the number of nodes: ");
    scanf("%d", &a);
    printf("Enter the data: ");
    scanf("%d", &data);
    t = createNode(data);
    head = t;
    do
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        t = createNode(data);
        struct node *w = head;
        while (w->next != NULL)
        {
            w = w->next;
        }
        w->next = t;
        a--;
    } while (a - 1);

    traversal(head);
    // display(head);
    // printf("NULL\n");
    // displayReverse(head);
    func(head);
    printf("NULL\n");
    return 0;
}

// |    |---->|    |---->|    |---->|    |---->|    |---->|    |---->NULL