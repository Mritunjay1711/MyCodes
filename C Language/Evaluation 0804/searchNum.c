#include<stdio.h>

int main()
{
    int *ptr,num,flag=0,arr[10]={3,4,6,2,5,10,26,24,54,32};
    ptr=arr+9;

    printf("Enter the element you want to find: ");
    scanf("%d",&num);

    for(int i=0;i<10;i++)
    {
        if(*(ptr-i)==num)
        {
            printf("The number %d is on %d position.",num,10-i);
            flag=1;
        }
    }

    if(!flag)
    printf("Number not found!");
    
    return 0;
}