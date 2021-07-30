#include<stdio.h>
#include<stdlib.h>

struct Student{
    int roll;
    char name[20];
    float cgpa;
};

int main()
{
    struct Student s;
    printf("Enter roll: ");
    scanf("%d", &s.roll);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter cgpa: ");
    scanf(" %f", &s.cgpa);

    printf("Roll: %d\n Name: %s\n CGPA: %.2f\n", s.roll, s.name, s.cgpa);
    
    return 0;
}