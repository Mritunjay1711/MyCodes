#include<stdio.h>
int main(){
    int ar[5][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{5,6,7,8,9},{7,8,9,10,11}};
    int sum1=0,sum2=0;

    
  
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i==j)
            sum1=ar[i][j]+sum1;
        }
    }
     int m=5;
     for(int i=0;i<5;i++)
    {
        int j=m-1;
            sum2=ar[i][j]+sum2;
            m--;
    }

     for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf(" %d ",ar[i][j]);
        }
        printf("\n");
    }
    printf("The sums of diagonals are %d and %d.",sum1,sum2);
    return 0;
}