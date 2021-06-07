#include<stdio.h>

int main()
{
    int a, b, c, d, n, ans;

    scanf("%d %d %d", &a, &b, &n);

    for(int i = 1; i <= n; i++)
    {
        if(i % 2)
            a *= 2;
        else
            b *= 2;
    }
    c = a;
    d = b;
    
    ans = (c/d) ? (c/d) : (d/c);

    printf("%d\n", ans);

    return 0;
}