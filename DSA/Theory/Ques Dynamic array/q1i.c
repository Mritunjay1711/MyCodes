#include<stdio.h>
#include<stdlib.h>

void print(int (*arr)[5], int r)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void scan(int (*arr)[5], int r)
{
    for(int i = 0; i < r; i++)
    {
        printf("Enter the element of row %d:\n", i + 1);
        for(int j = 0; j < 5; j++)
        {
            printf("Enter the %d element: ", j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

int main()
{
    int r, (*q)[5];
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    q = (int(*)[])malloc(r * 5 * sizeof(int));
    scan(q, r);
    print(q, r);
    return 0;
}