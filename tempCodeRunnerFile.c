#include <stdio.h>
#include <math.h>

int main()
{
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    int num[n];
    double std = 0.0, mean, sum = 0.0;

    printf("Enter n elements: \n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%f", &num[i]);
        sum += num[i];
    }

    mean = (double)sum / n;
    for (int i = 0; i < n; ++i)
    {
        sum += pow((num[i] - mean), 2);
        
    }
    std= sqrt((sum) / n);
    printf("\nStandard Deviation = %.2f", std);

    return 0;
}