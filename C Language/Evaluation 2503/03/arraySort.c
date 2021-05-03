#include<stdio.h>
int main()
{
int a[5][5]={{2,4,1,3,5},{7,8,6,10,9},{15,13,14,12,11},{20,16,19,18,17},{25,24,22,21,23}},temp;

for(int k=0; k< 5; k++) 
{
   for (int i = 0; i < 5; i++) 
   {
     for (int j = i +1; j < 5; ++j) 
     {
       if (a[k][i] > a[k][j])  
       {
            temp = a[k][i];
           a[k][i] = a[k][j];
           a[k][j] = temp;
       }
     }
   } 
}

 for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<5;j++)
        {
           int  t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
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