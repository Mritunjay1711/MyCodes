#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char num[20],len;
    int a[20];
    gets(num);
    len = strlen(num);
    // for(int i = 0; i < len; i++)
    // {
    //     a[i] = atoi(num[i]);
    // }
    int c = atoi(num);
    // for(int i = 0; i < len; i++)
    // {
    //     printf("%d",a[i]);
    // }
    printf("%d",c);
    return 0;
}