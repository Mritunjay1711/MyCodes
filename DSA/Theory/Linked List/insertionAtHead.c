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
node *createNode(int data)
{
    node *p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

void insertAtHead(node **head, int data)
{
    node *in;
    in = createNode(data);
    in->next = *head;
    *head = in;
}

int main()
{
    node* head = NULL, *t;
    int a, data;

    printf("Enter the data for the node: ");
    scanf("%d", &data);
    t = createNode(data);
    head = t;
// |    |--->|    |--->|    |--->|    |--->|    |--->NULL
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
    printf("After adding node\n");
    insertAtHead(&head, 43);
    traversal(head);
    return 0;
}