#include<stdio.h>
int main()
{
    int n,p,c=0,b=0,a=1;
    scanf("%d %d",&n,&p);


    //counting the least number of pages to reach the desired page
    while(a<p)
    {
        a+=2;
        c++;
    }

    if(n%2==0)
    {
        a=n;
        while (a>p)
        {
            a-=2;
            b++;
        }
    }
    else 
    {
        a=n-1;
        while (a>p)
        {
            a-=2;
            b++;
        }
    }
    printf("%d",c<b?c:b);

    return 0;
}