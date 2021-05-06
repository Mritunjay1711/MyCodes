#include<stdio.h>

struct book
{
    char name[25];
    char author[25];
    int cost;
};

void display(struct book *b)
{
    printf("%s %s %d", b->name, b->author, b->cost);
}

void scan(struct book *b)
{
    scanf("%s %s %d", b->author, b->name, &b->cost);
}

int main()
{
    struct book b;
    struct book *ptr;
    ptr = &b;

    printf("Enter the name of Book, Author and Price respectively: ");
    scan(ptr);
    printf("The name of Book, Author and Price are ");
    display(ptr);

    return 0;
}
