#include<stdio.h>

int main()
{
    int a, b, c, d, f, y, n, ans;

    scanf("%d %d %d", &a, &b, &n);

    y = n/2;
    f = n - y;

    // In case there is no increment
    c = a;
    d = b;


    while(f)
    {
        c = a * 2;
        f--;
    }

    while(y)
    {
        d = b * 2;
        y--;
    }
    
    if(c > d)
        ans = c/d;
    else
        ans = d/c;

    printf("%d\n", ans);

    return 0;
}