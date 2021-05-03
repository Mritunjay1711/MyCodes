#include<stdio.h>
int main(){
    int arr[1000];
    unsigned int n;
    int smallest=0,largest=0,a=0,b=0;
    
    scanf("%d",&n);    //To take number of inputs
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);      //To take input
    }

    smallest=arr[0];
    largest=arr[0];
    

    for(int i=1;i<n;i++)
    {
        if (arr[i]<smallest)
        {
            smallest=arr[i];           //To find the number lowest scores
            a++;
        }
        
        if(arr[i]>largest)
        {
            largest=arr[i];           //To find the number of highest scores
            b++;
        }
    }
    printf("%d %d",b,a);
    return 0;
}