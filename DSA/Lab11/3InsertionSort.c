#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *A, int n)
{
    int key, j;

    for(int i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;

        while(j >= 0 && key > A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
       
    }
}

void printArray(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int n, *A;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    A = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        printf("Enter the element A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Before sorting: ");
    printArray(A, n);
    insertionSort(A, n);
    printf("After sorting: ");
    printArray(A, n);     
    return 0;
}