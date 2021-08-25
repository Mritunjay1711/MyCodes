#include<stdio.h>

void increase()
{
    static int a = 20;
    static int b = 37;
    printf("%d %d\n", a, b);
    a++;
    b++;
}

int main()
{
    int x; 
    for(x = 0; x < 3; x++)
    {
        increase();
    }
    
    return 0;
}