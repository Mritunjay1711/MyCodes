#include<stdio.h>

int main()
{
    FILE *fp;
    int ch = 0, sp = 0, tab = 0, enter = 0;
    char cha;
    fp = fopen("fileRead.c","r");

    while((cha = fgetc(fp)) != EOF)
    {
        ch++;
        if(cha == ' ')
        sp++;
        if(cha == '\n')
        enter++;
        if(cha == '\t')
        tab++;
    }
    fclose(fp);
    printf("The number of characters are %d\n",ch);
    printf("The number of spaces are %d\n",sp);
    printf("The number of newlines are %d\n",enter);
    printf("The number of Tab are %d\n",tab);
    return 0;
}