#include<stdio.h>
#include<stdlib.h>

void copyString(char *src,char *dst)
{
    int i=0;
    while (src[i])
    {
        dst[i]=src[i];
        i++;
    }
    dst[i]='\0';
    
}

int main()
{
    char src[100],dst[100];

    printf("Enter the string:");
    scanf("%s",src);

    copyString(src,dst);
    printf("\nCopied string: %s",dst);
    return 0;
}