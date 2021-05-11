#include<stdio.h>
#include<string.h>

int main()
{
    char name[20], name2[20];
    int i;
    gets(name);
    for(i = 0; name[i] != '\0'; i++)
    {
        name2[i] = name[i];
        if(name[i] == ' ')
        {
            name2[i] = 'y';
        }
        
    }
    name2[i] = '\0';

    printf("%s",name2);
    return 0;
}