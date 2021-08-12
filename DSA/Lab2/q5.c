#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, *arr, count = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", (arr + i));
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
            count++;
    }

    for(int i = 0; i < count; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] % 2 == 0)
                swap(&arr[i], &arr[j]); 
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);
    return 0;
}