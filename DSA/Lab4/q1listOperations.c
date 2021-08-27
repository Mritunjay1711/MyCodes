#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;

node *createNode(int data)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

void traversal(node *head)
{
    while (head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void traversalRecursion(node *head)
{
    if (head)
    {
        printf("%d-->", head->data);
        traversalRecursion(head->next);
    }
}

int lengthList(node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int countRecursion(node *head)
{
    if (head == NULL)
        return 0;
    else
        return countRecursion(head->next) + 1;
}

int maxInList(node *head)
{
    int max = 0;
    while (head)
    {
        if (max < head->data)
            max = head->data;
        head = head->next;
    }
    return max;
}

int maxRecursive(node *head)
{
    int max;
    if(head == NULL)
        return -1;
    else
    {
        max = maxRecursive(head->next);
        return max > head->data ? max : head->data;
    }
}

int minInList(node *head)
{
    int min = head->data;
    while (head)
    {
        if (min > head->data)
            min = head->data;
        head = head->next;
    }
    return min;
}

int minRecursive(node *head, int min)
{
    if(head == NULL)
        return min;
    else
    {
        if(head->data < min)
            min = head->data;
        return minRecursive(head->next, min);
    }
}

int add(node *head)
{
    int sum = 0;
    while (head)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int addRecursion(node *head)
{
    if (head == NULL)
        return 0;
    else
        return addRecursion(head->next) + head->data;
}

int main()
{
    node *t;
    int a, data;

    printf("Enter the data for the node: ");
    scanf("%d", &data);
    t = createNode(data);
    head = t;
    do
    {
        printf("Enter the data for next node: ");
        scanf("%d", &data);
        t = createNode(data);
        node *w = head;
        while (w->next)
        {
            w = w->next;
        }
        w->next = t;
        printf("Enter 1 to add node or 0 to stop: ");
        scanf("%d", &a);
    } while (a);

    int i;
    
    do
    {
        printf("Enter\n1 for Display\n2 for Length of list\n3 for sum of elements of list\n4 for finding maximum element\n5 for finding minimum value\n0 to exit\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
        {
            int x;
            printf("Enter\n1 for iterative  0 for recursive\n");
            scanf("%d", &x);
            if (x)
                traversal(head);
            else
                traversalRecursion(head);

            break;
        }
        case 2:
        {
            int x;
            printf("Enter\n1 for iterative  0 for recursive\n");
            scanf("%d", &x);
            if (x)
                printf("Length of list: %d\n", lengthList(head));
            else
                printf("Length of list: %d\n", countRecursion(head));
            break;
        }
        case 3:
        {
            int x;
            printf("Enter\n1 for iterative  0 for recursive\n");
            scanf("%d", &x);
            if (x)
                printf("Sum of elements in list: %d\n", add(head));
            else
                printf("Sum of elements in list: %d\n", addRecursion(head));

            break;
        }
        case 4:
        {
            int x;
            printf("Enter\n1 for iterative  0 for recursive\n");
            scanf("%d", &x);
            if (x)
                printf("Maximum element in list: %d\n", maxInList(head));
            else
                printf("Maximum element in list: %d\n", maxRecursive(head));
            break;
        }
        case 5:
        {
            int x, min = 32741;
            printf("Enter\n1 for iterative  0 for recursive\n");
            scanf("%d", &x);
            if (x)
                printf("Minimum element in list: %d\n", minInList(head));
            else
                printf("Minimum element in list: %d\n", minRecursive(head, min));
            break;
        }
        }
    } while (i);

    return 0;
}