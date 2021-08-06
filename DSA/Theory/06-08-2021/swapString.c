#include<stdio.h>
#include<stdlib.h>

void f1(char *c1, char *c2)
{
    char *temp;
    temp = c1;
    c1 = c2;
    c2 = temp;
}

void f2(char **c1, char **c2)
{
    char *temp;
    temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

int main()
{
    char *s1 = {"IT"};
    char *s2 = {"CSE"};
    f1(s1, s2);
    printf("%s %s\n", s1, s2);
    f2(&s1, &s2);
    printf("%s %s\n", s1, s2);
    return 0;
}