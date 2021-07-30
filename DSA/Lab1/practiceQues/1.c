#include<stdio.h>
#include<stdlib.h>

struct demo{
    char p, q, r;
};


void main()
{
    struct demo d = {'5', '0', 'b' + 2};
    struct demo *e = &d;
    printf("%c %c\n", *((char*)e+1), *((char*)e + 2));
}