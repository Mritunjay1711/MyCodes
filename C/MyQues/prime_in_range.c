#include<stdio.h>

void mj_prime(int mj_a, int mj_b)
{
    int mjcount = 0;
    for(int i = mj_a; i <= mj_b; i++)
    {
         int flag = 1;
        for(int j = 2; j < i; j++)
        {
           
            if(i % j == 0)
            {
                flag = 0;
                break;
            }

        }
        if(flag == 1)
        printf("%d ", i);
    }
    printf("\n");
    
}


int main()
{
    char c = 'm';
    int a = c;
    mj_prime(a - 30, a + 20);
    return 0;
}