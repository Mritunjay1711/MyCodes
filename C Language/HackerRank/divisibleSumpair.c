#include<stdio.h>

int main()
{
    int n,k,a[100],count=0;
    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((a[i]+a[j])%k==0)
            {
                count++;
            }
        }
    }

    printf("%d",count);

    return 0;
}