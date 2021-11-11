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

node *reverseEvenNodes(node *head, node *prev)
{
    if(!head)
        return NULL;
    
    node *current = head;
    node *next = NULL;

    while(current && current->data % 2 == 0)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    if(current != head)
    {
        head->next = current;
        current = reverseEvenNodes(current, NULL);
        return prev;
    }
    else
    {
        head->next = reverseEvenNodes(head->next, head);
        return head;
    }    
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
    printf("List before reversing: ");
    traversal(head);
    head = reverseEvenNodes(head, NULL);
    printf("List after reversing: ");
    traversal(head);
    return 0;
}