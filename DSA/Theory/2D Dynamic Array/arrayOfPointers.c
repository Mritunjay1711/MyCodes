#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *q[5];
    int c;
    printf("Enter the no of columns in each row: ");
    scanf("%d", &c);

    for(int i = 0; i < 5; i++)
    {
        q[i] = (int *)malloc(c * sizeof(int));
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", (*(q + i) + j));
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", *(*(q + i) + j));
        }
        printf("\n");
    }
    return 0;
}

// 0--> 1 2 3 4 5
// 1--> 3 54 56 7
// 2--> 2 3 54 6 7
// 3
// 4