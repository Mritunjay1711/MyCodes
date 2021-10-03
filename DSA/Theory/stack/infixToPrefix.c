#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    int size;
    int top;
    char *arr;
}stack;

int isFull(stack *s)
{
    return s->top == s->size - 1;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

void push(stack *s, char data)
{
    if(!isFull(s))
    {
        s->top++;
        s->arr[s->top] = data;
    }
    else
        printf("Stack overflow!\n");
}

char pop(stack *s)
{
    if(!isEmpty(s))
    {
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
    else
    {
        printf("Stack underflow!\n");
        return '\0';
    }
}

char stackTop(stack s)
{
    return s.arr[s.top];
}

int precedence(char ch)
{
    if(ch == '^')
        return 4;
    else if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else 
        return 0;
}

int isParanthesis(char ch)
{
    if(ch == '(' || ch == ')')
        return 1;
    else    
        return 0;
}

int isOperator(char ch)
{
    if(ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return 1;
    else 
        return 0;
}

char *infixToPrefix(char *infix)
{
    int x = strlen(infix);
    x--;
    char *postfix = (char*)malloc(strlen(infix) * sizeof(char));
    int counter = 0;

    stack *s = (stack*)malloc(sizeof(stack));
    s->size = strlen(infix);
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));
    while(x != -1)
    {
        if(!isOperator(infix[x]) && !isParanthesis(infix[x]))
        {
            postfix[counter++] = infix[x];
            x--;
        }
        else if(isOperator(infix[x]))
        {
            if(precedence(stackTop(*s)) > precedence(infix[x]))
            {
                postfix[counter++] = pop(s);
                push(s, infix[x]);
                x--;
            }
            else
            {
                push(s, infix[x]);
                x--;
            }
        }
        else if(isParanthesis(infix[x]))
        {
            if(infix[x] == '(')
            {
                while(s->arr[s->top] != ')')
                {
                    postfix[counter++] = pop(s);
                }
                x--;
                pop(s);
            }
            else
            {
                push(s, infix[x]);
                x--;
            }
        }
    }
    while(!isEmpty(s))
    {
        postfix[counter++] = pop(s);
    }
    postfix[counter] = '\0';
    return postfix;
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
    char *eqn = (char*)malloc(19 * sizeof(char));
    printf("Enter the eqn: ");
    gets(eqn);
    eqn = infixToPrefix(eqn);
    reverseString(eqn);
    printf("Prefix eqn: %s\n", eqn);
    return 0;
}