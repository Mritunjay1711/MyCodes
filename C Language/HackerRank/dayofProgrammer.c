#include<stdio.h>

int leap(int n)
{
    if(n%4==0 && n%100!=0)
    return 1;
    else if(n%400==0)
    return 1;
    else return 0;
}

int julianLeap(int n)
{
    if(n%4==0)
    return 1;
    else return 0;
}

int main()
{
    int c,n;
    scanf("%d",&n);
    if (n<1918)
        c=julianLeap(n);
    else if(n>1918)
        c=leap(n);
    else if(n==1918)
        c=1918;
    
    if(c==1)
    printf("12.09.%d",n);
    else if(c==0)
    printf("13.09.%d",n);
    else if(c==1918)
    printf("26.09.1918");
   
    
    return 0;
}