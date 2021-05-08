#include<stdio.h>
#include<string.h>

struct employee{
    char name[10];
    int age;
    float salary; 
};

int main()
{
    struct employee e2;
    struct employee e1 = {"Rajesh", 23, 100};

    e2.salary = e1.salary;
    e2.age = e1.age;
    strcpy(e2.name, e1.name);

    printf("%s %d %.2f\n", e2.name, e2.age, e2.salary);

    return 0;
}