#include<stdio.h>
#include<stdlib.h>

struct node{
    int i;
    int *c;
};

int main()
{
    printf("Hello!\n");
    int x, y, z, r, s, t, u;
    struct node a[2], *p;
    int b[2] = {30, 40};
    p = &a[0];
    a[0].i = 10;
    a[1].i = 20;
    a[0].c = b;
    x = (++p)->i;
    y = (++p)->i;
    z = (p++)->i;
    r = *p->c;
    s = *p->c++;
    t = (*p->c)++;
    u = (p++)->i;
    printf("x = %d\ny = %d\nz = %d\nr = %d\ns = %d\nt = %d\nu = %d\n", x, y, z, r, s, t, u);
   
    
    return 0;
}