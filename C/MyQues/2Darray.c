#include<stdio.h>

int main()
{
    int n, a[100][100], len = 0, b[100],i = 0;
    printf("Enter the num: ");
    scanf("%d",&n);

    while(n)
    {
        int temp = n % 10;
        b[i] = temp;
        len++;
        n = n / 10;
        i++;
    }

    for(int i = 0; i < len; i++)
    {
        for(int j = i, k = 0; j < len, k < len; j++ , k++)      //Making matrix
        {  
            a[i][j] = b[k];
            a[j][i] = b[k];
        }
    }

     for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
           printf("%d ",a[i][j]);   
        }
        printf("\n");
    }
    return 0;
}