#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

node *head = NULL;

node *createNode(int data)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
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
    while (s->next)
        s = s->next;

    printf("NULL<--");
    while (s)
    {
        printf("%d<-->", s->data);
        s = s->prev;
    }
    printf("NULL\n");
}

void insertAtHead(int data)
{
    node *p = createNode(data);
    p->next = head;
    head->prev = p;
    head = p;
}

void insertAtTail(node *s, int data)
{
    node *p = createNode(data);
    while (s->next)
    {
        s = s->next;
    }
    s->next = p;
    p->prev = s;
}

void insertAtIndex(node *s, int data, int index)
{
    node *p = createNode(data);
    node *q;

    if (index == 1)
    {
        p->next = head;
        head->prev = p;
        head = p;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            q = s;
            s = s->next;
        }
        q->next = p;
        p->prev = q;
        p->next = s;
        s->prev = p;
    }
}

void deleteHead()
{
    node *w = head;
    head = head->next;
    head->prev = NULL;
    free(w);
}

void deleteTail(node *s)
{
    node *w;
    while (s->next)
    {
        w = s;
        s = s->next;
    }
    w->next = NULL;
    free(s);
}

void deleteAtIndex(node *s, int index)
{

    if (s == NULL)
        printf("Empty list\n");
    if (index == 1)
    {
        node *w = head;
        head = head->next;
        head->prev = NULL;
        free(w);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            s = s->next;
        }
        s->prev->next = s->next;
        free(s);
        
    }
}

void deleteKey(node *s, int key)
{
    if (s->data == key)
    {
        node *w = head;
        head = head->next;
        head->prev = NULL;
        free(w);
    }
    else
    {
        while(s)
        {
            if(s->data == key)
            {
                node *w = s;
                s->prev->next = s->next;
                free(w);
                return;
            }
            s = s->next;
        }
    }
    printf("Key not found!\n");
}

int countNode(node *s)
{
    int count = 0;
    while(s)
    {
        count++;
        s = s->next;
    }
    return count;
}

int searchElement(node *s, int element)
{
    while(s)
    {
        if(s->data == element)
        {
            return 1;
        }
        s = s->next;
    }
    return 0;
}

int main()
{
    node *t;
    int a, data, i;
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
        t->prev = w;
        a--;
    }

    do
    {
        printf("Enter\n1 for Display\n2 for insertion at head\n3 for insertion at end\n4 for insertion at index\n5 for deleting head\n6 for deletion of tail\n7 for deleting at index\n8 to delete a key\n9 to count elements\n10 to search an element\n0 to exit\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
        {
            int x;
            printf("Enter 1 for forward 0 for backward: ");
            scanf("%d", &x);
            if (x)
                traversal(head);
            else
                reverseTraversal(head);
            break;
        }
        case 2:
        {
            int x;
            printf("Enter the element to insert: ");
            scanf("%d", &x);
            insertAtHead(x);
            break;
        }
        case 3:
        {
            int x;
            printf("Enter the element to insert: ");
            scanf("%d", &x);
            insertAtTail(head, x);
            break;
        }
        case 4:
        {
            int x, index;
            printf("Enter the element to insert: ");
            scanf("%d", &x);
            printf("Enter the index: ");
            scanf("%d", &index);
            insertAtIndex(head, x, index);
            break;
        }
        case 5:
        {
            deleteHead();
            break;
        }
        case 6:
        {
            deleteTail(head);
            break;
        }
        case 7:
        {
            int index;
            printf("Enter the index you want to delete: ");
            scanf("%d", &index);
            deleteAtIndex(head, index);
            break;
        }
        case 8:
        {
            int key;
            printf("Enter the key you want to delete: ");
            scanf("%d", &key);
            deleteKey(head, key);
        }
        case 9:
        {
            printf("There are %d elements.\n", countNode(head));
        }
        case 10:
        {
            int element, x;
            printf("Enter the element to search: ");
            scanf("%d", element);
            x = searchElement(head, element);
            if(x)
                printf("Element found!\n");
            else
                printf("Element not found!\n");
        }
        }
    } while (i);
    return 0;
}