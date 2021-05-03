#include<stdio.h>

void func(int *a, int *b, int *c,int *d)
{
    static int i=0;
    i++;
    int ar[3]={*a,*b,*c},smallest=ar[0], greatest=0;
    if(i <= 1)
    {
        for(int i = 0; i < 3; i++)
        {
           if(ar[i] > greatest)
           greatest=ar[i];
        }
        *d = greatest;
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            if(ar[i] < smallest)
            smallest = ar[i];
        }
        *d = smallest;
    }   
}

int main()
{
    int a = 100, b = 12, c = 14, ans = 0;
    func(&a, &b, &c, &ans);
    printf("%d\n",ans);

    func(&a, &b, &c, &ans);
    printf("%d\n",ans);

    return 0;
}