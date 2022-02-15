#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int l = 2 * n;
    int j, k;
    for(int i = 0; i < n; i++)
    {
        for(j = 0; j < n - i; j++)
        {
            printf("* ");
        }
        for(j = 0; j < 2*i; j++)
        {
            printf(" ");
        }
        for(k = 0; k < 2*i; k++)
        {
            printf(" ");
        }
        for(k = 0; k < n - i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}