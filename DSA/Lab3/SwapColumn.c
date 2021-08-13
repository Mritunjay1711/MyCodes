#include<stdio.h>
#include<stdlib.h>

// For taking input
void scan(int **arr, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("Enter the element arr[%d][%d] :", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}


// For printing
void print(int **arr, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
}

// For swaping two numbers
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// For swaping columns
void swapEvryColumn(int **arr, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c/2; j++)
        {
            swap(&arr[i][j], &arr[i][c - j - 1]);
        }
    }
}

// Driver code
int main()
{
    
    int r, c;
    printf("Enter the number of rows : ");
    scanf("%d", &r);
    printf("Enter the number of column: ");
    scanf("%d", &c);
    int **arr = (int**)malloc(r * sizeof(int*));
    for(int i = 0; i < r; i++)
    {
        arr[i] = (int*)malloc(c * sizeof(int));
    }

    scan(arr, r, c);
    print(arr, r, c);
    swapEvryColumn(arr, r, c);
    print(arr, r, c);
    return 0;
}