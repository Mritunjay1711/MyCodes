#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *createList(node **head, int data)
{
    node *temp = *head;
    if(*head == NULL)
    {
        *head = (node*)malloc(sizeof(node));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else
    {
        while(temp->next)
            temp = temp->next;
        
        temp->next = (node*)malloc(sizeof(node));
        temp = temp->next;
        temp->data = data;
        temp->next = NULL;
    }
}

void rearrange(node *head)
{
    int temp;
    while(head->next)
    {
        temp = head->data;
        head->data = head->next->data;
        head->next->data = temp;

        if(head->next->next)
            head = head->next->next;
        else
            return;
    }
}

void traversal(node *head)
{
    while(head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, data;
    node *head = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        createList(&head, data);
    }
    traversal(head);
    rearrange(head);
    traversal(head);

    return 0;
}