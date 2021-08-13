#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *arr, n, x, y;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    printf("Enter two numbers to find distance: ");
    scanf("%d%d", &x, &y);
    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int dis = n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i] == x && arr[j] == y)
            {
                if((i - j) < dis && (i - j) > 0)
                {
                    dis = i - j;
                }
            }
        }
    }
    printf("%d\n", dis);
    return 0;
}