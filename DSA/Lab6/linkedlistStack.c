#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
}stack;

int isEmpty(stack *q)
{
    return q == NULL;
}

int isFull(stack *q)
{
    stack *temp = (stack*)malloc(sizeof(stack));
    return temp == NULL;
}

void push(stack **q, int data)
{
    if(isFull(*q))
    {
        printf("Stack Overflow!\n");
        printf("Stack Overflow!, Cannot push %d in Stack.\n", data);
    }
    else if(isEmpty(*q))
    {
        *q = (stack*)malloc(sizeof(stack));
        (*q)->data = data;
        (*q)->next = NULL;
        printf("%d pushed!\n", data);
    }
    else
    {
        stack *ptr = (stack*)malloc(sizeof(stack));
        ptr->data = data;
        ptr->next = *q;
        *q = ptr;
        printf("%d pushed!\n", data);
    }
}

int pop(stack **q)
{
    int val = -1;
    stack *temp;
    if(isEmpty(*q))
    {
        printf("Stack Underflow!\n");
        return val;
    }    
    else
    {
        val = (*q)->data;
        temp = *q;
        (*q) = (*q)->next;
        free(temp);
        return val;
    }
}

void traversal(stack *q)
{
    while(q)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

int main()
{
    stack *q = NULL;
    int a;
    do
    {
        printf("Enter\n1 for checking empty or not\n2 for Display the elements\n3 for Push\n4 for Pop\n0 to exit\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
        {
            if(isEmpty(q))
                printf("Stack is empty!\n");
            else
                printf("Stack is not empty!\n");
            break;
        }
        case 2:
        {
            traversal(q);
            break;
        }
        case 3:
        {
            int data;
            printf("Enter the data to push: ");
            scanf("%d", &data);
            push(&q, data);
            break;
        }
        case 4:
        {
            int val = pop(&q);
            printf("Popped %d\n", val);
        }
        }
    }while(a);
    return 0;
}