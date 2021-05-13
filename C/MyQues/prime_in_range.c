#include<stdio.h>

void prime(int *a, int *b, int *ans,int *count)
{
    int k = 0;
    for(int i = *a; i <= *b; i++)
    {
         int flag = 1;
        for(int j = 2; j < i; j++)
        {
           
            if(i % j == 0)
            {
                flag = 0;
                break;
            }

        }
        if(flag == 1)
        {
            *(ans + k) = i;
            k++;
        }
        
    }
    *count = k;
    
}


int main()
{
    int n1, n2, ans[1000],count = 0;
    
    printf("Enter the number in between you want the prime: ");
    scanf("%d %d", &n1, &n2);
    prime(&n1, &n2, ans, &count);
    for(int i = 0; i < count; i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\nThere are %d prime number.",count);
    return 0;
}