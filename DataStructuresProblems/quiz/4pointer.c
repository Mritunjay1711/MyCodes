#include<stdio.h>
#include<stdlib.h>


int main()
{
    static int a[] = {90, 98, 99, 96, 84, 70};
    static int *p[] = {a + 2, a + 1, a, a + 3, a + 4, a + 5};
    static int **s[] = {p + 4, p + 5, p + 1, p, p + 2, p + 3};
    int ***ptr;
    ptr = s + 2;
    printf("%d ", ***(ptr + 3) - **(p + 1));
    return 0;
}