#include<stdio.h>

typedef struct 
{
    char *a;
    char *b;
}t;

void f1(t s);
void f2(t *p);

void main()
{
    static t s = {"A", "B"};
    printf ("%s %s\n", s.a, s.b); //A B
    f1(s); // U V
    printf ("%s %s\n", s.a, s.b); //A B
    f2(&s);
}

void f1(t s) //Pass by value
{
    s.a = "U";
    s.b = "V";
    printf ("%s %s\n", s.a, s.b); //U V
    return;
}

void f2(t *p)
{
    p->a  = "V";
    p->b = "W";
    printf("%s %s\n", p->a, p->b); //V W
    return;
}