#include<stdio.h>

int main()
{
    int n,n2,a[20], len = 0,b[20],c = 0;
    scanf("%d", &n);
    n2 = n;
    while(n2)
    {
        n2 /= 10;
        len++;
    }
    

    for(int i = len -1; i >= 0; i--)
    {
        int temp = n % 10;    
        a[i] = temp;
        n /= 10;
    }
    
    for(int i = 0; i < len; i++)
    {
        int flag = 1;
        for(int j = i + 1; j < len; j++)
        {
            if(a[i] == a[j])
            {
                flag = 0;
                break;
            }
            
        }
        
        if(flag == 1)
        {
            b[c] = a[i];
            c++;
        }
        
    }
    
    for(int i = 0; i < c; i++)
    {
        printf("%d",b[i]);
    }
    return 0;
}