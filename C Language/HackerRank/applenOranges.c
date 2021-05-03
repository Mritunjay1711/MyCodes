#include<stdio.h>
#include<stdlib.h>

int main(){
    long int s,t,a,b,m,n,apple[100000],orange[100000],f1=0,f2=0;

    scanf("%ld %ld",&s,&t); //area of house
    scanf("%ld %ld",&a,&b); //location of trees
    scanf("%ld %ld",&m,&n); //number of respective fruits
    
    //Input of apples
    for(int i=0;i<m;i++)
    {
        scanf("%ld",&apple[i]);
    }
    
    //Input of oranges
    for(int i=0;i<n;i++)
    {
        scanf("%ld",&orange[i]);
    }
    //program to check the number of apple fruits
    for(int i=0;i<m;i++)
    {
        apple[i]+=a;
        if(apple[i]>=s && apple[i]<=t)
        f1++;
    }

    //program to check number of oranges
      for(int i=0;i<n;i++)
    {
        orange[i]+=b;
        if(orange[i]>=s && orange[i]<=t)
        f2++;
    }

    //print respective fruits
    printf("%d\n%d",f1,f2);
    return 0;
}