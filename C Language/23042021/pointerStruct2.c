#include<stdio.h>

struct book
{
    char name[20];
    float price;
    int pages;
};

int main()
{
    struct book b[5];
    struct book *ptr;
    ptr = b;

    for(int i = 0; i < 5; i++)
    {
        printf("Enter the name, price and pages of book:");
        scanf("%s %f %d", ptr[i].name, &ptr[i].price, &ptr[i].pages);
    }

    
    for(int i = 0; i < 5; i++)
    {
        printf("The name, price and pages of b[%d] is %s %.2f %d.\n", i, ptr[i].name, ptr[i].price, ptr[i].pages);
    }
    return 0;
}