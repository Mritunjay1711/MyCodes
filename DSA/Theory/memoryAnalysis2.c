#include<stdio.h>
#include<stdlib.h>

// In pointer arithmetic it will give us the number of elements between those two location
// ptr - p
int main()
{
    static int a[] = {40, 10, 20, 30, 50};
    static int *p[] = {a, a + 3, a + 4, a + 1, a + 2};
    int **ptr = p;
    ptr++;
    printf("%d %d\n", (ptr - p), **ptr);
    return 0;
}