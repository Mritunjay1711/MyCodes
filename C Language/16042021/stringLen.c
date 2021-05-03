#include<stdio.h>
#include<stdlib.h>

int stringLen(char *str)
{
    int i=0;
    while(str[i])
    {
        ++i;
    }
    return i;
}

int main()
{
    char str[100];
    int i=0;

    printf("Enter the string:");
    scanf("%s",str);

    i=stringLen(str);

    printf("The length of string is %d.",i);

    return 0;
}