#include<stdio.h>
int main()
{
    int a[5][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{5,6,7,8,9},{7,8,9,10,11}};
    int t;

    printf("Enter the number you want to multiply in diagonal: ");
    scanf("%d",&t);

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i==j)
            a[i][j]*=t;
        }
    }

      for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}