#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


void print(struct node *p)
{
    while(p)
    {
        printf("%d -- %p---->", p->data, &p->data);
        p = p->next;
    }
    printf("NULL\n");
    return;
}

struct node *largest(struct node *p)
{
    struct node *a;
    a = (struct node*)malloc(sizeof(struct node));
    a->data = -1;
    
    while(p)
    {
        if(a->data < p->data)
        {
            a->data = p->data;
        }
        p = p->next;
    }
    
    return a;

}

int *largestAddress(struct node *p)
{
    int *largest, large = -1;
    while(p)
    {
        if(large < p->data)
        {
            large = p->data;
            largest = &p->data;
        }
        p = p->next;
    }
    return largest;
}

int main()
{
    struct node *head = NULL, *p, *t;
    int a;
    t = (struct node*)malloc(sizeof(struct node));
    printf("Enter the first data: ");
    scanf("%d",&t->data);
    t->next = NULL;
    head = t;
    
    do {
        t = (struct node*)malloc(sizeof(struct node));
        printf("Enter the next element: ");
        scanf("%d",&t->data);
        t->next = NULL;

        p = head;
        while(p->next)
            p = p->next;
        p->next = t;

        printf("Do you want to add more elements? Enter 1 for yes and 0 for no: ");
        scanf("%d",&a);
    }while(a);

    print(head);



    struct node *q;
    int *address;
    address = largestAddress(head);
    q = largest(head);
    printf("The largest data in link list is %d and at address %p.\n",q->data, address);
    return 0;
}