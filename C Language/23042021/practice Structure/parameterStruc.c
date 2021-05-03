#include<stdio.h>

struct grocery
{
    char name[20];
    float price;
    int items;
};

struct grocery update(struct grocery product, float n, int a)
{
    product.price += n;
    product.items += a;
    return(product);
}

void print(struct grocery product)
{
    printf("%s %.2f %d\n", product.name, product.price, product.items);
}

int main()
{
    struct grocery g1 ={"Paneer", 89.33, 3}, g2 = {"Chicken", 140.25, 3};

    print(g1);
    print(g2);
    print(update(g1, 10.00, 2));
    print(update(g2, 30.00, 5));
    return 0;
}

