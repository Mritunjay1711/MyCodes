#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    for(int i = 0; i < n / 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j == (n / 2) - i || j == (n / 2) + i || j == (n / 2))
                printf("*");
            else
                printf(" ");

        }
        printf("\n");
    }
    for(int j = 0; j < n; j++)
    {
        printf("*");
    }
    printf("\n");
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
        {
            if(j == (n / 2) - i || j == (n / 2) + i  || j == n / 2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}