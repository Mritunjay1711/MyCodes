#include<stdio.h>
#include<stdlib.h>


int a1[] = {6, 2, 8, 18, 34, 67};
int a2[] = {23, 56, 28, 29};
int a3[] = {-12, 27, -31};
int *x[] = {a1, a2, a3};

void print(int *a[])
{
    printf("%d\n", a[0][2]);
    printf("%d\n", *a[2]);
    printf("%d\n", *++a[0]);
    printf("%d\n", *(++a)[0]);
    printf("%d\n", a[-1][+1]);
}

void main()
{
    print(x);
}