#include<stdio.h>
int main()
{
    int a[4][5];

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("Enter the a[%d][%d] element",i,j);
            scanf("%d",&a[i][j]);
        }
    }

     for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}