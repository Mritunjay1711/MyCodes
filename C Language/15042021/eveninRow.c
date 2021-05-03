#include<stdio.h>

int evenNum(int (*ptr)[5],int n)
{
    int count=0;
    for(int i=0;i<5;i++)
    {
        if(ptr[n][i]%2==0)
        count++;
    }
    return count;
}

int main()
{
    int arr[5][5]={{1,8,6,3,4},{2,3,26,76,7},{3,5,7,8,9},{4,3,2,1,65},{53,52,51,34,45}},n,m;
    int (*ptr)[5];
    ptr=arr;
    printf("Enter the row number you want to check even numbers in:");
    scanf("%d",&n);

    m=evenNum(ptr,n);
    printf("%d even numbers.\n",m);
    return 0;
}