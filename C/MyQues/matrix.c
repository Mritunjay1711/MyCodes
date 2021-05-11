#include<stdio.h>
#include<math.h>

int diagonalSum(int *a, int row, int column)
{
    
}

int main()
{
    int b[100][100], r,c;
    printf("Enter the number of rows: ");
    scanf("%d",&r);
    printf("Enter the numbers of column: ");
    scanf("%d", &c);

    if( r == c)
    {
        for(int i = 0; i < r; i++)
        {
            printf("Enter the elements of %d row:", i + 1);
            for( int j = 0; j < c; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }

        int sum = 0;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if( i == j)
                {
                    sum += b[i][j];
                }
            }
        }

        for(int i = 0; i < r; i++)
        {
            sum += b[i][c-1];
            c--;
        }

        printf("%d\n", sum);
    }
    else
    printf("It is not a square matrix.");
    return 0;
}