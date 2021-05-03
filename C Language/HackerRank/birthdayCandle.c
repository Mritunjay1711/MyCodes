#include<stdio.h>
int main(){
    int x,ar[100000],a=0,b=0;
    scanf("%d",&x);

    for(int i=0;i<x;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(int i=0;i<x;i++)
    {
      if(ar[i]>a)
      a=ar[i];
    }   
    int flag=0;
    for(int i=0;i<x;i++)
    {
        if(ar[i]==a)
        flag++;
    }
    printf("%d",flag);

    return 0;
}