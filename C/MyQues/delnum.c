#include<stdio.h>

int main()
{
    int n, n2, new_num = 0, len, len2 = 0, a[20], b[20];
    printf("Enter the number: ");
    scanf("%d",&n);
    n2 = n;
    while(n2)
    {
        n2 /= 10;
        len++;
    }
    
    for(int i = len - 1; i >= 0; i--)
    {
        int temp = n % 10;
        b[i] = temp;
        n /= 10;
    }

    for(int i = 0; i < len; i++)
    {
        if(b[i] != 0)
        {
            a[len2] = b[i];
            len2++;
        }
    }
    
    for(int i = 0; i < len2; i++)
    {
        new_num = new_num * 10 + a[i];
    }

    printf("The new num is %d.\n", new_num);
    return 0;
}