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
        printf("%d ---->", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return;
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
        t = (struct node*)malloc(sizeof(struct node));   // Creating memory
        scanf("%d",&t->data);
        t->next = NULL;

        p = head;              //To check from head everytime
        while(p->next)
            p = p->next;
        p->next = t;

        printf("Do you want to add more elements? Enter 1 for yes and 0 for no: ");
        scanf("%d",&a);
    }while(a);

    print(head);
    return 0;
}