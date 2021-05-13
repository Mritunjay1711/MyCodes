#include<stdio.h>
#include<math.h>

int armstrong(int n)
{
    static int i = 0,len = 0, ans;
    i++;
    if(i <= 1)
    {
        int temp = n;
        while (temp)
        {
            temp /= 10;
            len++;
        }
    }
    if(n > 0)
     ans = (pow(n % 10, len) + armstrong(n / 10));

    return (ans);
    
}

int main()
{
    int num, ans;
    printf("Enter the num: ");
    scanf("%d",&num);

    ans = armstrong(num);
    
    if(num == ans)
        printf("This is an Armstrong number.\n");
    else
        printf("This is not an armstrong number!\n");
    return 0;
}