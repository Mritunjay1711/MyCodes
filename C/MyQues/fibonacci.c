#include<stdio.h>

int mr_sumof(int *mr_a, int mr_len)
{
    int mr_sum = 0;
    for(int i = 0; i < mr_len; i++)
    {
        mr_sum += *(mr_a + i);
    }
    return mr_sum;
}

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
    int mr_m = 7, mr_n = 16, mr_fibArr[100], mr_len = mr_n - mr_m + 1, mr_j = 0, mr_sum = 0;

    // int mr_m = 1, mr_n = 10;
    for(int i = mr_m; i <= mr_n; i++)
    {
        mr_fibArr[mr_j] = mr_fibonacci(i);
        mr_j++;
    }
    
    for(int i = 0; i < mr_j; i++)
    {
        printf("%d ", mr_fibArr[i]);
    }
    printf("\n");

    mr_sum = mr_sumof(mr_fibArr, mr_len);
    printf("The sum of fibonacci numbers are %d\n",mr_sum);
    return 0;
}