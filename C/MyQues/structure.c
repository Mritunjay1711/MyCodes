#include<stdio.h>

struct number{
    int old_num;
    int new_num;
    int old_arr[20];
    int new_arr[20];
};

int k = 1;
struct number *function(struct number *n)
{
     int i = 0, n2 = n->old_num;
    while(n2)
    {
        n2 /= 10;
        i++;
    }
    n2 = n->old_num;
    for(int j = i - 1; j >= 0; j--)
    {
        int temp = n2 % 10;
        n->old_arr[j] = temp;
        n2 /= 10;
    }

    // for(int j = 0; j < i; j++)
    // {
    //     printf("%d",n->old_arr[j]);
    // }
    // printf("\n");
    n->new_arr[0] = n->old_arr[0];
    for(int j = 0; j < i - 1; j++)
    {
        int prev = n->old_arr[j], next = n->old_arr[j + 2], cur = n->old_arr[j + 1];
        if((prev + next != cur) && (next - prev != cur) && (prev - next != cur) && (next / prev != cur) && (prev / next != cur) && (next * prev != cur) && (next % prev != cur) && (prev % next != cur))
        {
            n->new_arr[k] = n->old_arr[j + 1];
            k++;
        }
    }
    n->new_arr[k] = n->old_arr[i];
    n->new_num = 0;
    for(int l = 0; l < k; l++)
    {
        n->new_num = n->new_num * 10 + n->new_arr[l]; 
    }
    return n;
}

int main()
{
    struct number n, *p;
    p = &n;
    int len,n2;
    printf("Enter the num: ");
    scanf("%d", &n.old_num);
    function(p);
    for(int l = 0; l < k; l++)
    {
        printf("%d ", n.new_arr[l]);
    }
    printf("\n%d", n.new_num);
    return 0;
}