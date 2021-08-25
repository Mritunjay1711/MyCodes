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
    while (head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int searchMax(struct node *head)
{
    int max = 0;
    while (head)
    {
        if(max < head->data)
            max = head->data;
        head = head->next;
    }
    return max;
}

int searchMin(struct node *head)
{
    int min = head->data;
    while (head)
    {
        if(min > head->data)
            min = head->data;
        head = head->next;
    }
    return min;
}

int main()
{
    struct node *head = NULL, *t;
    int a, data;
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
        while(w->next)
        {
            w = w->next;
        }
        w->next = t;
        a--;

    }while(a - 1);

    traversal(head);
    printf("Maximum element present in list is %d\n", searchMax(head));
    printf("Minimum element present in list is %d\n", searchMin(head));
    return 0;
}