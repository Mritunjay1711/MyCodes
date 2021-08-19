#include<stdio.h>
#include<stdlib.h>

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}

int permutation(int n, int r)
{
    return(factorial(n)/factorial(n - r));
}

int main()
{
    printf("%d\n", permutation(4, 2));
    return 0;
}