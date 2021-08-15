#include<stdio.h>
#include<stdlib.h>

// For user input
void scan(int *arr[], int r)
{
    for(int i = 0; i < r; i++)
    {
        printf("Enter the elements of row %d\n", i + 1);
        for(int j = 0; j < r; j++)
        {
            printf("Enter the element %d :", j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}


//For printing
void print(int *arr[], int r)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    
}

//For counting number of nonzero elements
int countNonZero(int *arr[], int r)
{
    int count = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            if(arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

// For calculating sum of elements above major diagonal
int sumAboveDiagonal(int *arr[], int r)
{
    int sum = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            if(j > i)
            {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}


//For displaying the elements below minor diagonal
void disBelowDiagonal(int *arr[], int r)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            if(j > r - i - 1)
            {
                printf("%2d ", arr[i][j]);
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}


// For calculating product of diagonal elements
int productDiagonal(int *arr[], int r)
{
    int product = 1;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            if(i == j || j == r - i - 1)
            {
                product *= arr[i][j];
            }
        }
    }
    return product;
}

// Driver code
int main()
{
    int r;
    printf("Enter the number of rows for square matrix: ");
    scanf("%d", &r);

    int *arr[r];
    for(int i = 0; i < r; i++)
    {
        arr[i] = (int*)malloc(r * sizeof(int));
    }

    scan(arr, r);
    print(arr, r);

    printf("The number of nonzero numbers in array is %d\n",countNonZero(arr, r));
    printf("The sum of elements above leading diagonal is %d\n", sumAboveDiagonal(arr, r));
    disBelowDiagonal(arr, r);
    printf("The product of diagonal elements is %d\n", productDiagonal(arr, r));
    return 0;
}