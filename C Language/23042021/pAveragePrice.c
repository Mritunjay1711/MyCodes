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
        printf("\nEnter the Name, Price and Pages of book b[%d]:",i);
        scanf("%s %f %d", (ptr+i)->name, &(ptr+i)->price, &(ptr+i)->pages);
    }

    static float avg, sum;
    
    for(int i = 0; i < 5; i++)
    {
        sum += (ptr+i)->price;
    }
    avg = sum/5.0;

    printf("The average price of books is %.2f.", avg);
    return 0;
}