#include<stdio.h>
int main()
{
    int n,a[100],b[100],count=1,flag,c=0;

    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        
        b[i]=-1;
    }
    

    //counting the number of pairs that can be sold
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;

                b[j]=0;
            }
        }
        if(b[i]!=0)
        {
            b[i]=count;
        }
        
         count=1;
    }

    for(int i=0;i<n;i++)
    {
        if(b[i]!=0)
        {
            c=c+(b[i]/2);
        }
    }
    printf("%d",c);
    
    return 0;
}