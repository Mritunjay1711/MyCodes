#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
        return 1;
    else return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size - 1)
        return 1;
    else return 0;
}

void push(struct stack *s,int data)
{
    if(!isFull(s))
    {
        s->top++;
        s->arr[s->top] = data;
    }
    else
        printf("Stack Overflow!, Cannot push %d in Stack.\n", data);
    
}

int pop(struct stack *s)
{
    if(!isEmpty(s))
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

int stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int peek(struct stack *s, int i)
{
    int arrInd = s->top - i + 1;
    if(arrInd < 0)
    {
        printf("Invalid Position!");
        return -1;
    }
    else return (s->arr[arrInd]);

}

struct stack sortStack(struct stack *s)
{
    struct stack temp;
    temp.top = -1;
    temp.size = s->size;
    temp.arr = (int*)malloc(temp.size * sizeof(int));
    int tmp;

    while(!isEmpty(s))
    {
        tmp = stackTop(s); 
        pop(s);

        while(!isEmpty(&temp) && stackTop(&temp) > tmp)
        {
            push(s, stackTop(&temp));
            pop(&temp);
        }

        push(&temp, tmp);
    }

    return temp;
}

int main()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int)); 

    push(s, 55);
    push(s, 52);
    push(s, 75);
    push(s, 56);
    push(s, 45);
    push(s, 2);
    
    for(int j = 1; j <= s->top + 1; j++)
    {
        printf("The element at index %d in stack is %d.\n", j, peek(s, j));
    }
    struct stack temp = sortStack(s);
    
    printf("After sorting: \n");
    for(int j = 1; j <= temp.top + 1; j++)
    {
        printf("The element at index %d in stack is %d.\n", j, peek(&temp, j));
    }
    return 0;
}