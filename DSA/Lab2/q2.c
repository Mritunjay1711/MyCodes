#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *arr, n, largest = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        printf("Enter the number %d: ", i + 1);
        scanf("%d", (arr + i));
        if(*(arr + i) > largest)
        {
            largest = *(arr + i);
        }
    }

    printf("The largest entered value is %d\n", largest);
    free(arr);
    return 0;
}