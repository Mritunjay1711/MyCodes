#include<stdio.h>

int main()
{
    char *sub[]= {"DSA", "probability", "math"};
    printf("%s\n", *(sub) + 1);
    printf("%s\n", *(sub + 1) + 4);
    return 0;
}