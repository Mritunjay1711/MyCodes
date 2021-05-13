#include<stdio.h>
#include<string.h>

int main()
{
    char mr_name[50], mr_nameCopy[150], mr_lch;
    int mr_sp = 2006226 % 10 + 1,k = 0;
    printf("Enter the name: ");
    gets(mr_name);

    for(int i = 0; mr_name[i] != '\0'; i++)
    {
        mr_lch = mr_name[i] - 32;
    }

    // printf("%c\n",mr_lch);

    for(int i = 0; mr_name[i] != '\0'; i++)
    {
        if(mr_name[i] != ' ')
        {
            mr_nameCopy[k] = mr_name[i]; 
            k++;
        }
       
        if(mr_name[i] == 'a' || mr_name[i] == 'A' || mr_name[i] == 'e' || mr_name[i] == 'E' || mr_name[i] == 'i' || mr_name[i] == 'I' || mr_name[i] == 'o' || mr_name[i] == 'O' || mr_name[i] == 'u' || mr_name[i] == 'U')
        {
            for(int j = 0; j < mr_sp; j++)
            {
                mr_nameCopy[k] = ' ';
                k++;
            }
        }
        if(mr_name[i] == ' ')
        {
            mr_nameCopy[k] = mr_lch;
            k++;
        }
    }
    mr_nameCopy[k] = '\0';
    printf("%s\n",mr_nameCopy);
    return 0;
}