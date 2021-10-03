#include<stdio.h>
#include<stdlib.h>

typedef struct dllNode
{
    struct dllNode *prev;
    int data;
    struct dllNode *next;
}dllNode;

void traversal(dllNode *head)
{
    printf("NULL ");
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void createList(dllNode **head, int data)
{
    dllNode *r = *head, *w;
    if (r == NULL)
    {
        r = (dllNode *)malloc(sizeof(dllNode));
        r->data = data;
        r->prev = NULL;
        r->next = NULL;
        *head = r;
    }
    else
    {
        w = (dllNode *)malloc(sizeof(dllNode));
        w->data = data;
        w->next = NULL;
        w->prev = NULL;
        while (r->next)
            r = r->next;
        r->next = w;
        w->prev = r;
    }
}

void reverseList(dllNode **head)
{
    dllNode *temp = NULL;
    dllNode *curr = *head;

    while(curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    if(temp != NULL)
    {
        *head = temp->prev;
    }
}

int main()
{
     int n, data;
    dllNode *head = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        createList(&head, data);
    }
    traversal(head);
    reverseList(&head);
    traversal(head);
    return 0;
}