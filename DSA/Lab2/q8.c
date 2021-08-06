#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n, a;
    printf("Enter the number of array: ");
    scanf("%d", &a);
    printf("Enter the number of elements in each array: ");
    scanf("%d", &n);

    int *arr[a];
    for(int i = 0; i < a; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for(int i = 0; i < a; i++)
    {
        printf("Enter the elements of array %d\n", i + 1);
        for(int j = 0; j < n; j++)
        {
            printf("Enter the element %d: ", j + 1);
            scanf("%d", (*(arr + i) + j));
        }
    }

    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    return 0;
}