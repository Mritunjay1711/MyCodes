#include<stdio.h>

int prime(int n)
{
    int flag=0;
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    return 1;
    else
    return 0;

}

int reverse(int n)
{
    int remainder=0,num;

    while(n)
    {
        remainder = n % 10;
        num= num * 10 + remainder;
        n /= 10;
    }

    return num;
}

int func(int n)
{
    int b,c;
    b=prime(n);
    c=prime(reverse(n));
    if(b && c)
    return 1;
    else
    return 0;
}

int main()
{
    int a=11;
    printf("%d\n",func(17));
    printf("%d\n",func(38));
    return 0;
}