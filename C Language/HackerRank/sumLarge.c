#include<stdio.h>
int main(){
    int n;
    long  ar[10];
    
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%li",&ar[i]);
    }

    for(int i=0;i<n;i++)
    {
        ar[i+1]=ar[i]+ar[i+1];
    }
    printf("%lli",(long long)ar[n-1]);

    return 0;
}