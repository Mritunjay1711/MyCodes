#include<stdio.h>

int square(int *n)
{
    int a=*n**n;
    return a;
}

int main()
{
    int a=10;
    a=square(&a);
    printf("%d",a);
    return 0;
}