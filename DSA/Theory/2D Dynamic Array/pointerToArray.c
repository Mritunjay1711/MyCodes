// q[i][j] = *(q + i)[j] = *(*(q + i) + j)
// q[5]
// *q = q[0]
// q[1] = *(q + 1) 
// &q[i] = (q + i)
#include<stdio.h>
#include<stdlib.h>


int main()
{
    int (*q)[5];
    int n;
    printf("Enter the no of rows: ");
    scanf("%d", &n);
    q = (int(*)[5])malloc(n * 5 * sizeof(int));
    // &q[i][j]
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            scanf("%d", (*(q + i) + j));
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d ", *(*(q + i) + j));
        }
        printf("\n");
    }
    return 0;
}