#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void createList(node **head, int data)
{
    node *r = *head, *ptr;
    if(r == NULL)
    {
        r = (node*)malloc(sizeof(node));
        r->data = data;
        r->next = NULL;
        *head = r;
    }
    else
    {
        while(r->next)
            r = r->next;
        ptr = (node*)malloc(sizeof(node));
        ptr->data = data;
        ptr->next = NULL;
        r->next = ptr;
    }
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

void removeDuplicate(node *head)
{
    node *p = head;
    node *q = head->next, *w, *temp;
    while(p->next)
    {
        w = p;
        q = p->next;
        while(q)
        {
            if(p->data == q->data)
            {
                w->next = q->next;
                temp = q;
                q = q->next;
                free(temp);
            }
            else
            {
                w = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

int main()
{
    node* head = NULL, *newList;
    int a, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &a);

    for(int i = 1; i <= a; i++)
    {
        printf("Enter the data for the node: ");
        scanf("%d", &data);
        createList(&head, data);
    }

    traversal(head);
    // printf("%u\n", head);
    removeDuplicate(head);
    // printf("%u\n", head);
    traversal(head);
    
    return 0;
}