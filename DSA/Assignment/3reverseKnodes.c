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

node *reverseKnodes(node *head, int k)
{
    if(!head)
        return NULL;
    
    node *current = head;
    node *next = NULL;
    node *prev = NULL;
    int count = 0;
    while(current && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next)
        head->next = reverseKnodes(next, k);
    
    return prev;
    
}

int main()
{
    node* head = NULL;
    int a, data, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &a);

    for(int i = 1; i <= a; i++)
    {
        printf("Enter the data for the node: ");
        scanf("%d", &data);
        createList(&head, data);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("List before reversing: ");
    traversal(head);
    head = reverseKnodes(head, k);
    printf("List after reversing: ");
    traversal(head);
    return 0;
}