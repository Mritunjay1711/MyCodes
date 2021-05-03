#include<stdio.h>
#include<stdlib.h>
int main(){
    int ar[5],x,temp,a,b;
    scanf("%d",&x); //To take the number
    for(int i=0;i<5;i++)
    {
        scanf("%d",&ar[i]);   //to take array
    }

    /*arranging in descending order according to absolute
    difference*/
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)  
        {                        
            a=abs(x-ar[i]);
            b=abs(x-ar[j]);

            if(a<b)
            {
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }

    //print array
      for(int i=0;i<5;i++)
    {
        printf("%d ",ar[i]);
    }
    return 0;
}