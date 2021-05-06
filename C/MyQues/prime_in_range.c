#include<stdio.h>

int mj_prime(int mj_a, int mj_b)
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
        mjcount++;
    }
    return mjcount;
}


int main()
{
    printf("%d\n",mj_prime(2, 10));
    return 0;
}