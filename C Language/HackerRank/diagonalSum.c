#include<stdio.h>
int main(){
    int ar[100][100];
    int n,sum1=0,sum2=0,difference;

    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    } 

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            sum1=ar[i][j]+sum1;
        }
    }
     int m=n;
     for(int i=0;i<n;i++)
    {
        int j=m-1;
            sum2=ar[i][j]+sum2;
            m--;
    }
    
    difference=sum1-sum2;
    if(difference>0)
    printf("%d",difference);
    else printf("%d",-1*difference);
   
    return 0;
}