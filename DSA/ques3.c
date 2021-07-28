#include<stdio.h>

void sum()
{
    int a = 10;
    static int b = 20;
    printf("%d %d\n", a, b);
    a++;
    b++;
}

void main()
{
    int x;
    for(x = 1; x < 4; x++)
    {
        sum();
    }
}