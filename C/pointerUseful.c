#include<stdio.h>
#include<stdlib.h>


int main()
{
    char *arr[] = {"one", "two", "three", "four", "five", "six", "seven"};
    printf("%s\n", arr[5-1]);
    return 0;
}