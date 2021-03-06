#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp  = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            swap(&arr[i][j], &arr[i][4 - j - 1]);
        }
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}