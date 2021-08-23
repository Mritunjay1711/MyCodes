#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct stack
{
  int size;
  int top;
  char * arr;
};
void push(struct stack **s,char data)
{ 
    if(is_full(*s))
    printf("\nStack Overflow!!");
    else
    {   (*s)->top++;
         (*s)->arr[(*s)->top] = data;
    }
}
char pop(struct stack **s)
{
    if(is_empty(*s))
     printf("Stack Overflow!!");
     else
     {
         char val = (*s)->arr[(*s)->top];
          (*s)->top--;
          return val;
     }
}
int is_empty(struct stack*s)
{
    if(s->top == -1)
    return 1;
    return 0;
}
int is_full(struct stack *s)
{
    if(s->top == s->size -1)
    return 1;
    return 0;
}
char stack_top(struct stack*s)
{
    return s->arr[s->top];
}
int is_operator(char a)
{
    if(a == '+' || a == '-' || a == '/' || a == '*')
     return 1;
     else
     return 0;
}
int precedence(char a)
{
    if(a == '-' ||  a == '+')
    return 2;
   if(a == '*' || a == '/' )
    return 3;
    else 
    return 0;
} 
char * infix_to_postfix(char *infix)
{
    struct stack *s1;
    s1 = (struct stack*)malloc(sizeof(struct stack));
    s1->size = 100;
    s1->top = -1;
    s1->arr = (char*)malloc(s1->size*sizeof(char));
    char * postfix = (char*)malloc(strlen(infix +1)*sizeof(char));
    int i = 0;
    int j = 0;
    while(infix[i] != '\0')
    {
        if(!is_operator(infix[i]))
        {
           postfix[j] = infix[i];
           i++;
           j++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stack_top(s1)))
            {
                push(&s1,infix[i]);
            i++;
            }
            else 
            {
                postfix[j] = pop(&s1);
                j++;
            }

        }
    }
             while(!is_empty(s1))
             {   
                 postfix[j] = pop(&s1);
                 j++;
             }
            
            postfix[j] = '\0';
             
             return postfix;

}
int main()
{
    char *infix,*postfix;
    infix= (char*)malloc(40*sizeof(char));
    printf("\nEnter the expression ");
    scanf("%s",infix);
    postfix = infix_to_postfix(infix);
    printf("\n %s",postfix);
}