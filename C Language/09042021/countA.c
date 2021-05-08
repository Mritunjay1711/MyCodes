#include<stdio.h>

int main()
{
    char *p[5];
    char a[]="Yudhistir",b[]="Bhim",c[]="Arjun",d[]="Nakul",e[]="Sahadev";
    int count=0;
    p[0]=a,p[1]=b,p[2]=c,p[3]=d,p[4]=e;

    for(int i=0;i<5;i++)
    {
        for(int j=0;p[i][j];j++)
        {
            if(p[i][j]=='a' || p[i][j] == 'A')
            count++;
        }
    }
    printf("There are %d 'a' in strings.",count);
    return 0;
}