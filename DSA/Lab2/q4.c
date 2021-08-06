#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int *arr, n, sum = 0;
    double *deviation, *sqrDeviation;
    float mean;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    deviation = (double *)malloc(n * sizeof(double));
    sqrDeviation = (double *)malloc(n * sizeof(double));

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
        *(deviation + i) = *(arr + i) - mean;
        *(sqrDeviation + i) = pow(*(deviation + i), 2);
        sqrSum += *(sqrDeviation + i);
    }
    double standardDeviation = sqrSum/n;
    standardDeviation = sqrt(standardDeviation);
    printf("Standard Deviation = %.2lf\n", standardDeviation);

    free(arr);
    free(deviation);
    free(sqrDeviation);
    return 0;
}