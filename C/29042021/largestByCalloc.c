#include<stdio.h>
#include<stdlib.h>

int main()
{
    int largest = 0, n;
    float *data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    data = (float*)calloc(n,sizeof(float));

    printf("Enter the elements: ");
    for(int i = 1; i <= n; i++)
    {
        scanf("%f", &data[i]);
        if(data[i] > largest)
        largest = data[i];
    }
    data[0] = largest;
    printf("%.2f",*(data));
    free(data);
    return 0;
}