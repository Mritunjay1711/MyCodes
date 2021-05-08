#include<stdio.h>

struct book
{
    char name[20];
    float price;
    int pages;
};

int main()
{
    struct book b1;
    struct book *ptr;
    ptr = &b1;

    printf("Enter the name, price and pages of the book b1:");
    scanf("%s %f %d", ptr->name, &ptr->price, &ptr->pages);
    printf("The input given by you was: %s %.2f %d.\n", ptr->name, ptr->price, ptr->pages);
    return 0;
}