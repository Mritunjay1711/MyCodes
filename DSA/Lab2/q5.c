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

    for(int i = 0; i < n; i = i + 2)
    {
        if(*(arr + i + 1) % 2 != 1)
        {
            int j = i + 2;
            while (*(arr + j) % 2 != 1)
            {
                if(j >= n)
                    break;
                j++;
            }
            swap((arr + i + 1), (arr + j));
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);
    return 0;
}