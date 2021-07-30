#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n, *arr;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i = i + 2)
    {
        if(arr[i + 1] % 2 == 0)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}