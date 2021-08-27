#include<stdio.h>
#include<stdlib.h>

int **allocate(int r, int c)
{
    int **p = (int **)malloc(r * sizeof(int *));//*p[r]
    for(int i = 0; i < r; i++)
    {
        p[i] = (int *)malloc(c * sizeof(int));
    }
    return p;
}

void input(int **s, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &s[i][j]);
        }
    }
}

void print(int **s, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **s;
    int r, c;
    printf("Enter the number of rows and columns respectively: ");
    scanf("%d%d", &r, &c);
    
    s = allocate(r, c);
    input(s, r, c);
    print(s, r, c);
    return 0;
}