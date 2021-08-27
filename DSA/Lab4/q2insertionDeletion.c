#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;

node *createNode(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

int countNode(node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
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

void insertAtHead(node **head, int data)
{
    node *in;
    in = createNode(data);
    in->next = *head;
    *head = in;
}

void insertAtEnd(node *head, int data)
{
    node *in;
    in = createNode(data);
    if(head == NULL)
        printf("List is empty!\n");
    while(head->next)
    {
        head = head->next;
    }
    head->next = in;
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

node *deleteAtIndex(node *head, int index)
{
    node *in, *q = NULL, *p = head;

    if(index < 1 && index > countNode(head))
    {
        printf("Invalid index!\n");
        return head;
    }

    if(index == 1)
    {
        in = head;
        head = head->next;
        free(in);
        return head;
    }
    else
    {
        for(int i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        in = p;
        q->next = p->next;
        free(in);
        return head;
    }
     
}

void deleteHead(node **head)
{
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteTail(node *head)
{
    node *temp;
    while(head->next)
    {
        temp = head;
        head = head->next;
    }
    temp->next = NULL;
    free(head);
    
}



int main()
{
    node *t;
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

    int i;
    
    do
    {
        printf("Enter\n1 for Display\n2 for insertion at head\n3 for insertion at end\n4 for insertion at index\n5 for deleting head\n6 for deletion of tail\n7 for deleting at index\n0 to exit\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
        {
            traversal(head);
            break;
        }
        case 2:
        {
            int x;
            printf("Enter the element to insert: ");
            scanf("%d", &x);
            insertAtHead(&head, x);
            break;
        }
        case 3:
        {
            int x;
            printf("Enter the element to insert: ");
            scanf("%d", &x);
            insertAtEnd(head, x);
            break;
        }
        case 4:
        {
            int x, index;
            printf("Enter the element to insert: ");
            scanf("%d", &x);
            printf("Enter the index: ");
            scanf("%d", &index);
            head = insertAtIndex(head, x, index);
            break;
        }
        case 5:
        {
            deleteHead(&head);
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
            head = deleteAtIndex(head, index);
            break;
        }
        default:
        {
            printf("Invalid input!\n");
        }
        }
    } while (i);
    
    return 0;
}