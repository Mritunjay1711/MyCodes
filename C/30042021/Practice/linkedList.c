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
        printf("%d--->",p->data);
        p = p->next;
    }
    printf("NULL\n");
    return;
}

int main()
{
    struct node *head = NULL, *t,*p;
    int a;
    t = (struct node*)malloc(sizeof(struct node));
    printf("Enter the first element:");
    scanf("%d",&t->data);
    t->next = NULL;

    head = t;
    
    do{
        t = (struct node*)malloc(sizeof(struct node));
        printf("Enter the next data:");
        scanf("%d",&t->data);
        t->next = NULL;
        p = head;
        while(p->next)
        {
            p = p->next;
        }
        p->next = t;
        printf("Do you want to continue? 1 for Yes and 0 for No.");
        scanf("%d",&a);
    }while (a);
    
    print(head);

    return 0;
}