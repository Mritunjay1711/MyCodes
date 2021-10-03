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

void sort(node *head)
{
    node *ptr;
    int temp;
    while(head)
    {
        ptr = head->next;
        while(ptr)
        {
            if(head->data > ptr->data)
            {
                temp = head->data;
                head->data = ptr->data;
                ptr->data = temp;
            }
            ptr = ptr->next;
        }
        head = head->next;
    }
}


//Removing duplicates from Singly Linked list
void removeDuplicate(node *head)
{
    node *r, *prev, *s;
    
    for(r = head; r != NULL; r = r->next)
    {
        prev = r;
        for(s = r->next; s != NULL;)
        {
            if(r->data == s->data)
            {
                prev->next = s->next;
                free(s);
                s = prev->next;
            }
            else
            {
                prev = s;
                s = s->next;
            }
        }
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

    traversal(head);
    removeDuplicate(head);
    traversal(head);
    sort(head);
    traversal(head);
    return 0;
}