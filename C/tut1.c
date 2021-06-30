#include<stdio.h>

 int saveThePrisoner(int n, int m, int s) {
    if(m > n)
        m %= n;
    int ans = (s + m - 1);
    if(ans > n)
        return ans - n;
    else 
        return ans;
}

int main()
{
    int arr[100], n, m, s;
    int x;
    scanf("%d", &x);
    for(int i = 0; i < x; i++)
    {
        scanf("%d %d %d", &n, &m, &s);
        arr[i] = saveThePrisoner(n, m, s);
    }
    for(int i = 0; i < x; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}