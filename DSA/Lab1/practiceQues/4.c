#include<stdio.h>
#include<stdlib.h>

struct test{
    int i;
    char *c;
}st[] = {5, "become", 4, "better", 6, "jungle", 5, "ancestor", 7, "abc"};

int main()
{
    struct test *p = st;
    p += 1;
    ++p->c;
    printf("%s\n", p++->c);
    printf("%c\n", *++p->c);
    printf("%d\n", p[0].i);
    printf("%s\n", p->c); 
    return 0;
}