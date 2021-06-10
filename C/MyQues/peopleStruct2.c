#include <stdio.h>
#include <string.h>
struct people
{
    char name[20];
    int age;
    char sex[1];
    char DOB[10];
} p[20];

void input(int n)
{
    printf("\nPerson %d\n", n + 1);
    printf("Enter name: ");
    scanf("%s", &p[n].name);
    printf("Enter age: ");
    scanf("%d", &p[n].age);
    printf("Enter sex[M/F/O]: ");
    scanf("%s", &p[n].sex);
    printf("Enter DOB in the format DD/MM/YY: ");
    scanf("%s", &p[n].DOB);
}
int main()
{
    int i, j = 1;
    for (i = 0; i < 7; i++)
        input(i);

    int a = (901 % 10) + 10;
    printf("\n");
    printf("\n\nSl no.\tName\tAge\tDOB (DD/MM/YY)\n");
    for (i = 0; i < 7; i++)
    {
        if (p[i].age > a)
        {
            printf("%d\t%s\t%d\t%s\t%s\n", j, p[i].name, p[i].age, p[i].sex, p[i].DOB);
            j++;
        }
    }

    return 0;
}