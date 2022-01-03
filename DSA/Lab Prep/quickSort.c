#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    static int count = 0;

    do{
        count++;
        while(A[i] <= pivot)
        {
            i++;
        }

        count++;
        while(A[j] > pivot)
        {
            j--;
        }
        count++;
        if(i < j)
            swap(&A[i], &A[j]);
        count++;
    }while(i < j);
    swap(&A[j], &A[low]);
    printf("%d\n", count);
    return j;
}

void quickSort(int *A, int low, int high)
{
    int partitionIndex;   
    if(low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1); 
        quickSort(A, partitionIndex + 1, high); 
    }
}

int main()
{
    int n, *A, low, high;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    A = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        printf("Enter the element A[%d]: ", i);
        scanf("%d", &A[i]);
    }
    low = 0;
    high = n - 1;

    printf("Before sorting: ");
    printArray(A, n);
    quickSort(A, low, high);
    printf("After sorting: ");
    printArray(A, n);
    
    return 0;
}