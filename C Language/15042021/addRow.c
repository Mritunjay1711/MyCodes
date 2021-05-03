#include<stdio.h>

void add_mat_row(int (*pa)[5],int *pb)
{
     for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        pb[i]=pb[i]+pa[i][j];
    }
}
int main()
{
    int a[4][5]={{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}},b[4]={0,0,0,0};
    int (*pa)[5],*pb;
    pa=a;
    pb=b;
   
    add_mat_row(pa,pb);
    for(int i=0;i<4;i++)
    {
        printf("%d\n",pb[i]);
    }
    return 0;
}