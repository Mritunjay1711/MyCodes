#include<stdio.h>
#include<stdlib.h>

void fun(int k)
{
    if(k == 0) return;
    printf("%d ", k);
    fun(k - 1);
    printf("%d ", k);
}

int main()
{
    fun(3);
    return 0;
}