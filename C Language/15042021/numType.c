#include<stdio.h>

int evenNum(int *ptr)
{
    int count=0;
    for(int i=0;i<25;i++)
    {
        if(ptr[i]%2==0)
        count++;
    }
    return count;
}

int oddNum(int *ptr)
{
    int odd=0;
    for(int i=0;i<25;i++)
    {
        if(ptr[i]%2==1)
        odd++;
    }
    return odd;
}

int posNum(int *ptr)
{
    int pos=0;
    for(int i=0;i<25;i++)
    {
        if(ptr[i]>0)
        pos++;
    }
    return pos;
}

int negNum(int *ptr)
{
    int neg=0;
    for(int i=0;i<25;i++)
    {
        if(ptr[i]<0)
        neg++;
    }
    return neg;
}

int main()
{
    int arr[25]={1,8,6,3,4,2,3,26,76,7,3,5,7,8,9,4,3,2,1,65,-2,-4,-4,-6,-19},o,e,p,n;
    int *ptr;
    ptr=arr;

    e=evenNum(ptr);
    o=oddNum(ptr);
    p=posNum(ptr);
    n=negNum(ptr);
    if(e)
    printf("There are %d even numbers.\n",e);
    else
    printf("No even numbers!");
     if(o)
    printf("There are %d odd numbers.\n",o);
    else
    printf("No odd numbers!");
     if(p)
    printf("There are %d positive numbers.\n",p);
    else
    printf("No pos numbers!");
     if(n)
    printf("There are %d negative numbers.\n",n);
    else
    printf("No negative numbers!");
    return 0;
}