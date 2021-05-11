#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char num[20];
    int n,len, b[40], a[40][40];
    gets(num);
    len = strlen(num);
    n = atoi(num);

    for(int i = 0 ; i < len; i++)
    {
        int temp = n % 10;
        b[i] = temp;
        n /= 10;
    }
    // Checking loop
    // for(int i = 0; i < 2*len; i++)
    // {
    //     printf("%d",b[i]);
    // }
    // printf("\n");
    for(int i = 0; i < len; i++)
    {
        for(int j = (len - 1 - i), k = 0; j >= 0 , k < len; j--, k++)
        {
            a[i][j] = b[k];
            a[len - j - 1][len - i - 1] = b[k];
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