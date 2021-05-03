#include<stdio.h>

int main()
{
    int a=2005,b=2008,c=2006;

    for(a=2005;a<3000;a+=13)
    {
        for(b=2008;b<3000;b+=11)
        {
            for( c=2006;c<3000;c+=7)
            {
                if(a==b && b==c)
                {
                    printf("%d\n",a);
                    break;
                }
            }
        }
    }
    int e=2811;
    while(e>17)
    {
        e-=17;
    }
    printf("%d",e);
    return 0;
}