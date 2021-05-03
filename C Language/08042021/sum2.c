#include<stdio.h>

int main()
{
    int sum=0,*ptr,ar[5]={5,3,7,2,4};

    ptr=ar+4;
    for(int i=0;i<5;i++)
    {
        sum+=*(ptr-i);
    }
    printf("%d",sum);

    return 0;
}