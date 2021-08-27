#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

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
        head = head->next;
        count++;
    }
    return count;
}

node *createNode(int data)
{
    node *p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

node *insertAtIndex(node *head, int data, int index)
{
    node *in, *q = NULL, *p = head;
    in = createNode(data);

    if(index < 1 && index > countNode(head))
    {
        printf("Invalid index!\n");
        return head;
    }

    if(index == 1)
    {
        in->next = head;
        head = in;
        return head;
    }
    else
    {
        for(int i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        in->next = q->next;
        q->next = in;
        return head;
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
    int index, value;
    printf("Enter the value you want to enter: ");
    scanf("%d", &value);
    printf("Enter the index: ");
    scanf("%d", &index);
    printf("After adding node\n");
    head = insertAtIndex(head, value, index);
    traversal(head);
    return 0;
}