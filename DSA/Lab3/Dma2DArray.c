#include<stdio.h>
#include<stdlib.h>

// For fix row i.e array of pointers
void createFixRow(int r)
{
    int *arr[r], c;
    printf("Enter the number of column: ");
    scanf("%d", &c);
    for(int i = 0; i < r; i++)
    {
        arr[i] = (int*)malloc(c * sizeof(int));
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("Enter the element arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}

// For fix column i.e pointer to array
void createFixColumn(int c)
{
    int r;
    printf("Enter the number of row: ");
    scanf("%d", &r);
    int (*arr)[c] = (int(*)[])malloc(r * c * sizeof(int));
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("Enter the element arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


// For variable row and columns i.e double pointer
void createVariable(int r, int c)
{
    int **arr = (int**)malloc(r * sizeof(int*));
    for(int i = 0; i < r; i++)
    {
        arr[i] = (int*)malloc(c * sizeof(int));
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("Enter the element arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Driver code
int main()
{
    int a;
    printf("Enter\n1 for fix row\n2 for fix column\n3 for variable row and column\n");
    scanf("%d", &a);

    switch(a)
    {
        case 1:
        {
            int r;
            printf("Enter the number of rows to be fixed: ");
            scanf("%d", &r);
            createFixRow(r);
            break;
        }
        case 2:
        {
            int c;
            printf("Enter the number of columns to be fixed: ");
            scanf("%d", &c);
            createFixColumn(c);
            break;
        }
        case 3:
        {
            int r, c;
            printf("Enter the number of rows: ");
            scanf("%d", &r);
            printf("Enter the number of columns: ");
            scanf("%d", &c);
            createVariable(r, c);
            break;
        }
    }
    return 0;
}