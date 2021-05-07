#include<stdio.h>

int sumdigit(int n)
{
    int num = 0, sum = 0;
    
    while(n)
    {
        num = n % 10;
        sum = sum + num;
        n /= 10;
    }

    return sum;
}

struct book{
    char name[10];
    int price;
    int pages;
};

int sumofdigits(struct book *b)
{
    int sum = 0;
    sum = sumdigit(b->pages) + sumdigit(b->price);
    return sum;
}

int main()
{
    struct book b;
    struct book *ptr;
    int sum;

    ptr = &b;
    scanf("%s %d %d",ptr->name, &ptr->price, &ptr->pages);
    sum = sumofdigits(ptr);
    printf("%d\n",sum);
    return 0;
}