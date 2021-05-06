#include<stdio.h>

void sum(int a,int b)
{
    int temp = a;
    a =  temp + b;
}

void sum2(int *a, int *b)
{
    int temp = *a;
    *a = temp + *b;
}

int main()
{
    int a = 5, b = 4;
    sum(a, b);
    printf("%d \n",a);

    sum2(&a, &b);
    printf("%d \n",a);
    return 0;
}
