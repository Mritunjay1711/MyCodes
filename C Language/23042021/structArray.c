#include<stdio.h>

struct book{
    char name[20];
    float price;
    int pages;
};

int main()
{
    struct book b[5];

    for(int i = 0; i < 5; i++)
    {
        printf("\nEnter the name, price and pages of book b[%d]:",i);
        scanf("%s %f %d",b[i].name, &b[i].price, &b[i].pages);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("\nThe name, price and pages of book b[%d] are: %s %.2f %d", i, b[i].name, b[i].price, b[i].pages);
    }
    return 0;
}