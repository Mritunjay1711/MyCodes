#include <stdio.h>

int main()
{
    int a[] = {100, 120, 350, 240, 500, 760};
    int *ptr1 = a;
    int *ptr2 = a + 4;
    printf("Number of elements between two pointer are: %d.\n", (ptr2 - ptr1));
    printf("Number of bytes between two pointers are: %d\n", (char *)ptr2 - (char *)ptr1);
}