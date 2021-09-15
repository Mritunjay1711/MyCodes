#include<stdio.h>
#include<stdlib.h>

struct point{
    int x; 
    int y;
};


struct point fun = {3, 7};

struct point *p = &fun;

int main()
{
    int y = 4;
    int x = 0;

    (*p).x = 8;
    p->x = 8;
    x = x + (*p).y + p->x;
    printf("%d %d\n", x, p->x);
    
    return 0;
}