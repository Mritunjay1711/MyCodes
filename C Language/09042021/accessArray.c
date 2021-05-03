#include<stdio.h>

int main()
{
    char *p[5];
    char a[]="Yudhistir",b[]="Bhim",c[]="Arjun",d[]="Nakul",e[]="Sahadev";
    p[0]=a,p[1]=b,p[2]=c,p[3]=d,p[4]=e;

    for(int i=0;i<5;i++)
    {
        printf("%s\n",p[i]);
    }
    printf("%c\n",*(p[0]+1));
    printf("%p",p[0]);
    return 0;
}