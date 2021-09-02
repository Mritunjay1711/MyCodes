#include<stdio.h>
#include<stdlib.h>

typedef struct node{
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
    while (head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

int countNode(node *head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}


void removeDuplicate(node *head)
{
    node *p = head;
    node *q = head->next, *w;
    while(p)
    {
        while(q && p->data != q->data)
        {
            w = q;
            q = q->next;
        }
        if(q == NULL)
        {
            p = p->next;
            if(p != NULL)
            {
                q = p->next;
            }
        }
        else if(p->data == q->data)
        {
            w->next = q->next;
            node *temp = q;
            q = q->next;
            free(temp);
        }
    }
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
        printf("Enter 1 to add node or 0 to stop: ");
        scanf("%d", &a);
    }while(a);

    traversal(head);
    removeDuplicate(head);
    traversal(head);
    return 0;
}