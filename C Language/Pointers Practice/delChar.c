#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void delete(char* s , char ch)
{
    int len = 0;
    int i = 0;
    while (s[i])
    {
        len++;
        i++;
    }


    for (int i = 0; i < len; i++)
    {
        if ((s[i] == ch) || (s[i] == ch-32))
        {
            for (int j = i; j <= len; j++)
            {
                s[j] = s[j+1];
            }
        }
        if ((s[i+1] == ch) && (s[i] == ch) || (s[i+1] == ch-32) && (s[i] == ch-32))
        {
            i-= 1;
        }
        
    }
}
            
        
    
    

    

int main()
{
    char str[100];
    char ch;
    scanf("%s",str);
    scanf("%c",&ch);
    printf("Enter the character :\t");
    scanf("%c",&ch);
    delete(str , ch);
    printf("Modified string : %s",str);
    return 0;
}