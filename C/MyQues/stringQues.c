#include<stdio.h>
#include<string.h>

int main()
{
    char name[20], name2[20], ch;
    int i;
    gets(name);
    ch = name[0];
    for(int i = 0; name[i] != '\0'; i++)
    {
        if(ch < name[i])
        {
            ch = name[i];
        }
    }

    for(i = 0; name[i] != '\0'; i++)
    {
        name2[i] = name[i];
        if(name[i] == ' ')
        {
            name2[i] = ch;
        }
        
    }
    name2[i] = '\0';

    printf("%s",name2);
    return 0;
}