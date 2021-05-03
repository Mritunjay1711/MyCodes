#include<stdio.h>

int main()
{
    int n, s[100], d, m, i, c=0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
    scanf("%d", &s[i]);
    }
    scanf("%d", &d);
    scanf("%d", &m);
        switch(m)
        {
            case 1:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]==d)
                c++;
                }
                break;
            }
            case 2:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]==d)
                c++;
                }
                break;
            }
            case 3:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]==d)
                c++;
                }
                break;
            }
            case 4:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]+s[i+3]==d)
                c++;
                }
                break;
            }
            case 5:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]==d)
                c++;
                }
                break;
            }
            case 6:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]+s[i+5]==d)
                c++;
                }
                break;
            }
            case 7:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]+s[i+5]+s[i+6]==d)
                c++;
                }
                break;
            }
            case 8:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]+s[i+5]+s[i+6]+s[i+7]==d)
                c++;
                }
                break;
            }
            case 9:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]+s[i+5]+s[i+6]+s[i+7]+s[i+8]==d)
                c++;
                }
                break;
            }
            case 10:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]+s[i+5]+s[i+6]+s[i+7]+s[i+8]+s[i+9]==d)
                c++;
                }
                break;
            }
            case 11:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]+s[i+5]+s[i+6]+s[i+7]+s[i+8]+s[i+9]+s[i+10]==d)
                c++;
                }
                break;
            }
            case 12:
            {   
                for(i=0;i<n;i++)
                {
                if(s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]+s[i+5]+s[i+6]+s[i+7]+s[i+8]+s[i+9]+s[i+10]+s[i+11]==d)
                c++;
                }
                break;
            }
        }
    printf("%d", c);
    return 0;
}