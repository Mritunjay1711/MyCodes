#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, *ptr, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
        sum += ptr[i];
    }

    printf("%d\n", sum);

    free(ptr);
    return 0;
}