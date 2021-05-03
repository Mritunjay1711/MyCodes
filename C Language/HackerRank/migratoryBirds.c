#include<stdio.h>

int main ()
{
    int count=0,n,a[200000],c=0,flag;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;
            }
        }
        if(count>c)
        {
            c=count;
            flag=a[i];
        }
        else if(count==c && flag>a[i])
        {
            c=count;
            flag=a[i];
        }
       
        count=0;
    }
    printf("%d",flag);
    return 0;
}