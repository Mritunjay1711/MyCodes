#include<stdio.h>
#include<stdlib.h>

void print(int *arr[], int r)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void scan(int *arr[], int r)
{
    for(int i = 0; i < r; i++)
    {
        printf("Enter the element of row %d:\n", i + 1);
        for(int j = 0; j < r; j++)
        {
            printf("Enter the %d element: ", j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

int sumAboveDiag(int *arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j > i)
            {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

void disBelMinDiag(int *arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j > (n - i - 1))
                printf("%d ", arr[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
}

int prodDiagonal(int *arr[], int n)
{
    int prod = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j || j == n - i - 1)
            {
                prod *= arr[i][j];
            }
        }
    }
    return prod;
}

int main()
{
    int n;
    printf("Enter the number of rows of square matrix: ");
    scanf("%d", &n);
    int *arr[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    scan(arr, n);
    print(arr, n);
    printf("The sum of elements above leading diagonal is: %d\n", sumAboveDiag(arr, n));
    disBelMinDiag(arr, n);
    printf("The product of all the diagonal elements is %d\n", prodDiagonal(arr, n));
    return 0;
}