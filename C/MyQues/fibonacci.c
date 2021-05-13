#include<stdio.h>

int mr_fibonacci(int n)
{
    int mr_n1 = 0, mr_n2 = 1, mr_nextnum = mr_n1 + mr_n2;
    if(n == 1)
    return 0;
    if(n == 2)
    return 1;
    if(n ==3)
    return 1;
    else
    {
        while(n - 3)
        {

            mr_n1 = mr_n2;
            mr_n2 = mr_nextnum;
            mr_nextnum = mr_n1 + mr_n2;
            n--;
        }
    }
      
    return mr_nextnum;
}

int main()
{
    int mr_m = 2006226 % 10 + 1, mr_n = 2006226 % 10 + 10;
    for(int i = mr_m; i <= mr_n; i++)
    {
        printf("%d ", mr_fibonacci(i));
    }
    return 0;
}