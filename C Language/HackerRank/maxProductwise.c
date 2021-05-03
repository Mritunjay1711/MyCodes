#include<stdio.h>

int main()
{
    long int n,a[1000];
    long int temp;
    long long int result=0;

    scanf("%ld",&n);

    for(long int i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }

    for(long int i=0;i<n;i++)
    {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        
        
    }
    result=(((long long)a[n-1])*a[n-2]);
    printf("%llu",result);
    return 0;
}