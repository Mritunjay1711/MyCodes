#include<stdio.h>

int main()
{
    int ar[3] = {5, 2, 3};
for(int i = 0; i < 3; i++)
{
    if(ar[i] < ar[i+1])
    {
        int temp = ar[i];
        ar[i] = ar[i + 1];
        ar[i + 1] = temp;
    }
}
for(int i = 0; i < 3; i++)
{
    printf("%d ",ar[i]);
}
    return 0;
}