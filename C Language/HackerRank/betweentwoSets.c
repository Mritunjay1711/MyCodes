#include<stdio.h>
int main(){
    int a[100],b[100],c[10],n,m,smallest,flag=0;
    scanf("%d %d",&n,&m);  //Input the no of elements in respective array
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);  //No. of elements in array 1
    }

     for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);  //No. of elements in array 2
    }

    smallest=b[0];
    for(int i=0;i<m;i++)
    {
            if(b[i]<smallest)   //finding smallest element in second array
            smallest=b[i]; 
    }
    int i,d=0;

    /*Finding the factors of numbers from second array*/

    for( i=1;i<=smallest;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[j]%i!=0)
            {
                flag=1;
                break;
               
            }
            
        }  
        if(flag==0)
        {
            c[d]=i;
            d++;
        }
        flag=0;

    }
    int num=0,largest=0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]>=largest)          //Findig largest num from first array
        largest=a[i];
    }

    /*Finding the number of elements which are multiple of numbers from array 1 */
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(c[i]%a[j]==0 && c[i]<=smallest && c[i]>=largest)
            flag=0;
            else 
            flag=1;
            if (flag==1)
            {
                break;
            }
            else continue;
            
        }
        if(flag==0)
        num++;
        flag=0;
    }

    printf("%d",num);  //Printing the number of numbers

    return 0;
}