#include<stdio.h>
int  main()
{
    int x,y,z,n,a[1000][3];

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
     //to find which cat will catch the mouse first or if the mouse can escape
    for(int i=0;i<n;i++)
    {
        
          x=a[i][2]-a[i][1];
          y=a[i][2]-a[i][0];
        
        if(x<0)
        x*=-1;
        if(y<0)
        y*=-1;

        
         if(x<y)
            printf("Cat B\n");
        else if (x>y) 
            printf("Cat A\n");
        else if(x==y)
            printf("Mouse C\n");
    }
   
    return 0;
}