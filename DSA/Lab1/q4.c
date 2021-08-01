#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n, *arr, sum = 0;
    
    printf("Enter the number of elements:");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));

    
    for(int i = 0; i < n; i++)
    {
        printf("Enter the number %d: ", i+1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nSum: %d", sum);

    free(arr);
    return 0;
}