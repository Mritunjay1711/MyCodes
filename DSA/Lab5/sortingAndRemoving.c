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
    node *r = s, *w;
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

// void sort(node *s)
// {
    
//     int swapped, i;
//     node *w;
  
//     if (s == NULL)
//         return;
  
//     do
//     {
//         swapped = 0;
//         w = s;
  
//         while (w->next != NULL)
//         {
//             if (w->data > w->next->data)
//             {
//                 int temp = w->data;
//                 w->data = w->next->data;
//                 w->next->data = temp;
//                 swapped = 1;
//             }
//             w = w->next;
//         }
//     }
//     while (swapped);
// }

void sort(node *head)
{
    node *ptr;
    int temp;
    while(head)
    {
        ptr = head->next;
        while(ptr)
        {
            if(head->data > ptr->data)
            {
                temp = head->data;
                head->data = ptr->data;
                ptr->data = temp;
            }
            ptr = ptr->next;
        }
        head = head->next;
    }
}

// Removing duplicates from doubly linked list
void removeDuplicate(node *head)
{
    node *r, *prev, *s;
    
    for(r = head; r != NULL; r = r->next)
    {
        prev = r;
        for(s = r->next; s != NULL;)
        {
            if(r->data == s->data)
            {
                prev->next = s->next;
                s->next->prev = prev;
                free(s);
                s = prev->next;
            }
            else
            {
                prev = s;
                s = s->next;
            }
        }
    }
    
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
    sort(head);
    traversal(head);
    removeDuplicate(head);
    // printf("%d\n", head->next->next->prev->data);
    traversal(head);
    return 0;
}