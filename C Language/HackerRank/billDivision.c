#include<stdio.h>
int main()
{
    int n,k,a[100000],sum=0,b;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&b);

    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
    }                                             //checking if one has to return  the money or not
    sum=sum-a[k];
    sum=sum/2;
    if(sum==b)
    printf("Bon Appetit");
    else 
    printf("%d",b-sum);

    return 0;
}