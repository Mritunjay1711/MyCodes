#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack1
{
    int size;
    int top;
    char *arr;
}stack1;

typedef struct stack2
{
    int size;
    int top;
    int *arr;
}stack2;


int isFull1(stack1 s)
{
    return s.top == s.size - 1;
}

int isFull2(stack2 s)
{
    return s.top == s.size - 1;
}

int isEmpty1(stack1 s)
{
    return s.top == -1;
}

int isEmpty2(stack2 s)
{
    return s.top == -1;
}

void push1(stack1 *s, char data)
{
    if(!isFull1(*s))
    {
        s->top++;
        s->arr[s->top] = data;
    }
    else
        printf("Stack overflow!\n");
}

void push2(stack2 *s, int data)
{
    if(!isFull2(*s))
    {
        s->top++;
        s->arr[s->top] = data;
    }
    else
        printf("Stack overflow!\n");
}

char pop1(stack1 *s)
{
    if(!isEmpty1(*s))
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

int pop2(stack2 *s)
{
    if(!isEmpty2(*s))
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
    else
    {
        printf("Stack underflow!\n");
        return -1;
    }
}



char stackTop1(stack1 s)
{
    return s.arr[s.top];
}

int stackTop2(stack1 s)
{
    return s.arr[s.top];
}

int isParanthesis(char ch)
{
    if(ch == '(' || ch == ')')
        return 1;
    else    
        return 0;
}

void ParanthesisCheck(char *eqn)
{
    int i = 0, pos; // keep track of position
    char ch;
    stack1 s1;
    stack2 s2;
    s1.size = s2.size = strlen(eqn);
    s1.top = s2.top = -1;
    s1.arr = (char*)malloc(s2.size * sizeof(int));
    s2.arr = (int*)malloc(s1.size * sizeof(char));

    while(eqn[i] != '\0')
    {
        if(isParanthesis(eqn[i]))
        {
            if(eqn[i] == '(')
            {
                push1(&s1, eqn[i]);
                push2(&s2, i);
                i++;
            }
            else
            {
                if(s1.top != -1 && stackTop1(s1) == '(')
                {
                    ch = pop1(&s1);
                    pos = pop2(&s2);
                }
                else
                    printf("The paranthesis are unbalanced at position %d\n", i);
                i++;
            }
        }
        else
            i++;
    }
    if(s2.top != -1)
    {
        pos = pop2(&s2);
        printf("The expression is unbalanced at %d\n", pos);
    }
}

int main()
{
    char eqn[100];
    printf("Enter the eqn: ");
    gets(eqn);

    ParanthesisCheck(eqn);
    return 0;
}