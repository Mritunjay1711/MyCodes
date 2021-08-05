#include<stdio.h>

int main()
{
    char *sub[]= {"DSA", "probability", "math"};
    //sub + 1 = address of 2nd array
    // *(sub + 1) will give probability
    printf("%s\n", *(sub) + 1); //SA
    printf("%s\n", *(sub + 1) + 4); //ability
    return 0;
}