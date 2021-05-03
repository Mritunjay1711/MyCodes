//This Function return max for the first time and
// returns minimum when it is executed for the second time.

#include<stdio.h>

int greater(int a, int b)
{
    if(a>b)
    return a;
    else
    return b;
}

int smaller(int a, int b)
{
    if(a<b)
    return a;
    else 
    return b;
}

int func(int a, int b, int c)
{
    static int i=0;
    i++;
    if(i<=1)
    return greater(a , greater(b,c));
    else
    return smaller(a ,smaller(b,c)); 
}

int main()
{
    int a = 10, b = 2,c=9,d;

    d=func(a, b, c);
    printf("%d\n",d);
    d=func(a, b, c);
    printf("%d\n",d);
    
    return 0;
}