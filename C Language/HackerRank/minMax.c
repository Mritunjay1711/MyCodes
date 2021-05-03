#include<stdio.h>
int main(){
    long int ar[5],a,sum1=0,sum2=0;
    for(int i=0;i<5;i++)
    {
        scanf("%ld",&ar[i]);
    }
    
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(ar[i]>ar[j])                     //sorting of array
           { 
            a=ar[i];
            ar[i]=ar[j];
            ar[j]=a;
           }
        }
    }
   for(int i=1;i<5;i++)
   {
       sum1=ar[i]+sum1;
   }
    for(int i=0;i<4;i++)
   {
       sum2=ar[i]+sum2;
   }
   printf("%ld %ld",sum2,sum1);
    return 0;
}