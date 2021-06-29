#include<stdio.h>

int reverse(int n)
{
    int remainder=0,num = 0;

    while(n)
    {
        remainder = n % 10;
        num= num * 10 + remainder;
        n /= 10;
    }

    return num;
}

int prime(int n)
{
    int flag=1;
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            flag=0;
            break;
        }
    }
    if(flag)
    return 1;
    else
    return 0;

}


int main()
{
    int a,b;

    printf("Enter the range: ");
    scanf("%d %d",&a, &b);

    for(int i = a; i <= b; i++)
    {
        if(prime(i))
        {
            printf("%d ",reverse(i));
        }
    }
    
    return 0;
}