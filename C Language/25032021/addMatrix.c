#include<stdio.h>
int main ()
{
    int a[5][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6},{5,6,7,8},{7,8,9,10}};
    int b[5][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6},{5,6,7,8},{7,8,9,10}};

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            a[i][j]+=b[i][j];
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
}