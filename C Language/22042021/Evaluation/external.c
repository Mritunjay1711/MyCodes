#include<stdio.h>

int x=21;

void display()
{
    printf("%d\n",x);
}

void display2()
{
    int x=10;
    printf("%d\n",x);
}
int main()
{
    display();
    display2();
    printf("%d\n",x);
    return 0;
}