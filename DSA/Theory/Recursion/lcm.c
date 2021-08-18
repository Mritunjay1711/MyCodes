#include<stdio.h>
#include<stdlib.h>

int lcm(int n1, int n2)
{
    static int common = 1;
    if(common % n1 == 0 && common % n2 == 0)
    {
        return common;
    }
    common++;
    lcm(n1, n2);
    return common;
}

int main()
{
    int n1, n2;
    printf("Enter the numbers to find gcd: ");
    scanf("%d%d", &n1, &n2);
    printf("The lcm of %d and %d is %d.", n1, n2, lcm(n1, n2));   
    return 0;
}