#include<stdio.h>

struct book{
    char name[20];
    float price;
    int pages;
};

int main()
{
    struct book b1, b2;

    printf("Enter the names, prices and pages of 2 books:");
    scanf("%s %f %d",b1.name, &b1.price, &b1.pages);
    scanf("%s %f %d",b2.name, &b2.price, &b2.pages);

    printf("The input from the keyboard was: ");
    printf("%s %f %d\n",b1.name, b1.price, b1.pages);
    printf("%s %f %d\n",b2.name, b2.price, b2.pages);

    return 0;
}