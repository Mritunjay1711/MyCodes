#include<stdio.h>
#include<string.h>

struct book{
    char name[20];
    float price;
    int pages;
};

int main()
{
    float highestPrice = 0;
    int index;
    char c[20];
    struct book b[5];

    for(int i = 0; i < 5; i++)
    {
            scanf("%s %f %d",b[i].name, &b[i].price, &b[i].pages);

            if(b[i].price > highestPrice)
            {
                highestPrice = b[i].price;
                index = i;
                strcpy(c, b[i].name);
            }
    }

    printf("The highest price is of %s book and price is %f and is at index %d.", c, highestPrice, index);
    
    return 0;
}