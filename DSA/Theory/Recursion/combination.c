#include<stdio.h>
#include<stdlib.h>

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}

int combination(int n, int r)
{
    return(factorial(n)/(factorial(r)*factorial(n - r)));
}

int main()
{
    printf("%d\n", combination(4, 2));
    return 0;
}