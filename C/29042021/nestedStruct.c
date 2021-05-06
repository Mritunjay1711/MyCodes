#include<stdio.h>

struct address{
    char phone[15];
    char city[20];
    int pin;
};

struct emp{
    char name[25];
    struct address adr;
};

int main()
{
    struct emp e;

    printf("Enter the name:");
    scanf("%s", e.name);
    printf("Phone: ");
    scanf("%s", e.adr.phone);
    printf("City: ");
    scanf("%s", e.adr.city);
    printf("Pin: ");
    scanf("%d", &e.adr.pin);

    printf("%s %s\n%s %d\n", e.name, e.adr.phone, e.adr.city, e.adr.pin);
    return 0;
}