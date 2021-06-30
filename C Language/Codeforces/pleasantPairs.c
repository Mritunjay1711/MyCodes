#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n,l;
    scanf("%d", &n);
    l = n;
    int arr[10000], arr2[200000];
    // arr = (int*)malloc(n * sizeof(int));
    while(n)
    {
        int temp, k = 0;
        scanf("%d", &temp);
        // arr2 = (int*)malloc(temp * sizeof(int));
        for(int i = 0; i < temp; i++)
        {
            scanf("%d", &arr2[i]);
        }
        for(int i = 0; i < temp; i++)
        {
            for(int j = i + 1; j < temp; j++)
            {
                if((arr2[i] * arr2[j]) == (i + j + 2))
                    k++;
            }
        }
        arr[l - n] = k;
        n--;
        // free(arr2);
    }
    
    for(int i = 0; i < l; i++)
    {
        printf("%d\n", arr[i]);
    }
    // free(arr);
    return 0;
}