#include<stdio.h>

int palindrome(int n)
{
    int sum=0,temp,r;
    temp=n;
        while(n>0)
        {
            r=n%10;
            sum=(sum*10)+r;
            n=n/10;
        }
        
        if(temp==sum)
        return 0;
        else return 1;
}
int main()
{
    int a[5][5],c;
      for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("Enter the a[%d][%d] element",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            c=palindrome(a[i][j]);
            if(c==0)
            printf("%d ",a[i][j]);
        }
    }
    return 0;
}