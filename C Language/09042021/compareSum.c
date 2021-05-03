#include<stdio.h>

int compareSum(int *x,int *y,int n)
{
    int s1=0,s2=0;

    for(int i=0;i<n;i++)
    {
        s1+=x[i];
        s2+=y[i];
    }

    if(s1==s2)
    return 0;
    else if(s1>s2)
    return 1;
    else 
    return 2;
}

int main()
{
    int a[10]={3,6,2,6,57,23,86,23,32,54},b[20]={45,33,21,123,45,56,12,23,45,64},n,c;

    printf("Enter the number of elements to find and compare sum: ");
    scanf("%d",&n);

    c=compareSum(a,b,n);

    if(!c)
    printf("The sum is equal.");
    else if(c==1)
    printf("The sum of first array is greater.");
    else
    printf("The sum of second array is greater.");

    return 0;
}