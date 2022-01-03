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

void BubbleSort(node *head , int n)
{
    node *ptr, *tmp = head;
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        ptr = tmp;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(ptr->data > ptr->next->data)
            {
                // printf("Wroking\n");
                temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        if(!swapped)
            break;
    }
}


int main()
{
    node* head = NULL, *t;
    int a, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &a);

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
        a--;
    }while(a - 1);

    int n = countNode(head);
    printf("List before sorting: ");
    traversal(head);
    BubbleSort(head, n);
    printf("List after sorting: ");
    traversal(head);
    return 0;
}