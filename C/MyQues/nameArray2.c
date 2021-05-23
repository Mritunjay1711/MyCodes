#include<stdio.h>
#include<string.h>

int main()
{
    char mr_name[100], mr_nameCopy[150], mr_fch;
    int mr_vow = 0, mr_k = 0, mr_sp = 6;

    printf("Enter the name: ");
    gets(mr_name);
    mr_fch = mr_name[0];

    for(int i = 0; mr_name[i] != '\0'; i++)
    {
        if(mr_name[i] != ' ')
        {
            mr_nameCopy[mr_k] = mr_name[i];
            mr_k++;
            for(int j = 0; j < mr_sp; j++)
            {
                mr_nameCopy[mr_k] = ' ';
                mr_k++;
            }
        }
        else
        {
            mr_nameCopy[mr_k] = mr_fch;
            mr_k++;
        }
        if(mr_name[i] == 'a' || mr_name[i] == 'A' || mr_name[i] == 'e' || mr_name[i] == 'E' || mr_name[i] == 'i' || mr_name[i] == 'I' || mr_name[i] == 'o' || mr_name[i] == 'O' || mr_name[i] == 'u' || mr_name[i] == 'U')
        {
            mr_vow++;
        }
    }
    mr_nameCopy[mr_k] = '\0';
    printf("%s\n",mr_nameCopy);
    printf("There are %d number of vowels in your name.\n",mr_vow);
    
    return 0;
}