#include<stdio.h>
int main(){
    int n,ar[100],a=0,b=0,c=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(ar[i]>0)
        a++;
        else if(ar[i]<0)
        b++;
        else c++;
    }
    printf("%f\n%f\n%f\n",(float)a/n,(float)b/n,(float)c/n);

    return 0;
}