#include<stdio.h>

void increment()
{
    auto int m=1;
    printf("%d\n",m);
    m++;
}

int main()
{
    increment();
    increment();
    increment();
    return 0;
}