#include<stdio.h>
int main()
{
    int a[5][4],t;
     for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter the a[%d][%d] element",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the number to be multiplied: ");
    scanf("%d",&t);

    for(int j=0;j<4;j++)
    {
        for(int i=0;i<5;i++)
        {
            a[j][i]=a[j][i]*t;
        }
    }

     for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}