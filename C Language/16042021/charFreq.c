#include<stdio.h>
#include<stdlib.h>

int freqChar(char *str,char ch)
{
    int i=0,count=0;

    while (str[i])
    {
        if(str[i]==ch)
        count++;

        ++i;
    }
    return count;
}

int main()
{
    char str[100],ch;
    int i=0;

    printf("Enter the string:");
    gets(str);
    scanf("%c",&ch);
    printf("Enter the charcter to find frequency:");
    scanf("%c",&ch);

    i=freqChar(str,ch);
    
    if(i)
    printf("%c is %d times in the string\n",ch,i);
    else
    printf("%c not found!");

    return 0;
}