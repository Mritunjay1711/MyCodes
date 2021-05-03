#include<stdio.h>
int main(){
    int a[3],b[3],c=0,d=0;
    for(int i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
    }

     for(int i=0;i<3;i++)
    {
        scanf("%d",&b[i]);
    }

    for(int i=0;i<3;i++)
    {
        if(a[i]>b[i])
        c=c+1;
        else if(a[i]<b[i]) 
        d=d+1;
        
    }
    printf("%d %d",c,d);

    return 0;
}