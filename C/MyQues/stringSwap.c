#include<stdio.h>
#include<string.h>

int main()
{
    char str[40];
    int indices[30], k = 1;
    gets(str);
    indices[0] = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' && str[i + 1] != ' ')
        {
            indices[k] = i + 1;
            k++;
        }
    }
    
    
    for(int i = 0; i < k; i += 2)
    {
        for(int j = 0; j < 2; j++)
        {
            char temp = str[indices[i] + j];
            str[indices[i] + j] = str[indices[i+1] + 2 + j];
            str[indices[i + 1] + 2 + j] = temp;
        }
        
        for(int j = 0; j < 2; j++)
        {
            char temp  = str[indices[i] + j + 2];
            str[indices[i] + j + 2] = str[indices[i + 1] + j];
            str[indices[i + 1] + j] = temp;
        }
    }
    printf("%s\n",str);
    return 0;
}