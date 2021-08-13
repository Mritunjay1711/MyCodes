#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *arr, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        int greater = 0;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] > greater)
                greater = arr[j];
        }
        arr[i] = greater;
    }
    arr[n - 1] = 0;

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}