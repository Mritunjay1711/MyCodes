#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
    int size;
    int top;
    char *arr;
}stack;

int isEmpty(stack *s)
{
    return (s->top == -1);
}

int isFull(stack *s)
{
    return (s->top == s->size - 1);
}

void push(stack *s, char ch)
{
    if(isFull(s))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = ch;
    }
}

char pop(stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack UnderFlow!\n");
    }
    else
    {
        return s->arr[s->top--];
    }
}

void reverseString(char *st)
{
    stack s;
    s.size = strlen(st);
    s.top = -1;
    s.arr = (char*)malloc(s.size * sizeof(char));
    int i = 0;
    while (st[i] != '\0')
    {
        push(&s, st[i]);
        i++;
    }
    i = 0;
    while(i != strlen(st))
    {
        st[i] = pop(&s);
        i++;
    }
}

int main()
{
    char string[30];
    printf("Enter the string to reverse: ");
    gets(string);
    printf("%s\n", string);   

    reverseString(string);
    printf("%s\n", string);   
    return 0;
}