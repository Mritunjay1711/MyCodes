#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int isEmpty(stack *s)
{
    return s->top == -1;
}

int isFull(stack *s)
{
    return s->top == s->size - 1;
}

void push(stack *s, int data)
{
    if (!isFull(s))
    {
        s->top++;
        s->arr[s->top] = data;
        printf("%d pushed!\n", data);
    }
    else
        printf("Stack Overflow!, Cannot push %d in Stack.\n", data);
}

int pop(stack *s)
{
    if (!isEmpty(s))
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
    else
    {
        printf("Stack Underflow.\n");
        return -1;
    }
}

int stackTop(stack *q)
{
    return q->arr[q->top];
}

void traversal(stack *q)
{
    for(int i = q->top; i >= 0; i--)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main()
{
    stack *q = (stack *)malloc(sizeof(stack));
    q->top = -1;
    printf("Enter the size of stack: ");
    scanf("%d", &q->size);
    q->arr = (int*)malloc(q->size * sizeof(int));

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
            push(q, data);
            break;
        }
        case 4:
        {
            int val = pop(q);
            printf("Popped %d\n", val);
        }

        }
    }while(a);
    return 0;
}