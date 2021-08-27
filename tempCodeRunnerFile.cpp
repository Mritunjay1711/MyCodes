#include<iostream>

using namespace std;

void fun(int, int&, int*);

int main()
{
    int a = 10, b = 20, c = 30;
    fun(a, b, &c);
    cout << a << " " << b << " " << c;
    return 0;
}


void fun(int x, int &y, int *z)
{
    x = y;
    y = x;
    *z = y;
}