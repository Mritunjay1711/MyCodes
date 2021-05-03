#include<stdio.h>

int main()
{
    int *ptr,od=0,sum=0,count=0,arr[10]={1,3,2,6,4,2,7,11,13,17};
    float aver;
    ptr=arr;

    for(int i=0;i<10;i++)
    {
        if(*(ptr+i)%2==1)
        {
            count++;
            sum+=*(ptr+i);
        }
    }

    aver=sum/10.0;
    printf("There are %d odd numbers.\n",count);
    printf("The sum of odd numbers are %d and average is %.2f. ",sum,aver);
    return 0;
}