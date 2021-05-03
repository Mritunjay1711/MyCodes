#include<stdio.h>

int main()
{
    int *ptr3,e=0,a,arr[20];

    ptr3=arr;
    
    for(int i=0;i<10;i++)
    {
        scanf("%d",ptr3+i);
    }

    for(int i=0;i<10;i++)
    {
        if(*(ptr3+i)%2==0)
        e++;
    }

    for(int i=0;i<e;i++)
    {
        for(int j=0;j<10-e;j++)
        {
            if(*(ptr3+i)%2==1 &&*(ptr3+9-j)%2==0)
           { 
               a=*(ptr3+i);
               *(ptr3+i)=*(ptr3+9-j);
               *(ptr3+9-j)=a;
           }
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",*(ptr3+i));
    }
    return 0;
}