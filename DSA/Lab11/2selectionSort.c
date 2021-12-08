#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *A, int n)
{
    int indexOfMin;
    for(int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for(int j = i + 1; j < n; j++)   
        {
            if(A[j] < A[indexOfMin])   
                indexOfMin = j;
        }
        swap(&A[i], &A[indexOfMin]);       
       
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
    printf("Before Sorting: ");
    printArray(A, n);
    selectionSort(A, n);
    printf("After Sorting: ");
    printArray(A, n);
    
    return 0;
}