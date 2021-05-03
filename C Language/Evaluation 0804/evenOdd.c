#include <stdio.h>

int main()
{
    int arr[5] = {3,6,7,2,1};
    int a=0,ar[5];
    
    for (int i=0;i<5;i++)
    {
        if ((*(arr+i)%2)==0)
        {
            *(ar+a)=*(arr+i);
            a++;
        }
    }

    for (int i=0;i<5;i++)
    {
        if ((*(arr+i)%2)==1)
        {
            *(ar+a)=*(arr+i);
            a++;
        }
    }
        
    for (int i=0;i<5;i++)
    {
        printf("%d ",*(ar+i));
    }
    
    return 0;      
}