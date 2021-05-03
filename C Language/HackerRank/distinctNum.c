//To find the distinct numbers in an array
#include<stdio.h>

int main()
{
    int ar[10]={1,2,2,3,5,5,6,4,2,3};
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(ar[i]==ar[j])
            {
                break;
            }
        }
        if(i==j)
        printf("%d ",ar[i]);
    }
}