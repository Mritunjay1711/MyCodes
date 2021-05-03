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

void concatString(char *str1,char *str2,int n)
{
    int i=0;
    while(str2[i])
    {
        str1[n]=str2[i];
        ++n;
        ++i;
    }
    str1[n]='\0';
}

int main()
{
    char str1[100],str2[100],ch;
    int i=0,n;

    printf("Enter the first string:");
    scanf("%s",str1);
    scanf("%c",&ch);
    printf("Enter the second string:");
    scanf("%s",str2);
    
    n=stringLen(str1);
    concatString(str1,str2,n);

    printf("%s",str1);

    return 0;
}