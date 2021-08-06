#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *arr, n, sum = 0;
    float avg;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        printf("Enter the number %d: ", i + 1);
        scanf("%d", (arr + i));
        sum += *(arr + i);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    avg = (float)sum/n;
    printf("\nThe average of the numbers are %.2f\n", avg);

    free(arr);
    return 0;
}