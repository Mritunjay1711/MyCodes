#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    int i = 0;
    char ch;
    fp = fopen("input.txt", "r");
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
        i++;
    }
    
}