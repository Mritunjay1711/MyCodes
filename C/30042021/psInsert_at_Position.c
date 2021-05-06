#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


void print(struct node *p)
{
    while (p)
    {
        printf("%d--->",p->data);
        p = p->next;
    }
    printf("NULL\n");
    return;
    
}


struct node *insert(struct node *p, int n, int a)
{
    int i = 0;
    while(i < n)
    {
        p = p->next;
        i++;
    }
    p->data = a;
    return p;
}

int main()
{
    struct node *head = NULL, *p, *t;
    int a, pos, new_data;
    t = (struct node*)malloc(sizeof(struct node));
    printf("Enter the first element: ");
    scanf("%d",&t->data);
    t->next = NULL;
    head = t;

    do{
        t = (struct node*)malloc(sizeof(struct node));
        printf("Enter the next element: ");
        scanf("%d", &t->data);
        t->next = NULL;

        p = head;
        while (p->next)
            p = p->next;
        p->next = t;
        
        printf("Do you want to continue? Press 1 to yes and 0 for no: ");
        scanf("%d",&a);
    }while(a);

    print(head);

    printf("Enter the position you want to enter the data: ");
    scanf("%d",&pos);
    printf("Enter the data: ");
    scanf("%d",&new_data);
    insert(head, pos, new_data);
    printf("New linked list: ");
    print(head);
    return 0;
}