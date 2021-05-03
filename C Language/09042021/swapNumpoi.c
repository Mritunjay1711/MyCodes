#include<stdio.h>

void swapbyRef(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
    printf("The value of a and b after swapping are %d and %d.",*x,*y);
}

int main()
{
    int a=34,b=54;
    swapbyRef(&a,&b);
    return 0;
}