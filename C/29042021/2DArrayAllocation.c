#include<stdio.h>
#include<stdlib.h>
#define col 5

int main()
{
    int n, i, sum = 0;
    int (*a)[col];
    printf("Enter number of rows: ");
    scanf("%d", &n);
    a = (int (*)[col]) malloc(n* col* sizeof(int));
    for(i = 0; i < n; i++)
    {
        for (int j = 0; j < col; ++j)
        { 
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }
    }
    printf("%d\n",sum); 
    return 0;
}