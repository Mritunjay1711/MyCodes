#include<stdio.h>
#include<stdlib.h>


int main()
{
    int a[] = {2, 5, 6, 9, 10};
    int b[] = {1, 3, 6, 23, 32};
    int *x[2] = {a, b};
    int **p = x;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    return 0;
}