#include<stdio.h>
#include<stdlib.h>

void vowelFreq(char *str)
{
    int b=0,a=0,e=0,i=0,o=0,u=0;

    while (str[b])
    {
        if(str[b]=='a' || str[b]=='A')
        a++;
        else if (str[b]=='e' || str[b]=='E')
        e++;
        else if(str[b]=='i' || str[b]=='I')
        i++;
        else if(str[b]=='o' || str[b]=='O')
        o++;
        else if(str[b]=='u' || str[b]=='U')
        u++;

        b++;
        
    }
        printf("a is %d times.\n",a);
        printf("e is %d times.\n",e);
        printf("i is %d times.\n",i);
        printf("o is %d times.\n",o);
        printf("u is %d times.\n",u);
}

int main()
{
    char str[100];
    int i=0;

    printf("Enter the string:");
    gets(str);

    vowelFreq(str);

    return 0;
}