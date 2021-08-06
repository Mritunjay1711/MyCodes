#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, *arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", (arr + i));
    }

    for(int i = 0; i < n/2; i++)
    {
        swap((arr + i), (arr + n - i - 1));
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);
    return 0;
}