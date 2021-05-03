#include<stdio.h>
int main()
{
    int n,u=0,d=0;
    char a[1000000];

    scanf("%d",&n);

    for(int i=0;i<=n;i++)
    {
        scanf("%c",&a[i]);
       
    }

    
    //finding number of valleys during hike
    for(int i=0;i<=n;i++)
    {
     if(a[i]=='U')
        u+=1;
    else if(a[i]=='D')
        u-=1;

    
     if (u==-1 && a[i+1]=='U')
     d++;
    }
  
    printf("%d",d);
    return 0;
}