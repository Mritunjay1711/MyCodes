#include<stdio.h>
#include<stdlib.h>

void sort(int *arr, int n)
{
    int temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int *arr, n, k;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("%dth smallest value is %d\n%dth largest value is %d\n", k, arr[k - 1], k, arr[n - k]);
    return 0;
}