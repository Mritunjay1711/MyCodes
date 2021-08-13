#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int *arr, n, sum = 0;
    double sumSqr, stdDeviation;
    float mean;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    

    for(int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", (arr + i));
        sum += *(arr + i);
    }
    mean = (float)sum/n;
    double sqrSum = 0;

    for(int i = 0; i < n; i++)
    {
        sqrSum += pow((arr[i] - mean), 2);
    }
    stdDeviation = sqrt((sqrSum/n));
    printf("Standard Deviation = %.2lf\n", stdDeviation);

    free(arr);
    return 0;
}