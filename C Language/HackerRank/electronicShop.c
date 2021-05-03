#include<stdio.h>
int main()
{
    int m,n,b,max=0,k[100000],a[100000];
    scanf("%d %d %d",&b,&m,&n);

    for(int i=0;i<m;i++)
    {
        scanf("%d",&k[i]);
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(k[i]+a[j]>max && k[i]+a[j]<=b)           //finding maximum amount that can be spent to buy
            {
                max=k[i]+a[j];
                
            }
           
        }
    }
   
    printf("%d",max==0?-1:max);
}