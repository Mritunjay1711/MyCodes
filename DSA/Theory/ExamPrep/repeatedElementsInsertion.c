//4 4 4 4 3 3 3 5 5 5 5 5
// insert any element that many time after one series

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int arr[MAX], count;

void insert(int val, int p)
{
    int exactP, i = p, flag = 0;

    while(arr[i - 1] == arr[i] && i > 0)
    {
        i--;
        flag = 1;
    }

    if(flag)
        exactP = i + arr[i];
    else
        exactP = i;

    for(int j = count - 1; j >= exactP; j--)
    {
        arr[j + val] = arr[j];
    }

    for(i = 0; i < val; i++)
    {
        arr[exactP + i] = val;
    }
    count += val;
}

int main()
{
    int val, p;
    scanf("Enter the number of elements: ");
    scanf("%d", &count);
    for(int i = 0; i < count; i++)
    {
        scanf("%d", &arr[i]);
    }
    insert(5, 14);
    for(int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}