#include<stdio.h>

int main()
{
    int *ptr1,*ptr2,*ptr3,arr1[5]={3,5,2,7,8};
    int arr3[10],arr2[5]={5,9,10,15,14};
    ptr1=arr1;
    ptr2=arr2;
    ptr3=arr3;

    for(int i=0;i<5;i++)
    {
        *(ptr3+i)=*(ptr1+i);
        
    }
    for(int i=0;i<5;i++)
    {
        *(ptr3+5+i)=*(ptr2+i);
    }
    
    for(int i=0;i<10;i++)
    {
        printf("%d ",*(ptr3+9-i));
    }

    return 0;
}