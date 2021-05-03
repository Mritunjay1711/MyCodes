#include<stdio.h>
int main()
{
    int a[5][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{5,6,7,8,9},{7,8,9,10,11}},rs=0,cs=0;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            rs=rs+a[i][j];
        }
        printf("The sum of %d row is %d\n",i+1,rs);
        rs=0;
    }

     for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cs=cs+a[j][i];
        }
        printf("The sum of %d column is %d\n",i+1,cs);
        cs=0;
    }
    return 0;
    
}