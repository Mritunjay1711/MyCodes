#include<stdio.h>

int freqNum(int *ptr,int n)
{
    int count=0;
    for(int i=0;i<25;i++)
    {
        if(ptr[i]==n)
        count++;
    }
    return count;
}

int main()
{
    int arr[25]={1,8,6,3,4,2,3,26,76,7,3,5,7,8,9,4,3,2,1,65},n,m;
    int *ptr;
    ptr=arr;

    printf("Enter the number you want to search in array:");
    scanf("%d",&n);

    m=freqNum(ptr,n);
    if(m)
    printf("%d is %d times in array.\n",n,m);
    else
    printf("Number not found!");
    
    return 0;
}