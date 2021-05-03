#include<stdio.h>

struct book 
{
    char name[20];
    float price;
    int pages;
};

void print(struct book n)
{
    printf("%s %.2f %d",n.name, n.price, n.pages);
}

int main()
{
    struct book b1 = {"Maths", 2340.34, 3234};
    print(b1);
    return 0;
}